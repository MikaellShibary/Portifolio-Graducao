#include <stdio.h>

int main(){
    //Declaração dos valores das cartas 01 e 02
    //int turistico, populacao, turistico2, populacao2;
    //char estado[40], estado2[40];
    //char nome_cidade[30], nome_cidade2[30];
    //char ID_cidade[30], ID_cidade2[30];
    //float pib, area, densidade, PIB, pib2, area2, densidade2, PIB2, poder, poder2;
    
    // valores declarados para facilitar o codigo
    int turistico = 50, populacao = 12325000, turistico2 = 30, populacao2 = 67488000, opcao;
    char estado[40] = "São Paulo", estado2[40] = "Rio de Janeiro";
    char nome_cidade[30] = "São Paulo", nome_cidade2[30] = "Rio de Janeiros";
    char ID_cidade[30] = "SP01", ID_cidade2[30] = "RJ02";
    float pib = 699280000000, area = 1521.11, densidade, PIB, pib2 = 3005000000000, area2 = 1200.25, densidade2, PIB2, poder, poder2;
    int atb1, atb2;

    //flag pra indicar se é pra continuar rodando mostrando o menu ou n
    int rodando = 1; //1 significa ativo 0 inativo
    //flags para mostrar itens do submenu
    int item1Sub = 1;
    int item2Sub = 1; 
    int item3Sub = 1; 
    int item4Sub = 1; 
    int item5Sub = 1; 
    int item6Sub = 1;
    int item7Sub = 1;
    int sair = 1; 
            
    //Menu inicial 01
    printf("\n--- Super Trunfo - Países ---\n");
    printf("\n");
    printf("Opção 1 - Iniciar Jogo\n");
    printf("Opção 2 - Regras do Super Trunfo\n");
    printf("Digite o número da opção escolhida: \n");
    scanf("%d", &opcao);  

    //Criei um laço pra deixar tudo em loop, assim q termina o fluxo, repete tudo dnv
    while(rodando){    
    switch (opcao)
    {
    case 1:
        // Coleta dos dados da carta 01
    //printf("Desafio Super Trunfo - Países CARTA 01\n");

    //printf("Defina o ID da sua carta (Primeira letra e um número): ");
    //scanf("%s", &ID_cidade);

    //printf("Estado: ");
    //fgets(estado, sizeof(estado), stdin);

    //printf("Nome da cidade: ");
    //fgets(nome_cidade, sizeof(nome_cidade), stdin);

    //printf("População total da cidade (SEM PONTUAÇÃO): ");
    //scanf("%i", &populacao);

    //printf("Qual a área total da cidade: ");
    //scanf("%f", &area);

    //printf("Qual o PIB da cidade: ");
    //scanf("%f", &pib);

    //printf("Quantos pontos turísticos a cidade possui(SEM PONTUAÇÃO): ");
    //scanf("%d", &turistico);

    // Coleta dos dados da carta 02
    //printf("Desafio Super Trunfo - Países CARTA 02\n");

    //printf("Defina o ID da sua carta (Primeira letra e um número): ");
    //scanf("%s", &ID_cidade);

    //printf("Estado: ");
    //fgets(estado2, sizeof(estado2), stdin);
    
    //printf("Nome da cidade: ");
    //fgets(nome_cidade2, sizeof(nome_cidade2), stdin);

    //printf("População total da cidade (SEM PONTUAÇÃO): ");
    //scanf("%i", &populacao2);

    //printf("Qual o PIB da cidade: ");
    //scanf("%f", &pib2);

    //printf("Quantos pontos turísticos a cidade possui(SEM PONTUAÇÃO): ");
    //scanf("%d", &turistico2);

    //printf("Qual a área total da cidade: ");
    //scanf("%f", &area2);
        break;
     case 2:
            printf("#### REGRAS DO JOGO SUPER TRUFO ####");
            printf("\n");
            printf("O Super Trunfo é um jogo de cartas colecionáveis em que os jogadores tentam tirar todas as cartas dos adversários através de comparações de características. O jogador que primeiro conseguir todas as cartas vence o jogo.\n"); 
            printf("\n");
            printf("Regras:\n");
            printf("\n");
            printf("1-Distribuição: O baralho é dividido igualmente entre os jogadores, formando montes individuais. \n");
            printf("2-Início: O jogador à esquerda do distribuidor começa o jogo. \n");
            printf("3-Escolha da Característica: O primeiro jogador escolhe uma característica da sua carta de cima (ex: velocidade, altura) e lê em voz alta.\n");
            printf("4-Comparações: Os outros jogadores também escolhem a mesma característica na sua carta de cima e lêem o valor. \n");
            printf("5-Vencedor da Rodada: O jogador com o maior valor naquela característica ganha a rodada e recebe todas as cartas da mesa. \n");
            printf("6-Embaralhamento: As cartas ganhas na rodada são colocadas no fundo do próprio monte do vencedor. \n");
            printf("7-Carta Super Trunfo: Se houver uma carta Super Trunfo, ela vence a todas as cartas com as letras B, C e D (exceto a carta A). \n");
            printf("8-Empate: Em caso de empate, os jogadores que empataram escolhem outra característica e comparam novamente. \n");
            printf("9-Fim do Jogo: O jogo termina quando um jogador consegue todas as cartas dos outros. \n");
            printf("10-Vencedor: O jogador que fica com todas as cartas vence o jogo.\n");
            printf("\n");
        break;
    }
    //Caclulo do PIB e Densidade pop das cartas 01 e 02
    densidade = populacao / area;
    PIB = pib / populacao;
    densidade2 = populacao2 / area2;
    PIB2 = pib2 / populacao2;

    //calculo do poder da carta
    poder = (float)populacao + area + pib + (float)turistico + PIB - densidade; //Carta 01
    poder2 = (float)populacao2 + area2 + pib2 + (float)turistico2 + PIB2 - densidade2; // Carta 02

    //Menu inicial 02
    printf("\n---_ Super Trunfo - Países _---\n");
    printf("\n--- Comparações dos atributos ---\n");
    printf("\n");
    printf("Carta 01 x Carta 02\n");
    printf("\n");
    printf("\n");
    if(item1Sub){
        printf("Opção 1 - População.\n");
    }
    if(item2Sub){
        printf("Opção 2 - Área.\n");
    }
    if(item3Sub){
        printf("Opção 3 - PIB.\n");
    }
    if(item4Sub){
        printf("Opção 4 - Pontos Turísticos.\n");
    }
    if(item5Sub){
        printf("Opção 5 - Densidade Populacional.\n");
    }
    if(item6Sub){
       printf("Opção 6 - PIB per Capita.\n");
    }
    if(item7Sub){
       printf("Opção 7 - Poder.\n");
    }
    if(sair){
       printf("Opção 0 - Sair.\n");
    }


    printf("Digite o número da opção do atributo da CARTA 01: \n");
    scanf("%d", &atb1);

    switch (atb1)
    {
    case 1: //Comparação da população
        printf("População total das cidades das Carta 01 x Carta 02\n");
        if (populacao>populacao2) {
            printf("População da Carta 01 VENCEU !!!\n");
        } else if (populacao2>populacao){
            printf("População da Carta 02 VENCEU !!!\n");
        } else {
            printf("População das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.<' ");
        }
        item1Sub = 0;
    break;
    case 2: //Comparação da area
        printf("Area total das cidades das Carta 01 x Carta 02\n");
        if (area>area2){
            printf("Area total da Carta 01 VENCEU !!!\n");
        } else if (area2>area){
            printf("Area total da Carta 02 VENCEU !!!\n");
        } else {
            printf("Area total das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.< ");
        }
        item2Sub = 0;
    break;
    case 3: //Comparação do PIB
        printf("PIB das cidades das Carta 01 x Carta 02\n");
        if (pib>pib2){
            printf("PIB da Carta 01 VENCEU !!!\n");
        } else if (pib2>pib){
            printf("População da Carta 02 VENCEU !!!\n");
        } else {
            printf("PIB das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.< ");
        }
         item3Sub = 0;
    break;
    case 4: //Comparação do Pontos Turísticos
        printf("Pontos Turísticos das cidades das Carta 01 x Carta 02\n");
        if (turistico>turistico2){
            printf("Ponto Turístico da Carta 01 VENCEU !!!\n");
        } else if (turistico2>turistico){
            printf("População da Carta 02 VENCEU !!!\n");
        } else {
            printf("Pontos Turísticos das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.< ");
        }
         item4Sub = 0;
    break;
    case 5: //Comparação da Densidade população comparação inversa
        printf("Densidade Populacional das cidades das Carta 01 x Carta 02\n");
        if (densidade<densidade2){
            printf("Densidade populacional da Carta 01 VENCEU !!!\n");
        } else if (densidade2<densidade){
            printf("Densidade populacional da Carta 02 VENCEU !!!\n");
        } else {
            printf("Densidade populacional das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.< ");
        }
         item5Sub = 0;
    break;
    case 6: //Comparação da PIB per capita
        printf("PIB per capita das cidades das Carta 01 x Carta 02\n");
        if (PIB>PIB2){
            printf("PIB per capita da Carta 01 VENCEU !!!\n");
        } else if (PIB2>PIB2){
            printf("PIB per capita da Carta 02 VENCEU !!!\n");
        } else {
            printf("PIB per capita das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.< ");
        }
         item6Sub = 0;
    break;
    case 7: //Comparação do poder
        printf("Poder das cidades das Carta 01 x Carta 02\n");
        if (poder>poder2){
            printf("Poder da Carta 01 VENCEU !!!\n");
        } else if (poder2>poder){
            printf("Poder da Carta 02 VENCEU !!!\n");
        } else {
            printf("Poder das Cartas 01 e Carta 02 são iguais\n");
            printf("EMPATE >.< ");
        }
         item7Sub = 0;
    break;
    case 0: //sair
        rodando = 0;
    break;
    default:
            printf("Opção inválida\n");
    break;
    }
}
    return 0;
}
