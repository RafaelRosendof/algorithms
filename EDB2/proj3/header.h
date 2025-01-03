#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No No ;
typedef struct tree tree ;

struct No{
    int age;
    char name[100];
    int score;
};

struct tree{
    int alt;
    No node;
    int num_filhos;
    tree * esq;
    tree *dir;
};

tree * leitor_csv(tree * raiz , char * csv_file); //feito 
tree * arv_criaVazia(); //feito
tree * arv_insereAVL(tree* raiz , No node); //feito
tree * arv_criaNo(No node); //feito
tree * rotacaoDireita(tree* raiz);
tree * rotacaoEsquerda(tree* raiz);
//tree * rotacaoDuplaDireita(tree* raiz);
//tree * rotacaoDuplaEsquerda(tree* raiz);

void arv_libera(tree* raiz); //feito
void imprimeOrdem(tree * raiz); //feito
void imprimePreOrdem(tree * raiz); //feito

int arv_altura(tree * raiz); //feito
int fatorBalanceamento(tree * raiz); //feito
int max(int a , int b); //feito

bool arv_vazia(tree * raiz); //feito
//bool arv_pertence(tree * raiz , int score);
bool * arv_busca(tree* raiz , int score); //feito
bool arv_removeAVL(tree** raiz , int score); //feito


#endif //HEADER_H
