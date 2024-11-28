#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define HEAP_MAX 1000

typedef struct No No;
typedef struct Heap Heap;

struct No {
    char identificador[100] ; // Identificador da aeronave
    int combustivel;         // combustivel
    long minutos ;           // minutos
    int tipo;                // 0 decolagem 1 pouso
    int emergencia;         // 0 não 1 sim
    int prioridade;         // base de calculo
    //No *filho1;
    //No *filho2;
};


struct Heap {
    No **avioes;
    int tamanho;
    int capacidade;

};

bool inserir_aeronave(Heap *heap , No *aeronave); //FEITO
bool remove_aeronave(Heap *heap , char identificador[]);//FEITO
bool heap_vazia(Heap *heap);//FEITO
bool atualizar_prioridade(Heap *heap , char identificador[]);//FEITO
bool remover_maior_prioridade(Heap *heap); //FEITO
bool pertence_heap(Heap *heap , char identificador[]); //FEITO


int calculo_prioridade(No *aeronave); //FEITO

No *consultar_maior_prioridade(Heap *heap); //vou retornar o índice

No *consulta_aeronave(Heap *heap , char identificador[]);

void ordena_heap(Heap *heap);//usando o heapify up
void heapify_up(Heap *heap , int i); //FEITO
void heapify_down(Heap *heap , int i); //FEITO
void printa_node(No* node); //FEITO
void printa_heap(Heap *heap);//FEITO
void printa_UnicoNode(Heap *heap , char identificador[]);//FEITO
void libera_heap(Heap *heap);//FEITO

Heap *cria_heap_vazia();//FEITO
Heap *carrega_csv(const char *nomeArq , Heap *heap);//FEITO




#endif // HEADERS_H
