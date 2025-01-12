#include "jogo.h"
#include "trie.h"
#include "avl.h"
#include <stdio.h>
#include <string.h>

/*
ler tabuleiro -> file.txt
ler palavras -> file.txt

buscar_palavras
imprimir resultados (palavras encontradas e armazenadas na AVL)
*/

tree * raizAVL = NULL;
Trie * raizTrie = NULL;

//tabuleiro para ficar mais fácil de acessar
char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE];


void iniciar_arvores(){
    raizAVL = arv_criaVazia();
    raizTrie = criaNo();
}



//INCOMPLETO -> FALTA VALIDAR NA TRIE
//Somente caso seja validado na trie
void inserir_palavraAVL(char * palavra){

   // raizAVL = arv_insereAVL(raizAVL , palavra);

}

void imprmir_palavras(char * palavras){
    printf("%s\n" , palavras);
}

//Copiado dos outros projetos
void ler_palavras(char * file, Trie * raiz){
    FILE * arq = fopen(file , "r");

    if(!arq){
        printf("Erro ao abrir o arquivo das palavras\n");
        return;
    }

    char linha[1000];
    while(fgets(linha , sizeof(linha) , arq)){
        char palavra[100];
        sscanf(linha , "%s" , palavra);

        insereTrie(raiz , palavra);
        //imprmir_palavras(palavra);
        //imprimeTrie(raiz, palavra, 0);
        printf(" PALAVRA INSERIDA: %s\n", palavra);
    }
    char palavra[100] = "adrasteia";



    imprimeTrie(raiz, palavra , 0);
    fclose(arq);

}

void imprimir_tabuleiro(char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE], int linhas, int colunas) {
    printf("\nTabuleiro carregado:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void ler_tabuleiro(char *file) {
    FILE *arq = fopen(file, "r");

    if (!arq) {
        printf("Erro ao abrir o arquivo do tabuleiro\n");
        return ;
    }

    char linha[1000];
    int i = 0;

    while (fgets(linha, sizeof(linha), arq)) {
        for (int j = 0; j < strlen(linha); j++) {
            if (linha[j] != '\n') {
                tabuleiro[i][j] = linha[j];
            }
        }
        i++;
    }

    fclose(arq);

    imprimir_tabuleiro(tabuleiro, i, strlen(linha) - 1); // debug

}

void buscar_Tabu(Trie *raiz, tree **raizAVL, char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE]) {
    char palavra[100];
    int linhas = TABULEIRO_SIZE;
    int colunas = TABULEIRO_SIZE;
    
    printf("Tabuleiro carregado:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Para cada posição inicial no tabuleiro
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Para cada direção possível
            for (int Di = -1; Di <= 1; Di++) {
                for (int Dj = -1; Dj <= 1; Dj++) {
                    if (Di == 0 && Dj == 0) continue; // Ignora a direção (0, 0)
                    
                    int x = i, y = j;
                    int pos = 0;
                    memset(palavra, 0, sizeof(palavra));
                    
                    // Enquanto estiver dentro dos limites do tabuleiro
                    while (x >= 0 && x < linhas && y >= 0 && y < colunas && pos < 99) {
                        // Adiciona apenas o caractere atual (sem espaços)
                        palavra[pos++] = tabuleiro[x][y];
                        palavra[pos] = '\0';
                        
                        if (buscaTrie(raiz, palavra)) {
                            printf("Palavra encontrada: %s na posição inicial (%d,%d)\n",palavra, i, j);
                            
                            // Debug print before insertion
                           // printf("Antes da inserção:\n");
                            //debug_print_tree(*raizAVL, 0);
                            
                            // Correct way to call arv_insereAVL
                            *raizAVL = arv_insereAVL(raizAVL, palavra);
                            
                            // Debug print after insertion
                            //printf("Depois da inserção:\n");
                        //    debug_print_tree(*raizAVL, 0);
                        }
                        
                        // Move para próxima posição na direção atual
                        x += Di;
                        y += Dj;
                    }
                }
            }
        }
    }
}


void imprimir_resultados(){
    imprimeAlfabetico(raizAVL);
}

void fluxoJogo(char * arquivoTab , char * arqP, Trie * raizTrie , tree ** raizAVL){

    iniciar_arvores();           // inicializa AVL e Trie
    ler_palavras(arqP, raizTrie); // carrega palavras na Trie

    //printf("\n\nLendo as palavras da trie agora\n\n");
    //char palavra[100] = "adrasteia";
    //imprimeTrie(raizTrie, palavra , 0);

    ler_tabuleiro(arquivoTab); // carrega tabuleiro

    buscar_Tabu(raizTrie, raizAVL,  tabuleiro); // busca palavras no tabuleiro

}
