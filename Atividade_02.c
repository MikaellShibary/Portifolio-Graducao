#include <stdio.h>

int main(){
    int idade, matricula;
    float altura;
    char nome [50];

    printf ("Nome completo: .\n")
    scanf ("%s, &nome\n")
}

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
    scanf ("%s, &municipio");

    printf ("Qual sua matricula: \n");
    scanf ("%d, &matricula");
    
    printf ("Nome completo: %s . Idade: %d . Altura: %f \n", nome, idade, altura);
    printf ("Município de nascimento: %s . Matricula: %d \n", municipio, matricula);

    return 0;
}

