#include <stdio.h>

int main()
{
    int opcao;

    printf("_______Calculadora de notas _________\n");
    printf("|   Opção 1 - Cacular notas.         |\n");
    printf("|   Opção 2 - Determinar status.     |\n");
    printf("|   Opção 3 - Sair.                  |\n");
    printf("|   Escolha sua opção:               |\n");
    printf("|____________________________________|\n");
    scanf("%d", &opcao);
    
    float nota1, nota2;

    switch (opcao)
    {
    case 1:
        printf("_____Informar suas notas_____\n");
        printf("|  Nota 01:                  |\n");
        scanf("%.f", nota1);
        printf("|  Nota 02:                  |\n");
        scanf("%f", nota2);
        printf("_____________________________\n");
        break;
    
    default:
        break;
    }
    return 0;
}
