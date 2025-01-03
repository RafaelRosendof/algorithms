#include "avl.h"


/*
cria node 
insere palavra encontrada e validada na trie 

balanceamento 

remove a palavra a critério do usuário 

balanceamento pós remoção 

imprimer em ordem alfabética(deve ter algo pronto já)
*/

tree * arv_criaVazia(){
    return NULL;
}

tree * arv_criaNo(No node){
    tree * novo = (tree*)malloc(sizeof(tree));
    novo -> node = node;
    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> alt = arv_altura(novo);
    novo -> num_filhos = 0;
}





tree * rotacaoDuplaEsquerda(tree * raiz){
    raiz -> dir = rotacaoDireita(raiz -> dir);
    return rotacaoEsquerda(raiz);
}

tree * rotacaoDuplaDireita(tree * raiz){
    raiz -> esq = rotacaoEsquerda(raiz -> esq);
    return rotacaoDireita(raiz);
}

char * arv_busca(tree * raiz , char *palavra){
    if (raiz == NULL){
        return NULL;
    }

    if (strcmp(raiz -> node.palavra , palavra) == 0){
        return raiz->node.palavra;
    }

    else if(strcmp(raiz -> node.palavra , palavra) > 0){
        return arv_busca(raiz -> esq , palavra);
    }

    else{
        return arv_busca(raiz -> dir , palavra);
    }

    printf("NÓ NÃO ENCONTRADO");

}


int arv_altura(tree * raiz){
    if (raiz == NULL){
        return -1;
    }

    int h1 = arv_altura(raiz -> esq);
    int h2 = arv_altura(raiz -> dir);

    return (h1 > h2) ? h1 + 1 : h2 + 1;
}

int max(int a , int b){
    return (a > b) ? a : b;
}

int fatorBalanceamento(tree * raiz){
    if (raiz == NULL){
        return 0;
    }

    return arv_altura(raiz -> esq) - arv_altura(raiz -> dir);
}

void arv_libera(tree * raiz){
    if (raiz == NULL) return;

    arv_libera(raiz -> esq);
    arv_libera(raiz -> dir);

    free(raiz);
}

void imprimeAlfabetico(tree * raiz){
    if (raiz == NULL) return;

    imprimeAlfabetico(raiz -> esq);
    printf("%s\n" , raiz -> node.palavra);
    imprimeAlfabetico(raiz -> dir);
}

