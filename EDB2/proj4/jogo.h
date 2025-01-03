#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avl.h"
#include "trie.h"

void iniciar_arvores();
bool ler_palavras(char * file);
bool ler_tabuleiro(char * file);
void inserir_palavraTrie(char * palavra);
void inserir_palavraAVL(char * palavra);
bool buscar_palavras(Trie * raiz , char tabuleiro[100][100]);

void imprimir_resultados(); 