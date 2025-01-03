#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "avl.h"
#include "trie.h"


bool ler_palavras(char * file);
bool ler_tabuleiro(char * file);

bool buscar_palavras(Trie * raiz , char tabuleiro[100][100]);

void imprimir_resultados(); //-> função para exibir as palavras encontradas, armazenadas na AVL