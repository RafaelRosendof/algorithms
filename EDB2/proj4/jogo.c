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

/*
void inserir_palavraTrie(char * palavra){
    insereTrie(raizTrie , palavra); //colocar a insereTrie como tree ou mudar a lógica aqui
}
*/

//INCOMPLETO -> FALTA VALIDAR NA TRIE
//Somente caso seja validado na trie
void inserir_palavraAVL(char * palavra){
    //No node;
    //strcpy(node.palavra , palavra);
    raizAVL = arv_insereAVL(raizAVL , palavra);
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
    }
    char palavra[100] = "carro";
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

//função de busca
void buscar_Tabu(Trie *raiz, char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE]) {
    char palavra[100]; // Buffer para armazenar a palavra formada durante a busca
    int linhas = TABULEIRO_SIZE; // Número de linhas do tabuleiro
    int colunas = TABULEIRO_SIZE; // Número de colunas do tabuleiro

    // Percorre cada posição da matriz (tabuleiro)
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            // Explora todas as direções possíveis (8 direções: N, NE, E, SE, S, SO, O, NO)
            for (int Di = -1; Di <= 1; Di++) {
                for (int Dj = -1; Dj <= 1; Dj++) {
                    // Ignora a direção estática (quando não há movimento em nenhuma direção)
                    if (Di == 0 && Dj == 0) continue;

                    int x = i; // Coordenada inicial da linha
                    int y = j; // Coordenada inicial da coluna
                    int pos = 0; // Índice para construção da palavra

                    // Percorre na direção atual enquanto estiver dentro dos limites do tabuleiro
                    while (x >= 0 && x < linhas && y >= 0 && y < colunas) {
                        // Adiciona a letra atual ao buffer da palavra
                        palavra[pos++] = tabuleiro[x][y];
                        palavra[pos] = '\0'; // Adiciona o caractere nulo para formar uma string válida

                        //char *resultado = verificaTrie(raiz, palavra);
                        //if (resultado != NULL) {
                            //inserir_palavraAVL(palavra); // Se existir, insere na AVL
                            //}

                        if (buscaTrie(raiz, palavra)) {
                            inserir_palavraAVL(palavra);
                        } else {
                            //printf("Não foi possível inserir aqui");
                            break; // Pare se o prefixo não for válido
                        }


                        // Atualiza as coordenadas para a próxima posição na direção atual
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

void fluxoJogo(char * arquivoTab , char * arqP, Trie * raizTrie){

    iniciar_arvores();           // inicializa AVL e Trie
    ler_palavras(arqP, raizTrie); // carrega palavras na Trie

    printf("\n\nLendo as palavras da trie\n\n");
    char palavra[100] = "carro";
    imprimeTrie(raizTrie, palavra , 0);

    ler_tabuleiro(arquivoTab); // carrega tabuleiro

    buscar_Tabu(raizTrie, tabuleiro); // busca palavras no tabuleiro

}
