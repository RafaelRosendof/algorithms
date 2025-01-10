#include "headers.h"


Heap *cria_heap_vazia(){
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap -> tamanho = HEAP_MAX;
    heap -> capacidade = 0;
    heap -> avioes = (No **)malloc(HEAP_MAX * sizeof(No *));
    return heap;
}

Heap *carrega_csv(const char *nomeArq , Heap *heap){

    return heap;
}


void printa_heap(Heap *heap){
    if(heap == NULL) return;

    for(int i =0 ; i < heap -> tamanho ; i++){
    printa_node(heap -> avioes[i]);
    }

}

void printa_node(No *node){
    printf("Identificador: %s , Combustível: %d , Minutos %l , Tipo: %d , Emergência %d , Prioridade %d",node -> identificador , node -> combustivel , node -> minutos , node -> tipo , node -> emergencia , node -> prioridade);;
}

void printa_node_indentificador(Heap *heap , char identificador[]){
    if(heap == NULL || heap -> tamanho == 0){
        printf("HEAP VAZIA !!!!");
        return;
    }

    for(int i =0 ; i < heap -> tamanho ; i++){
        if(strcmp(heap -> avioes[i] -> identificador , identificador) == 0){
            printa_node(heap -> avioes[i]);
            return;
        }
    }
    printf("AERONAVE NÃO ENCONTRADA ");
}

void libera_heap(Heap *heap){
    if(heap == NULL){
        printf("HEAP NÃO ALOCADA, NADA A DESALOCAR");
        return;
    }
    for( int i = 0 ; i < heap -> tamanho ; i++){
        free(heap -> avioes[i]);
    }
    free(heap -> avioes);
    free(heap);

    printf("HEAP LIBERADA COM SUCESSO !!!!");
}

No *consultar_maior_prioridade(Heap *heap){
    if(heap == NULL || heap -> tamanho == 0){
        printf("HEAP VAZIA !!!!");
        return NULL;
    }

    if(heap -> avioes[0] -> prioridade < heap -> avioes[1] -> prioridade){
        return heap -> avioes[1];
    } else {
        return heap -> avioes[0];
    }

    return //retorna o node, como que faço isso?
}

bool heap_vazia(Heap *heap){
    bool lambda = heap == NULL || heap -> tamanho == 0 ? true : false;
    return lambda;
}
