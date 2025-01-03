#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avl.h"
#include "trie.h"

#define TABULEIRO_SIZE 100

extern char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE];

void iniciar_arvores();
bool ler_palavras(char * file);
bool ler_tabuleiro(char * file);
void inserir_palavraTrie(char * palavra);
void inserir_palavraAVL(char * palavra);
bool buscar_palavras(Trie * raiz , char * tabuleiro);

void imprimir_resultados(); 