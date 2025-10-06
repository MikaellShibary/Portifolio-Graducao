#include <stdio.h>

int main()
{
    float Banana, Uva;

    printf("----------  Pesquisa de preço de frutas ----------\n");

    printf("Qual valor da Banana ? \n");
    scanf("%f",&Banana);

    printf("Qual valor da Uva? \n");
    scanf("%f", &Uva);

    //comparativo de valores informados através do if
    if(Banana > Uva){    
        printf("Banana está mais cara\n");
    }else{
                 printf("Uva está mais cara\n");
    }
    printf("Estão no mesmo preço\n");
    /* code */
    return 0;
}
