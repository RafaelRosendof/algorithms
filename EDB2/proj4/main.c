#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "avl.h"
#include "trie.h"
#include "jogo.h"


//Colocar opções de visualizar a árvore e remover palavras, etc...
void jogar(char *file1 , char * file2){

    fluxoJogo(file2 , file1);

    int choice = 1;

    switch (choice)
    {
    case (choice == 2):
        
        break;
    
    default:
        break;
    }

}


int main(){

    printf("Iniciando o jogo\n");

    printf("\nDigite o nome do arquivo de palavras, coloque o caminho global: ");
    char file[100];
    scanf("%s",file);

    printf("\n\nDigite o nome do arquivo de tabuleiro, coloque o caminho global: ");
    char fileTab[1000];
    scanf("%s",fileTab);

    jogar(file , fileTab);



    return 0;
}