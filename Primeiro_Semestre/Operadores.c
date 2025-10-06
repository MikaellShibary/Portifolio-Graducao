#include <stdio.h>

int main(){
    int numero1, numero2;
    int soma, multiplicacao, divisao, subtracao;
    
    divisao = numero1 / numero2; //Operação de divisão
    soma = numero1 + numero2; //Operação de somar +
    subtracao = numero1 - numero2; //Operação de subtração -
    multiplicacao = numero1 * numero2; //Operação de multiplicação *

    printf ("Informe o primerio número: \n");
    scanf ("%d", &numero1);

    printf ("Informe o segundo núemro: \n");
    scanf ("%d", &numero2);

    printf ("RESULTADOS DOS VALORES INFORMADOS \n");
    printf ("Soma é: %d \n", soma);
    printf ("Subtração é: %d \n", subtracao);
    printf ("Divisão é: %d \n", divisao);
    printf ("Multiplicação é: %d \n", multiplicacao);


    return 0;
}
