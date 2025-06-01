#include <stdio.h>

int main () {
    int idade, matricula;
    float altura;
    char nome [50];
    char municipio [50];

    printf ("Nome completo:\n");
    scanf ("%s, &nome");

    printf ("Sua idade é:\n");
    scanf ("%d, &idade");

    printf ("Sua altura é: \n");
    scanf ("%f, &altura");

    printf ("Município de nascimento: \n");
    scanf ("%s, &município");

    printf ("Qual sua matricula: \n");
    scanf ("%d, &matricula");
    
    printf ("Nome completo: %s. Idade: %d\n, Altura: %f.2 nome, idade, altura\n");
    printf ("Município de nascimento: %s. Matricula: %d, município, matricula");
    
    return 0;
}
