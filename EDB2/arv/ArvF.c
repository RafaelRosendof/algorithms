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
typedef struct Arv Arv;

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

bool insere_arv(Arv *arv, char c){

    if(arv == NULL){return false;}


    Arv *novo_no = cria_no(c);

    if(novo_no == NULL){return false;}

    arv -> num_filhos++;

//realocar o array de gilhos para adicionar o novo nó
    Arv **aux = (Arv**)realloc(arv -> filhos, arv -> num_filhos * sizeof(Arv*));

    if(aux == NULL){
        printf("Erro na alocação de memória\n");
        free(novo_no);
        arv -> num_filhos--;
        return false;
    }

    arv -> filhos = aux;
    arv -> filhos[arv -> num_filhos - 1] = novo_no;

    return true;
}

bool pertence(Arv *arv , char c){
    if(arv == NULL){return false;}

    if(arv -> info == c){printf("Elemento encontrado \n"); return true;}

    for(int i = 0 ; i < arv -> num_filhos ; i++){
        if(pertence(arv -> filhos[i], c)){
            return true;
        }
    }

    printf("Elemento não encontrado\n");
    return false; 
}


