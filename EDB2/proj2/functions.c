#include "headers.h"
#include <stdio.h>
#include <string.h>

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

void printa_UnicoNode(Heap *heap , char identificador[]){
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
    return;
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
            //ou - i
            for(int j = i ; j < heap -> tamanho - 1 ; j++){
                heap -> avioes[j] = heap -> avioes[j + 1]; // todos avançam?
            }                                              //como explicar

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

bool pertence_heap(Heap *heap, char identificador[]){
    if(heap == NULL || heap -> tamanho == 0){
        printf("HEAP VAZIA OU NULA  ");
        return false;
    }

    for(int i = 0 ; i < heap -> tamanho ; i++){
        if(strcmp(heap -> avioes[i] -> identificador, identificador)== 0){
            printf("\n\n ACHOU O ELEMENTO !!!! %d", i);
            return true;
        }
    }
    printf("Elemento não existe na heap com esse identificador %s",identificador);
    return false;
}

void ordena_heap(Heap *heap) {
    if (heap == NULL || heap->tamanho == 0) {
        printf("Heap vazia ou nula, impossível ordenar.\n");
        return;
    }

    for (int i = (heap->tamanho - 2) / 2; i >= 0; i--)  { //explicar melhor esse for
        heapify_down(heap, i);
    }
}

No *consulta_aeronave(Heap *heap , char identificador[]){
    if(heap == NULL || heap -> tamanho == 0){
        printf("HEAP VAZIA OU NÃO INICIALIZADA");
        return NULL;
    }

    for(int i = 0 ; i < heap -> tamanho ; i++){
        if(strcmp(heap -> avioes[i] -> identificador, identificador) == 0){
            return heap -> avioes[i];
        }
    }

    printf("Node não encontrado pela busca");
    return NULL;
}

bool atualizar_prioridade(Heap *heap, char identificador[]) {
    if (heap == NULL || heap->tamanho == 0) {
        printf("HEAP VAZIA, IMPOSSÍVEL ATUALIZAR A PRIORIDADE\n");
        return false;
    }

    if (!pertence_heap(heap, identificador)) {
        printf("Elemento não encontrado na HEAP\n");
        return false;
    }

    No *aeronave = consulta_aeronave(heap, identificador);
    if (aeronave == NULL) {
        printf("Erro ao consultar a aeronave\n");
        return false;
    }

    printf("\nEscolha o parâmetro que quer atualizar:\n");
    printf("(1) Combustível\n");
    printf("(2) Minutos\n");
    printf("(3) Tipo\n");
    printf("(4) Emergência\n");
    printf("\nEscolha: ");

    int escolha;
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: {
            printf("Novo combustível: ");
            int novo_combustivel;
            scanf("%d", &novo_combustivel);
            aeronave->combustivel = novo_combustivel;
            break;
        }
        case 2: {
            printf("Novos minutos: ");
            long novos_minutos;
            scanf("%ld", &novos_minutos);
            aeronave->minutos = novos_minutos;
            break;
        }
        case 3: {
            printf("Novo tipo: ");
            int novo_tipo;
            scanf("%d", &novo_tipo);
            aeronave->tipo = novo_tipo;
            break;
        }
        case 4: {
            printf("Emergência? (0 = não, 1 = sim): ");
            int nova_emergencia;
            scanf("%d", &nova_emergencia);
            aeronave->emergencia = nova_emergencia;
            break;
        }
        default:
            printf("Escolha inválida.\n");
            return false;
    }

    // Recalcula a prioridade e reorganiza a heap
    aeronave->prioridade = calculo_prioridade(aeronave);
    ordena_heap(heap); // Pode ser otimizado se souber o índice

    return true;
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
