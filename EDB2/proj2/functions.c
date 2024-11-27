#include "headers.h"
#include <stdio.h>

Heap *cria_heap_vazia(){
    Heap *heap = (Heap *) malloc(sizeof(Heap));
    heap -> capacidade = HEAP_MAX;
    heap -> tamanho = 0;
    heap -> avioes = (No **)malloc(HEAP_MAX * sizeof(No *));
    return heap;
}

Heap *carrega_csv(const char *nomeArq , Heap *heap){
    FILE *arq = fopen(nomeArq , "r");
    if(!arq){
        printf("Erro ao abrir o arquivo ");
        return NULL;
    }

    char linha[1000];
    int primeiro = 1;

    while(fgets(linha , sizeof(linha), arq)){
        if(primeiro){
            primeiro = 0;
            continue;
        } //trantado o header do csv, pular ele

        No aviao;

        sscanf(
            linha , "%99[^,],%d,%ld,%d,%d",
            aviao.identificador,
            &aviao.combustivel,
            &aviao.minutos,
            &aviao.tipo,
            &aviao.emergencia
        );
        No *novo = (No *) malloc(sizeof(No));
        *novo = aviao;
        novo -> prioridade = calculo_prioridade(novo);
        inserir_aeronave(heap, novo);
    }
    fclose(arq);
    return heap;
}


void printa_heap(Heap *heap){
    if(heap == NULL) return;

    for(int i =0 ; i < heap -> tamanho ; i++){
    printa_node(heap -> avioes[i]);
    }

}

void printa_node(No *node){
    printf("Identificador: %s , Combustível: %d , Minutos %ld , Tipo: %d , Emergência %d , Prioridade %d",node -> identificador , node -> combustivel , node -> minutos , node -> tipo , node -> emergencia , node -> prioridade);;
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

void heapify_up(Heap *heap, int i){
    while(i > 0){
        int pai = (i - 1) / 2;
        if(heap -> avioes[pai] -> prioridade >= heap -> avioes[i]->prioridade)break;

        //trocando
        No *temp = heap -> avioes[pai];
        heap -> avioes[pai] = heap -> avioes[i];
        heap -> avioes[i] = temp;

        i = pai;
    }
}

void heapify_down(Heap *heap, int i){
    while(true){
        int maior = i;
        int esq = i * 2 + 1;
        int dir = i * 2 + 2;

        if(esq < heap -> tamanho && heap -> avioes[esq] -> prioridade > heap ->avioes[maior] -> prioridade){
            maior = esq;
        }

        if(dir < heap -> tamanho && heap -> avioes[dir] -> prioridade > heap -> avioes[maior] -> prioridade){
            maior = dir;
        }

        if(maior == i) break;

        No *temp = heap -> avioes[i];
        heap -> avioes[i] = heap -> avioes[maior];
        heap -> avioes[maior] = temp;

        i = maior;
    }
}


bool inserir_aeronave(Heap *heap , No *aviao){
    if(heap -> tamanho == heap -> capacidade){
        printf("HEAP CHEIA ALOCANDO O DOBRO DE MEMÓRIA");
        heap -> capacidade *= 2;
        heap -> avioes = (No **) realloc(heap -> avioes , heap -> capacidade * sizeof(No *));
    }

    heap ->avioes[heap ->tamanho] = aviao;
    int i = heap -> tamanho;
    heap -> tamanho++;

    heapify_up(heap, i);
    return true;
}

bool remove_aeronave(Heap *heap , char identificador[]){
    if(heap == NULL || heap -> tamanho == 0 ) return false;

    for(int i = 0 ; i < heap -> tamanho ; i++){
        if(strcmp(heap -> avioes[i] -> identificador , identificador ) == 0){
            free(heap -> avioes[i]);

            for(int j = i ; j < heap -> tamanho - i ; j++){
                heap -> avioes[j] = heap -> avioes[j + 1];
            }

            heap -> tamanho--;

            heapify_down(heap, i);
            return true;
        }
    }

    printf("Nenhum elemento encontrado!!!!");
    return false;
}

bool remover_maior_prioridade(Heap *heap){
    if(heap == NULL || heap -> tamanho == 0) return false;

    int indice = 0;

    remove_aeronave(heap , heap -> avioes[indice]->identificador);

    return true;
}

bool atualizar_prioridade(Heap *heap, char identificador[]){
/*
bool atualizar_prioridade(Heap *heap, char identificador[], int nova_prioridade) {
    if (heap == NULL || heap->tamanho == 0) return false;

    for (int i = 0; i < heap->tamanho; i++) {
        if (strcmp(heap->avioes[i]->identificador, identificador) == 0) {
            int prioridade_antiga = heap->avioes[i]->prioridade;
            heap->avioes[i]->prioridade = nova_prioridade;

            // Se a prioridade aumentou, sobe
            if (nova_prioridade > prioridade_antiga) {
                heapify_up(heap, i);
            } else {  // Se a prioridade diminuiu, desce
                heapify_down(heap, i);
            }

            return true;
        }
    }
    printf("Aeronave não encontrada!\n");
    return false;
}

*/
}



bool heap_vazia(Heap *heap){
    return heap == NULL || heap -> tamanho == 0 ? true : false;

}

No *consultar_maior_prioridade(Heap *heap){
    if(heap == NULL || heap -> tamanho == 0) return NULL;

    //já que está organizado via prioridade então o maior é a raiz
    return heap -> avioes[0] ;
}

int calculo_prioridade(No *aviao){
    int prioridade = (1000 - aviao->combustivel) + (1440 - aviao->minutos) + 500 * aviao->tipo + 5000 * aviao->emergencia;
    return prioridade;
}
