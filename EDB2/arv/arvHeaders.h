#ifndef ARVHEADERS_H
#define ARVHEADERS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Arv Arv;

struct Arv {
    char info;
    int num_filhos;           // Número de filhos no nó
    Arv **filhos;      // Array dinâmico de ponteiros para filhos
};

// Funções para manipulação da árvore N-ária
struct Arv *cria_arv_vazia();
struct Arv *cria_no(char c);
bool arv_vazia(struct Arv *arv);
void libera(struct Arv *arv);
bool insere_arv(struct Arv *arv, char c);
void imprime_arvPreOrdem(struct Arv *arv);
void imprime_arvPosOrdem(struct Arv *arv);
void imprime_larg(struct Arv *arv);
bool pertence(struct Arv *arv, char c);
int altura_arv(struct Arv *arv);
bool remove_arv(struct Arv *arv, char c);

#endif // ARVHEADERS_H

