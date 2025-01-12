#ifndef AVL_H
#define AVL_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tree tree ;

struct tree{
    int alt;
    char palavra[100];
    int num_filhos;
    tree * esq;
    tree *dir;
};

void auxiliar(tree* raiz, int level);
tree * arv_criaVazia(); //feito
tree * arv_insereAVL(tree ** raiz, char * palavra); //feito
//tree * arv_insereAVL(tree* raiz , char * palavra); //feito
tree * arv_criaNo(char palavra[100]); //feito
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
