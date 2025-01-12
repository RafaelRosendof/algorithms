#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avl.h"
#include "trie.h"

#define TABULEIRO_SIZE 100

//extern char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE];

void imprimir_tabuleiro(char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE], int linhas, int colunas);
void imprimir_palavras(char * palavras);
void iniciar_arvores(); //feito
void ler_palavras(char * file, Trie *raiz); //feito
void ler_tabuleiro(char * file); //feito
void inserir_palavraTrie(char * palavra , Trie *raiz); //feito
void inserir_palavraAVL(char * palavra);  ////feito
void buscar_Tabu(Trie * raiz ,tree ** raizAVL, char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE]);

void imprimir_resultados(); //feito

void fluxoJogo(char * tabuleiro , char * palavras, Trie *raiz, tree **raizAVL);
