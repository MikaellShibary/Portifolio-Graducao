#include <stdio.h>

/*main (){
    for (int i = 0; i <= 10; i++){
        for (int j = 0; j <= 10; j++){
        printf("Resultado %d \n", i * j);
        }
    printf("\n");
    }
    return 0;
}*/
main (){
    int i, j;
    char letra;

    for (i = 1; i <= 5; i++)
    {
        letra = 'A';
        printf("Triangulacao de letras \n");

        for (j = i; j <= i; j++)
        {
            printf("%c", letra);
            ++letra;
        }
        printf("\n");
    }
    return 0;
}
