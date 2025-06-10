#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int player, pc;
    srand(time(0));

    printf("____Jogo JoKenPo____\n");
    printf("Escolha umas das opções a baixo\n");
    printf("\n");
    printf("1.Pedra\n");
    printf("2.Papel\n");
    printf("3.Tesoura\n");
    printf("Qual sua escolha:\n");
    scanf("%d",&player);
    //Escolha aleatória do PC
    pc = rand () % 3 + 1;

    switch (player)
    {
    case 1:
        printf("Jogador escolheu: Pedra\n");
        break;
    case 2:
        printf("Jogador escolheu: Papel\n");
        break;
    case 3:
        printf("Jogador escolheu: Tesoura\n");
    default:
        printf("Opção invalida, tente entre 1-Pedra, 2-Papel e 3-Tesoura.\n");
        break;
    }
        switch (pc)
    {
    case 1:
        printf("PC escolheu: Pedra\n");
        break;
    case 2:
        printf("PC escolheu: Papel\n");
        break;
    case 3:
        printf("PC escolheu: Tesoura\n");
    }
    if (player=pc)
    {
        printf("Empate.\n");
    } else if  (player == 1) && (pc == 3) || (player == 2) && (pc == 1) || (player == 3) && (pc == 2);
    {
        printf("Player ganhou\n");
    } else {
        printf("Player perdeu\n");
    }
    return 0;
}