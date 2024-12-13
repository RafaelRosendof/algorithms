#include "headers.h"
#include <stdio.h>

int main() {

    Heap *heap = cria_heap_vazia();
    if (!heap) {
        printf("Erro ao criar a heap.\n");
        return 1;
    }


    const char *nome_arquivo = "file.csv";
    heap = carrega_csv(nome_arquivo, heap);
    if (!heap) {
        printf("Erro ao carregar o arquivo CSV.\n");
        libera_heap(heap);
        return 1;
    }

    printf("Heap inicial:\n");
    printa_heap(heap);


    char id_consulta[] = "AV003";
    printf("\nConsultando aeronave com identificador %s:\n", id_consulta);
    printa_UnicoNode(heap, id_consulta);


    No *nova_aeronave = (No *)malloc(sizeof(No));
    if (nova_aeronave) {
        strcpy(nova_aeronave->identificador, "AV021");
        nova_aeronave->combustivel = 120;
        nova_aeronave->minutos = 90;
        nova_aeronave->tipo = 1;
        nova_aeronave->emergencia = 0;
        nova_aeronave->prioridade = calculo_prioridade(nova_aeronave);
        inserir_aeronave(heap, nova_aeronave);
        printf("\nAeronave AV021 inserida:\n");
        printa_heap(heap);
    }


    printf("\nRemovendo aeronave de maior prioridade:\n");
    remover_maior_prioridade(heap);
    printa_heap(heap);

    char id_remover[] = "AV005";
    printf("\nRemovendo aeronave com identificador %s:\n", id_remover);
    remove_aeronave(heap, id_remover);
    printa_heap(heap);


    char id_atualizar[] = "AV007";
    printf("\nAtualizando prioridade da aeronave com identificador %s:\n", id_atualizar);
    atualizar_prioridade(heap, id_atualizar);
    printa_heap(heap);


    printf("\nConsultando aeronave de maior prioridade:\n");
    No *maior_prioridade = consultar_maior_prioridade(heap);
    if (maior_prioridade) {
        printa_node(maior_prioridade);
    } else {
        printf("Heap vazia ou erro na consulta.\n");
    }


    libera_heap(heap);

    return 0;
}
