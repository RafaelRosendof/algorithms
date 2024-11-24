#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct No No;
typedef struct Arvore Arvore;

struct No {
    int codigo;               // Identificador único do livro
    char titulo[100];         // Nome do livro
    char autor[100];          // Autor do livro
    char genero[50];          // Gênero do livro
    int ano;                  // Ano de publicação
    char editora[100];        // Nome da editora
    int numPaginas;           // Número de páginas do livro
};

struct Arvore {
    No livro;                 // Dados do livro no nó atual
    int num_filhos;           // Número de filhos do nó atual
    Arvore* esq;              // Ponteiro para o filho à esquerda
    Arvore* dir;              // Ponteiro para o filho à direita
};

Arvore* arvore_criaVazia(); //feito

Arvore* arvore_insere(Arvore* raiz, No livro);//feito

Arvore *arv_criaNo(No livro); //feito

void arvore_libera(Arvore* raiz); //feito

bool arv_vazia(Arvore *arv); //feito

Arvore* arvore_busca(Arvore* raiz, int codigo); //feito

void arvore_buscaPorGenero(Arvore* raiz, const char genero[]); //feito

bool arvore_pertence(Arvore* raiz, int codigo);

void arvore_imprimeOrdem(Arvore* raiz); //feito
void arvore_imprimePreOrdem(Arvore* raiz);//feito
void arvore_imprimePosOrdem(Arvore* raiz);//feito

int arvore_altura(Arvore* raiz); //feito

bool arvore_removeNo(Arvore** raiz, int codigo); //feito

Arvore* carregarCSV(const char* nomeArquivo, Arvore* raiz); //TODO





#endif // HEADERS_H


/*

Arvore* arvore_criaVazia();
bool arv_vazia(Arvore* arv);
Arvore* arv_criaNo(No livro);
void arvore_libera(Arvore* raiz);
Arvore* arvore_insere(Arvore* raiz, No livro);
Arvore* arvore_busca(Arvore* raiz, int codigo);
void arvore_imprimeOrdem(Arvore* raiz);
int arvore_altura(Arvore* raiz);
*/