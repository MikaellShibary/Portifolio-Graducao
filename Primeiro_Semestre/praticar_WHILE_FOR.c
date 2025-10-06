#include <stdio.h>

int main(){

    /*int i = 0;
    while (i <= 10)
    {
        if (i %2 == 0){
            printf("Valor de While é par %d\n", i);
        }else if (i %2 != 0){
            printf("Valor do WHile é impar %d\n", i);
        }
        i++;
    }*/
    int numero, i;
    /*do
    {
        printf("para sair do jogo basta digitar um número par\n");
        printf("Digite  um número:\n");
        scanf("%i", &numero);

        if (numero%2==0)
        {
            printf("Valor digitado é par %i\n",numero);
        } else{
            printf("Valor digitado é impar %d\n",numero);
        }
        
    } while (numero % 2 != 0);

    printf("Saindo do programa...");*/
    printf("Digite o valor para a cacluladora da tabuada!\n");
    scanf("%i",numero);

    for ( i = 0; i <= 10; i++)
    {
        printf("%d x %d = %d", i, numero, i * numero);
    }
    
    return 0;
}
