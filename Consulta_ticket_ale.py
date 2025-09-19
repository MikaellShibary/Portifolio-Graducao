import time
import pandas as pd
import os
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.action_chains import ActionChains

# ================================
# CONFIGURAÇÕES
# ================================

usuario_sac = "mikaell.mesquita"
senha_sac = "Mesquita1001"
caminho_planilha = r"C:\Users\mikaell.mesquita\Documents\PLANILHA CONTROLE DAS MANUTENÇÕES (3).xlsx"

# ================================
# FUNÇÃO DE LOGIN
# ================================


def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def realizar_login(driver, usuario, senha, url_login, max_tentativas=3):
    from selenium.webdriver.common.by import By
    from selenium.webdriver.common.keys import Keys
    from selenium.webdriver.support.ui import WebDriverWait
    from selenium.webdriver.support import expected_conditions as EC
    from selenium.common.exceptions import TimeoutException
    import time

    tentativa = 0
    login_sucesso = False

    while tentativa < max_tentativas and not login_sucesso:
        tentativa += 1
        print(f"Tentativa de login #{tentativa}")

        driver.get(url_login)

        try:
            # Aguarda os campos aparecerem
            WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.ID, "user_login")))

            # Preenche os campos
            driver.find_element(By.ID, "user_login").clear()
            driver.find_element(By.ID, "user_login").send_keys(usuario)

            driver.find_element(By.ID, "password").clear()
            driver.find_element(By.ID, "password").send_keys(senha + Keys.RETURN)

            # Aguarda possível redirecionamento
            time.sleep(5)

            # Verifica se a URL mudou
            if driver.current_url != url_login:
                login_sucesso = True
                print("✅ Login realizado com sucesso!")
            else:
                print("❌ Login falhou, tentando novamente...")
                time.sleep(3)

        except Exception as e:
            print(f"⚠️ Erro na tentativa #{tentativa}: {e}")
            time.sleep(3)

    if not login_sucesso:
        print("🚫 Não foi possível realizar o login após várias tentativas.")

    return login_sucesso

# ================================
# INICIALIZA WEBDRIVER
# ================================

driver = webdriver.Chrome()
wait = WebDriverWait(driver, 10)

# ================================
# LOGIN
# ================================

url_login = "https://seducgo.cloud4biz.com/4biz/webmvc/login"
login_ok = realizar_login(driver, usuario_sac, senha_sac, url_login)

# ================================
# EXECUÇÃO PRINCIPAL
# ================================

if login_ok:

    # Acessa a planilha e salva no dataframe df
    df = pd.read_excel(caminho_planilha)

    # Colunas que serão preenchidas
    colunas = {
        "Solicitante": "solicitante",
        "Municipio": "municipio",
        "Código Escola": "codigo_escola",
        "Escola": "escola",
        "Marca": "marca",
        "Numero de Série": "numero_serie",
        "Defeito": "defeito"
    }

    # Adiciona colunas se não existirem
    for col in colunas:
        if col not in df.columns:
            df[col] = ""

    # Define os campos para extrair
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
    driver.get("https://seducgo.cloud4biz.com/4biz/pages/serviceRequestIncident/serviceRequestIncident.load#/")

    for i, row in df.iterrows():
        ticket_num = str(row["Ticket"])
        print(f"🔍 Processando ticket: {ticket_num}")
        try:
              
            wait = WebDriverWait(driver, 50)

            # Espera o campo de busca aparecer
            campo_busca = wait.until(EC.element_to_be_clickable((By.ID, "pesquisaSolicitacao")))
            print("Campo de busca pronto")

            # Limpa e insere o ticket
            campo_busca.clear()
            time.sleep(1)
            campo_busca.send_keys(ticket_num)
            time.sleep(1)

            # Abre a busca avançada (se necessário)
            try:
                botao_abrir_busca_avancada = driver.find_element(By.ID, "open-advanced-search")
                botao_abrir_busca_avancada.click()
                print("📂 Busca avançada aberta")
                time.sleep(0.5)
            except Exception as e:
                print(f"⚠️ Falha ao abrir busca avançada (pode já estar aberta): {e}")

            # Aguarda o botão de pesquisa ficar visível e clicável
            try:
                botao_pesquisar = WebDriverWait(driver, 30).until(
                    EC.element_to_be_clickable((By.ID, "button-filtro-pesquisar"))
                )
                botao_pesquisar.click()
                driver.execute_script("arguments[0].click();", botao_pesquisar)
                print("🔎 Botão de pesquisa clicado com sucesso")
                time.sleep(2)
            except Exception as e:
                print(f"❌ ERRO: Não foi possível clicar no botão de pesquisa: {e}")
                continue  # pula para o próximo ticket


            # Espera que a lista seja carregada — por exemplo, espera que o item com o ticket apareça
            try:
                element = WebDriverWait(driver, 50).until(
                    EC.element_to_be_clickable((By.ID, f"list-item-{ticket_num}"))
                )
                print(f"✅ Ticket {ticket_num} encontrado na lista.")
            except Exception as e:
                print(f"❌ ERRO: Ticket {ticket_num} não encontrado na lista: {e}")
                continue

            driver.execute_script("arguments[0].scrollIntoView(true);", element)

            # Limpa os filtros
            botao_limpar = driver.find_element(By.ID, "button-filtro-limpar")
            driver.execute_script("arguments[0].click();", botao_limpar)

            # Tenta o duplo clique
            try:
                time.sleep(5)
                ActionChains(driver).double_click(element).perform()
                print("Duplo clique realizado, esperando formulário")
            except Exception as e:
                print(f"⚠️ Duplo clique falhou: {e} - tentando click simples via JS")
                driver.execute_script("arguments[0].click();", element)
                continue
                     
            
            WebDriverWait(driver, 50).until(EC.presence_of_element_located((By.ID, "formulario_manutencaoPage")))  # ou outro ID principal

            #Checar a ATIVIDADE do chamado, se difente de MANUTENÇÃO ou VISTORIA, retornar e presquisar próximo chamado
            if "MANUTENÇÃO" in texto_atividade:
                print("Atividade: MANUTENÇÃO")
            elif "VISTORIA" in texto_atividade:
                print("Atividade: VISTORIA")
            else:
                print("Atividade diferente:", texto_atividade)

            #Aguardando formulário
            print("Formulário de manutenção aberto")
            time.sleep(10)

            valores = {}

            # Agora capturar os campos
            for nome, seletor_id in campos.items():
                try:
                    elem = driver.find_elements(By.CSS_SELECTOR, f"input#{seletor_id}, textarea#{seletor_id}")
                    valores[nome] = elem[0].get_attribute("value")
                    print(f"Campo {nome}: {valores[nome]}")
                except Exception as e_inner:
                    print(f"⚠️ Não encontrei o campo {nome} para ticket {ticket_num}: {e_inner}")
                    valores[nome] = None

            # Guardar os dados no DataFrame ou no dicionário
            df.at[i, "Solicitante"] = valores.get("solicitante")
            df.at[i, "Municipio"] = valores.get("municipio")
            df.at[i, "Código Escola"] = valores.get("codigo_escola")
            df.at[i, "Escola"] = valores.get("escola")
            df.at[i, "Marca"] = valores.get("marca")
            df.at[i, "Numero de Série"] = valores.get("numero_serie")
            df.at[i, "Defeito"] = valores.get("defeito")

            print(f"✅ Ticket {ticket_num} processado")

            try:
                # Clica no botão "Voltar"
                botao_voltar = wait.until(EC.element_to_be_clickable((
                    By.CSS_SELECTOR,
                    "button.request-back[title='Voltar']"
                )))
                botao_voltar.click()
                print("🔙 Botão 'Voltar' clicado")

                # Aguarda e clica no botão "Confirmar"
                botao_confirmar = wait.until(EC.element_to_be_clickable((
                    By.XPATH,
                    "//button[contains(text(), 'Confirmar')]"
                )))
                botao_confirmar.click()
                print("✅ Navegação confirmada para voltar")

                # Aguarda brevemente para garantir carregamento da lista novamente
                time.sleep(2)

            except Exception as e:
                print(f"⚠️ Erro ao tentar voltar após acessar ticket {ticket_num}: {e}")

        except Exception as e:
            import traceback
            print(f"❌ Erro ao processar ticket {ticket_num}: {e}")
            traceback.print_exc()
             #volta para o topo do loop externo
            raise  # levanta de novo para o try externo

    # ================================
    # SALVAR OS RESULTADOS
    # ================================
    
    df.to_excel("planilha_atualizada.xlsx", index=False)
    print("📁 Planilha atualizada salva como 'planilha_atualizada.xlsx'.")

else:
    print("❌ Encerrando script por falha no login.")

# ================================
# ENCERRAR WEBDRIVER
# ================================

driver.quit()

