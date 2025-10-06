//Declaração das bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes gerais/globais do banco
#define max_livros 100
#define tam_string 50

//Definição da STRUCT
struct livro {
    char nome[tam_string];
    char autor[tam_string];
    char editora[tam_string];
    int edicao;
};

//Limpar o BUFFER
int LimparBuferDeEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}
    
//Função principal
int main(void) {
    struct livro biblioteca[max_livros];
    int TotalLivros = 0;
    int opcao;

    //principal ação
    do {
        //Menu de ação
        printf("Biblioteca Serviços - Parte 1 \n");
        printf("1 - Cadastrar Livro \n");
        printf("2 - Listar Livros \n");
        printf("0 - Sair \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        LimparBuferDeEntrada(); //Limpar o buffer do teclado

        //Ações do menu conforme a opção escolhida
        switch (opcao) {
            case 1: //Cadastrar Livro
                printf("\nCadastrar Livro \n");
                if (TotalLivros < max_livros) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[TotalLivros].nome, tam_string, stdin);
                    
                    printf("Digite o nome do autor: ");
                    fgets(biblioteca[TotalLivros].autor, tam_string, stdin);

                    printf("Digite o nome da editora: ");
                    fgets(biblioteca[TotalLivros].editora, tam_string, stdin);

                    //Remover o \n do final das strings
                    biblioteca[TotalLivros].nome[strcspn(biblioteca[TotalLivros].nome, "\n")] = 0;
                    biblioteca[TotalLivros].autor[strcspn(biblioteca[TotalLivros].autor, "\n")] = 0;
                    biblioteca[TotalLivros].editora[strcspn(biblioteca[TotalLivros].editora, "\n")] = 0;

                    printf("Digite a edição do livro: ");
                    scanf("%d", &biblioteca[TotalLivros].edicao);
                    LimparBuferDeEntrada();
                    
                    TotalLivros++; //Incrementa uma vez apenas
                    printf("Livro cadastrado com sucesso! \n");
                } else {
                    printf("Capacidade máxima de livros atingida! \n");
                    printf("Não é possível cadastrar mais livros. \n");
                }
                printf("Pressione Enter para continuar...");
                getchar(); //Aguardar o usuário pressionar Enter
                break;

            case 2: //Listar Livros
                printf("\nListar Livros \n");
                if (TotalLivros == 0) {
                    printf("Nenhum livro cadastrado! \n");
                } else {
                    for (int i = 0; i < TotalLivros; i++) {
                        printf("Livro %d: \n", i + 1);
                        printf("Nome: %s \n", biblioteca[i].nome);
                        printf("Autor: %s \n", biblioteca[i].autor);
                        printf("Editora: %s \n", biblioteca[i].editora);
                        printf("Edição: %d \n\n", biblioteca[i].edicao);
                    }
                }
                printf("Pressione Enter para continuar...");
                getchar();
                break;

            case 0: //Sair
                printf("\nSaindo do programa... \n");
                printf("Obrigado por usar o sistema! \n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente. \n");
                printf("Pressione Enter para retornar ao menu...");
                getchar();
                break;
        }
    } while (opcao != 0);

    return 0;
}
