#ifndef AVL_H
#define AVL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct No No ;
typedef struct tree tree ;

struct No{
    char palavra[100];
};

struct tree{
    int alt;
    No node;
    int num_filhos;
    tree * esq;
    tree *dir;
};

tree * arv_criaVazia(); //feito
tree * arv_insereAVL(tree* raiz , char * palavra); //feito
tree * arv_criaNo(No node); //feito
tree * rotacaoDireita(tree* raiz); //feito
tree * rotacaoEsquerda(tree* raiz); //feito
tree * rotacaoDuplaDireita(tree* raiz); //feito
tree * rotacaoDuplaEsquerda(tree* raiz); //feito

char * arv_busca(tree* raiz , char * palavra); //feito

void arv_libera(tree* raiz); //feito
void imprimeAlfabetico(tree * raiz); //feito

int arv_altura(tree * raiz); //feito
int fatorBalanceamento(tree * raiz); //feito
int max(int a , int b); //feito

bool arv_removeAVL(tree** raiz , char * palavra); //feito


#endif //AVL_H