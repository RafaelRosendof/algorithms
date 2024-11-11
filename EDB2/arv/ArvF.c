#include "arvHeaders.h"

/*

Alocação da arvore filhos 
Alocação da arvore mãe
bool arv_vazia(struct Arv *arv)
void libera(struct Arv *arv)
bool insere_arv(struct Arv *arv, char c)
void imprime_arv(struct Arv *arv)
bool pertence(struct Arv *arv, char c)
int altura_arv(struct Arv *arv)
bool remove_arv(struct Arv *arv, char c)

*/

struct Arv *cria_arv_vazia(){
    return NULL;
}

struct Arv *cria_no(char c){
    struct Arv *novo_no = (struct Arv*)malloc(sizeof(struct Arv));

    if(novo_no == NULL){
        printf("Erro na alocação de memória\n");
        exit(1);
    }

    novo_no -> info = c; //colocando valor no nó
    novo_no -> num_filhos = 0; //inicialmente não tem nenhum filho
    novo_no -> filhos = NULL; //inicialmente não tem nenhum filho

    return novo_no;
}

bool arv_vazia(struct Arv *arv){
    return (arv == NULL) ? true : false; //verificando se é nulo 
}

void libera(struct Arv *arv){
    if(arv == NULL){return;}

    for(int i = 0 ; i < arv ->num_filhos; i++){
        libera(arv -> filhos[i]);
    }

    free(arv->filhos);
    free(arv);
}

void imprime_arvPreOrdem(struct Arv *arv){
    if(arv == NULL){return;}

    printf("%c ", arv -> info);
    for(int i = 0; i < arv -> num_filhos; i++){
        imprime_arvPreOrdem(arv -> filhos[i]);
    }
}

void imprime_arvPosOrdem(struct Arv *arv){
    if(arv == NULL){return;}

    for(int i = 0; i < arv -> num_filhos; i++){
        imprime_arvPosOrdem(arv -> filhos[i]);
    }
    printf("%c ", arv -> info);
}

void imprime_larg(struct Arv *arv){
    if (arv == NULL){return;}

    return; //TODO
}
