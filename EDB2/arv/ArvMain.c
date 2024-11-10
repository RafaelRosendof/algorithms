#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arv
{
    char info;
    struct Arv *esq;
    struct Arv *dir;
};

typedef struct Arv Arv;

//colocar isso no header? 

Arv *cria_arv_vazia(char c){
    Arv *arv = (Arv*) malloc(sizeof(Arv));
    arv->info = c;
    arv->esq = NULL;
    arv->dir = NULL;
    return arv;
}

bool arv_vazia(Arv *arv){
    return arv == NULL;
}

void libera(Arv *arv){
    Arv * p = arv -> esq;
    while(p != NULL){
        Arv *t = p->dir;
        libera(p);
        p = t;
    }
    free(arv);
}

/*
métodos a fazer 

Criar arvore 

void ou bool inserir na árvore 

void imprimir arvore 

bool pertence 

void libera arvore 

bool arvore vazia

int altura arvore

bool remove da árvore 


*/
