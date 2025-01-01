#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_ALFABETO 26

typedef struct Trie Trie;

struct Trie{
    Trie * filhos[TAM_ALFABETO];
    bool folha;
};

//funções 

Trie * criaNo();

void insereTrie(Trie * raiz , char * palavra);

bool buscaTrie(Trie * raiz , char *palavra);

void imprimeTrie(Trie * raiz , char * palavra , int pos);

void liberaTrie(Trie * raiz);

bool verificaTrie(Trie * raiz , char * palavra);

#endif //TRIE_H
