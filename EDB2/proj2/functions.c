#include "headers.h"


Heap *cria_heap_vazia(){
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap -> tamanho = 0;
    heap -> capacidade = 1;

    return heap;
}

void printa_heap(Heap *heap){
    if(heap == NULL){return;}

    printf("Identificador: %s , Combustível: %d , Minutos %l , Tipo: %d , Emergência %d , Prioridade %d",heap -> aviao.identificador, heap -> aviao.combustivel , heap -> aviao.minutos , heap -> aviao.tipo , heap -> aviao.emergencia , heap -> aviao.prioridade);

    printa_node(heap -> avioes[0]);;
}

void printa_node(No *node){
    printf()
}

void printa_node_indentificador(Heap *heap , char identificador[]){
    if(heap == NULL){
        printf("HEAP VAZIA !!!!");
        return;
    }
}
