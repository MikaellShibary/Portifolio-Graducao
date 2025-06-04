#include <stdio.h>

int main() {
    //Declaração dos valores das cartas 01 e 02
    //int turistico, populacao, turistico2, populacao2;
    //char estado[40], estado2[40];
    //char nome_cidade[30], nome_cidade2[30];
    //char ID_cidade[30], ID_cidade2[30];
    //float pib, area, densidade, PIB, pib2, area2, densidade2, PIB2, poder, poder2;
    
    // valores declarados para facilitar o codigo
    int turistico = 50, populacao = 1232500, turistico2 = 30, populacao2 = 67488000;
    char estado[40] = "São Paulo", estado2[40] = "Rio de Janeiro";
    char nome_cidade[30] = "São Paulo", nome_cidade2[30] = "Rio de Janeiros";
    char ID_cidade[30] = "SP01", ID_cidade2[30] = "RJ02";
    float pib = 699.28, area = 1521.11, densidade, PIB, pib2 = 300.50, area2 = 1200.25, densidade2, PIB2, poder, poder2;

    // Coleta dos dados da carta 01
    //printf("Desafio Super Trunfo - Países CARTA 01\n");

    //printf("Estado: ");
    //fgets(estado, sizeof(estado), stdin);

    //printf("Nome da cidade: ");
    //fgets(nome_cidade, sizeof(nome_cidade), stdin);

    //printf("População total da cidade (SEM PONTUAÇÃO): ");
    //scanf("%i", &populacao);

    //printf("Qual o PIB da cidade: ");
    //scanf("%f", &pib);

    //printf("Quantos pontos turísticos a cidade possui(SEM PONTUAÇÃO): ");
    //scanf("%d", &turistico);

    //printf("Qual a área total da cidade: ");
    //scanf("%f", &area);

    //printf("Defina o ID da sua carta (Primeira letra e um número): ");
    //scanf("%s", &ID_cidade);

    // Coleta dos dados da carta 02
    //printf("Desafio Super Trunfo - Países CARTA 02\n");

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

    //printf("Defina o ID da sua carta (Primeira letra e um número): ");
    //scanf("%s", &ID_cidade2);

    //Caclulo do PIB e Densidade pop das cartas 01 e 02
    densidade = populacao / area;
    PIB = pib / populacao;
    densidade2 = populacao2 / area2;
    PIB2 = pib2 / populacao2;

    //calculo do poder da carta
    poder = (float)populacao + area + pib + (float)turistico + PIB - densidade; //Carta 01
    poder2 = (float)populacao2 + area2 + pib2 + (float)turistico2 + PIB2 - densidade2; // Carta 02

     // Impressão dos dados coletados
    printf("\n--- Super Trunfo - Países ---\n");
    printf("\n");
    //Impressão dos dados da carta 01
    printf("CARTA 01");
    printf("\n");
    printf("ID da cidade: %s\n", ID_cidade);
    printf("Estado: %s", estado);
    printf("Nome da cidade: %s", nome_cidade);
    printf("Total de %d pessoas.\n", nome_cidade, populacao);
    printf("Sua área de %.2f km².\n", nome_cidade, area);
    printf("Pontos turísticos.\n", nome_cidade, turistico);
    printf("Tem seu Produto Interno Bruto (PIB) de R$:%.0f bilhões de reais.\n", nome_cidade, pib);
    printf("Densidade populacional é de %.2f hab/km².\n", nome_cidade, densidade);
    printf("PIB per Capita é de R$:%.2f reais.\n", nome_cidade, PIB);
    printf("Super poder: Carta 01 %.2f de poder.", poder);
    printf("\n");
    printf("\n");
    //Impressão dos dados da Carta 02
    printf("CARTA 02\n");
    printf("\n");
    printf("ID da cidade: %s\n", ID_cidade2);
    printf("Estado: %s", estado2);
    printf("Nome da cidade: %s", nome_cidade2);
    printf("Total de %d pessoas.\n", nome_cidade2, populacao2);
    printf("Sua área de %.2f km².\n", nome_cidade2, area2);
    printf("Pontos turísticos.\n", nome_cidade2, turistico2);
    printf("Tem seu Produto Interno Bruto (PIB) de R$:%.0f bilhões de reais.\n", nome_cidade2, pib2);
    printf("Densidade populacional é de %.2f hab/km².\n", nome_cidade2, densidade2);
    printf("PIB per Capita é de R$:%.2f reais.\n", nome_cidade2, PIB2);
    printf("Super poder: Carta 02 %.2f de poder.", poder2);

       //comparação de qual carta vence
    printf("\n--- Super Trunfo - Países ---\n");
    printf("\n--- Países resultados ---\n");
    printf("\n");
    printf("\n");
    printf("População venceu: %2.f\n", (populacao > populacao2));
    printf("PIB venceu: %2.f\n", (pib > pib2));
    printf("Pontos turísticos venceu: %2.f\n", (turistico > turistico2));
    printf("Densidade populacional venceu: %2.f\n", (densidade > densidade2));
    printf("PIB per carpita venceu: %2.f\n", (PIB > PIB2));
    printf("Super poder venceu: %2.f\n", (poder > poder2));

    //Comparação entre os atributos com IF e ELSE
    printf("----- Comparações entre as cartas -----\n")
    printf("Carta 01 - População: %2.f\n", populacao);
    printf("Carta 02 - População: %2.f\n", populacao2);
        if (populacao > populacao2)
        {
             printf("Carta 01 venceu\n");
        }else{
            printf("Carta 02 vence\n");
        }
    return 0;
}