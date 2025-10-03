import time
import pandas as pd
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.common.keys import Keys

# ================================
# CONFIGURAÇÕES
# ================================

usuario_sac = "mikaell.mesquita@seduc.go.gov.br"
senha_sac = ""
caminho_planilha = r"C:\Users\mikaell.mesquita\Documents\PLANILHA CONTROLE DAS MANUTENÇÕES (3).xlsx"

# ================================
# FUNÇÃO CLEAR
# ================================

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

# ================================
# FUNÇÃO LOGIN
# ================================

def realizar_login(driver, usuario, senha, url_login, max_tentativas=3):
    tentativa = 0
    login_sucesso = False

    while tentativa < max_tentativas and not login_sucesso:
        tentativa += 1
        print(f"Tentativa de login #{tentativa}")

        driver.get(url_login)
        wait = WebDriverWait(driver, 30)

        try:
            botao_seduc = wait.until(EC.element_to_be_clickable(
                (By.XPATH, "//span[contains(text(),'Se você é da SEDUC - Clique')]")
            ))
            botao_seduc.click()
            print("✅ Botão 'Se você é da SEDUC - Clique Aqui' clicado")

            campo_email = wait.until(EC.presence_of_element_located((By.ID, "i0116")))
            campo_email.clear()
            campo_email.send_keys(usuario)
            print("✉️ Email preenchido")

            botao_avancar = wait.until(EC.element_to_be_clickable((By.ID, "idSIButton9")))
            botao_avancar.click()
            time.sleep(2)

            campo_senha = wait.until(EC.presence_of_element_located((By.ID, "i0118")))
            campo_senha.clear()
            campo_senha.send_keys(senha)
            print("🔑 Senha preenchida")

            botao_entrar = wait.until(EC.element_to_be_clickable((By.ID, "idSIButton9")))
            botao_entrar.click()
            print("✅ Botão Entrar clicado")

            # MFA (se existir)
            try:
                botao_outra_maneira = wait.until(
                    EC.element_to_be_clickable((By.ID, "signInAnotherWay"))
                )
                botao_outra_maneira.click()
                botao_sms = wait.until(
                    EC.element_to_be_clickable((By.XPATH, "//div[contains(text(), 'Texto +')]"))
                )
                botao_sms.click()
                input("⏳ Digite o código do SMS no navegador e pressione ENTER aqui...")
            except:
                print("⚠️ MFA não apareceu ou já autenticado.")

            time.sleep(5)
            login_sucesso = True
            print("🎉 Login realizado com sucesso!")
        except Exception as e:
            print(f"⚠️ Erro na tentativa #{tentativa}: {e}")
            time.sleep(3)

    if not login_sucesso:
        raise Exception("🚫 Não foi possível realizar o login após várias tentativas.")

    return True

# ================================
# INICIALIZA WEBDRIVER
# ================================

driver = webdriver.Chrome()
wait = WebDriverWait(driver, 10)

# ================================
# LOGIN
# ================================

url_login = "https://keycloak.4biz.one/auth/realms/seduc-03/protocol/openid-connect/auth?client_id=front-manager&redirect_uri=https%3A%2F%2Fseduc.4biz.one%2Fworkflow%2Fpages%2FserviceRequestIncident%2FserviceRequestIncident.load%3Fiframe%3Dtrue&state=aa36d904-001f-44c1-86ab-7e0528fc7cf5&response_mode=fragment&response_type=code&scope=openid&nonce=9e0f0d92-5337-4988-8b33-1200ebb6a182&code_challenge=m_ReNZMLGBPkSIXpMeYUlFZg8cFKLWSwtt8sEF8fAGM&code_challenge_method=S256"
realizar_login(driver, usuario_sac, senha_sac, url_login)

# ================================
# CARREGA PLANILHA
# ================================

df = pd.read_excel(caminho_planilha)

colunas = {
    "Solicitante": "solicitante",
    "Municipio": "municipio",
    "Código Escola": "codigo_escola",
    "Escola": "escola",
    "Marca": "marca",
    "Numero de Série": "numero_serie",
    "Defeito": "defeito"
}

for col in colunas:
    if col not in df.columns:
        df[col] = ""

campos = {
    "solicitante": "formulario_manutencao\\.CRE",
    "municipio": "formulario_manutencao\\.municipio",
    "codigo_escola": "formulario_manutencao\\.inep",
    "escola": "formulario_manutencao\\.escola",
    "marca": "formulario_manutencao\\.marca",
    "numero_serie": "formulario_manutencao\\.serial",
    "defeito": "formulario_manutencao\\.defeito"
}

clear()
driver.get("https://seduc.4biz.one/workflow/pages/serviceRequestIncident/serviceRequestIncident.load?iframe=true")
time.sleep(5)

# ================================
# LOOP DE PROCESSAMENTO DE TICKETS
# ================================

for i, row in df.iterrows():
    ticket_num = str(row["Ticket"])
    print(f"🔍 Processando ticket: {ticket_num}")
    try:
        driver.switch_to.default_content()
        iframe = wait.until(EC.presence_of_element_located((By.TAG_NAME, "iframe")))
        driver.switch_to.frame(iframe)

        campo_busca = wait.until(EC.element_to_be_clickable((By.ID, "pesquisaSolicitacao")))
        campo_busca.clear()
        campo_busca.send_keys(ticket_num)
        campo_busca.send_keys(Keys.ENTER)
        time.sleep(1)

        #try:
            #driver.find_element(By.ID, "open-advanced-search").click()
            #time.sleep(1)
        #except:
            #pass

        #botao_pesquisar = wait.until(EC.element_to_be_clickable((By.ID, "button-filtro-pesquisar")))
        #driver.execute_script("arguments[0].click();", botao_pesquisar)
        campo_busca.send_keys(Keys.ENTER)
        time.sleep(2)

        # Espera adaptativa para o ticket aparecer
        ticket_found = False
        for _ in range(30):  # até 30 segundos
            try:
                element = driver.find_element(By.ID, f"list-item-{ticket_num}")
                ticket_found = True
                break
            except:
                time.sleep(1)
        if not ticket_found:
            print(f"⚠️ Ticket {ticket_num} não encontrado. Pulando...")
            continue

        driver.execute_script("arguments[0].scrollIntoView(true);", element)
        try:
            ActionChains(driver).double_click(element).perform()
        except:
            driver.execute_script("arguments[0].click();", element)

        wait.until(EC.presence_of_element_located((By.ID, "formulario_manutencaoPage")))
        time.sleep(2)

        valores = {}
        for nome, seletor_id in campos.items():
            try:
                elem = driver.find_elements(By.CSS_SELECTOR, f"input#{seletor_id}, textarea#{seletor_id}")
                valores[nome] = elem[0].get_attribute("value") if elem else None
            except:
                valores[nome] = None

        for col, nome in colunas.items():
            df.at[i, col] = valores.get(nome)

        try:
            botao_voltar = wait.until(EC.element_to_be_clickable(
                (By.CSS_SELECTOR, "button.request-back[title='Voltar']")))
            botao_voltar.click()
            botao_confirmar = wait.until(EC.element_to_be_clickable(
                (By.XPATH, "//button[contains(text(), 'Confirmar')]")))
            botao_confirmar.click()
            time.sleep(2)
        except:
            pass

    except Exception as e:
        import traceback
        print(f"❌ Erro ao processar ticket {ticket_num}: {e}")
        traceback.print_exc()
        continue

# ================================
# SALVA PLANILHA EM MEUS DOCUMENTOS
# ================================

caminho_documentos = os.path.join(os.path.expanduser("~"), "Documents", "planilha_atualizada.xlsx")
df.to_excel(caminho_documentos, index=False)
print(f"📁 Planilha atualizada salva em: {caminho_documentos}")

driver.quit()
