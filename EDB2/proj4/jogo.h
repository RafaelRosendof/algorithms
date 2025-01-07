#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avl.h"
#include "trie.h"

#define TABULEIRO_SIZE 100

extern char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE];

void iniciar_arvores(); //feito
bool ler_palavras(char * file); //feito
bool ler_tabuleiro(char * file); //feito
void inserir_palavraTrie(char * palavra); //feito
void inserir_palavraAVL(char * palavra);  ////feito
bool buscar_palavras(Trie * raiz , char * tabuleiro);

void imprimir_resultados(); //feito