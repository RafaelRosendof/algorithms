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

Trie * criaNo(); //feito

void insereTrie(Trie * raiz , char * palavra); //feito

bool buscaTrie(Trie * raiz , char *palavra); //feito

void imprimeTrie(Trie * raiz , char * palavra , int pos); //feito

void liberaTrie(Trie * raiz); //feito

char * verificaTrie(Trie * raiz , char * palavra); //feito

#endif //TRIE_H
