#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "avl.h"
#include "trie.h"
#include "jogo.h"

 char *palavras = "palavras.txt";
 char *tabuleiros = "tabuleiro.txt";

//Colocar opções de visualizar a árvore e remover palavras, etc...
void jogar(char *file1 , char * file2, Trie * raizTrie , tree ** raizAVL){

    fluxoJogo(file2 , file1, raizTrie, raizAVL);

    //printf("Imprimindo a trie \n\n::: ");
    //char palavra[100] = "adrasteia";
    //imprimeTrie(raizTrie, palavra , 0); //até aqui ta ok

/*
    if(buscaTrie(raizTrie, palavra)){
        printf("Palavra encontrada\n");
        arv_insereAVL(raizAVL, palavra);
    }else{
        printf("Palavra não LOCALIZADA JOGAR FUNCTION\n");
    }
*/
/*
raizAVL = arv_insereAVL(raizAVL, "adrasteia");
raizAVL = arv_insereAVL(raizAVL, "adra");
raizAVL = arv_insereAVL(raizAVL, "figas");
raizAVL = arv_insereAVL(raizAVL, "Rafael");
*/



    //printf("Imprimindo a AVL\n");
    //imprimeAlfabetico(*raizAVL);

    int choice = 1;

    while(choice != 0){
        printf("\n\nDigite 0 para sair\n");
        printf("Digite 1 para imprimir as palavras encontradas\n");
        printf("Digite 2 para remover uma palavra\n");
        printf("Digite 3 para visualizar a árvore\n");
        printf("Digite 4 para visualizar verficar uma palavra\n");
        printf("Digite 5 para visualizar a Trie\n");

        scanf("%d" , &choice);

        switch(choice){
            case 0:
                printf("Saindo...\n");
                break;
            case 1:
                //imprimir_resultados();
                printf("Imprimindo a AVL\n");
                imprimeAlfabetico(*raizAVL);
                break;
            case 2:
                printf("Digite a palavra que deseja remover: ");
                char palavra[100];
                scanf("%s" , palavra);
                if(arv_removeAVL(raizAVL , palavra)){
                    printf("Palavra removida\n");
                }
                else{
                    printf("Palavra não encontrada\n");
                }
                break;
            case 3:
                imprimeAlfabetico(*raizAVL);
                break;
            case 4:
                printf("Digite a palavra que deseja remover: ");
                char palav[100]; //tava dando erro aqui de redefinição
                scanf("%s" , palav);
                if(arv_busca(*raizAVL, palav)){
                    printf("Palavra encontrada %s \n", palav);
                }else{
                    printf("Palavra não encontrada\n");
                }
                break;

            case 5:
                {
                char palavra[100]; //deu certo
                printf("Visualizadno a trie\n");
                //strcpy(palavra, "adrasteia"); // copia da primeira palavra do arquivo, ou pergunta qual palavra quer
                printf("Insira a primeira palavra que deseja: ");
                scanf("%s", palavra);
                printf("E a posição que deseja começar: ");
                int pos; scanf("%d", &pos);
                imprimeTrie(raizTrie, palavra, pos);
                }
                break;

            default:
                printf("Opção inválida\n");
                break;
        }
    }

}


int main(){

    printf("Bem-vindo ao jogo de palavras!\n");


    //printf("Digite o caminho do arquivo de palavras: ");
    char filePalavras[100];
    //scanf("%s", filePalavras);

    //printf("Digite o caminho do arquivo do tabuleiro: ");
    char fileTabuleiro[50];
    //scanf("%s", fileTabuleiro);

    // Inicializa as árvores
    Trie *raizTrie = criaNo();
    tree *raizAVL = arv_criaVazia();

    //imprimir_tabuleiro( tabuleiros, 100, 100);

    // Inicia o fluxo principal do jogo
    jogar(palavras, tabuleiros, raizTrie, &raizAVL);

    // Libera a memória alocada
    liberaTrie(raizTrie);
    arv_libera(raizAVL);

    printf("Jogo encerrado. Até a próxima!\n");
    return 0;

}
