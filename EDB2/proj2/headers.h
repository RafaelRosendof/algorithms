#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct No No;
typedef struct Heap Heap;

struct No {
    char identificador[100] ; // Identificador da aeronave
    int combustivel;         // combustivel
    long minutos ;           // minutos
    int tipo;                // 0 decolagem 1 pouso
    int emergencia;         // 0 não 1 sim
    int prioridade;         // base de calculo
};

struct  Heap{

};

bool inserir_aeronave(Heap *heap , No aeronave);
bool remove_aeronave(Heap *heap , No *aeronave);
bool heap_vazia(Heap *heap);
bool atualizar_prioridade(Heap *heap , char identificador[] , int nova_prioridade);
bool remover_maior_prioridade(Heap *heap);

int calculo_prioridade(No *aeronave);

No *consultar_maior_prioridade(Heap *heap);

void printa_heap(Heap *heap);
void printa_node(Heap *heap , char identificador[]);
void libera_heap(Heap *heap);

Heap *cria_heap_vazia();
Heap *carrega_csv(const char *nomeArq , Heap *heap);




#endif // HEADERS_H