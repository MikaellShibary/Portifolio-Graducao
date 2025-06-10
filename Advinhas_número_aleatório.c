#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
    int opcao, numerosecreto, palpite;

  printf("Menu Principal\n");
  printf("1. Iniciar Jogo\n");
  printf("2. Ver Regras\n");
  printf("3. Sair\n");
  printf("Escolha uma opção: \n");
  scanf("%d", &opcao);

  switch (opcao)
  {
  case 1:
    srand (time(0));
    numerosecreto=rand()%10+1;
    printf("Advinhe o número entre 1 a 10: \n");
    scanf ("%d", &palpite);
    if (palpite == numerosecreto){
        printf ("Você acertou o número\n");
    } else {
        printf ("VocÊ errou o número, correto seria o número %d\n", numerosecreto);
    }
    case 2:
      printf("Regras do Jogo:\n");
      printf("1. Escolha uma opção no menu.\n");
      printf("2. Se você escolher 'Iniciar Jogo', adivinhe o número secreto.\n");
      printf("3. O jogo termina quando você escolhe 'Sair'.\n");
      break;
}