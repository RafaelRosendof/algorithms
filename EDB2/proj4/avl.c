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


tree * rotacaoDireita(tree * raiz){
    tree * aux = raiz -> esq;

    raiz -> esq = aux -> dir;

    aux -> dir = raiz;

    raiz -> alt = 1 + max(arv_altura(raiz -> esq) , arv_altura(raiz -> dir));
    aux -> alt = 1 + max(arv_altura(aux -> esq) , arv_altura(aux -> dir));

    return aux;
}

tree * rotacaoEsquerda(tree * raiz){
    tree * aux = raiz -> dir;

    raiz -> dir = aux -> esq;
    aux -> esq = raiz;

    raiz -> alt = 1 + max(arv_altura(raiz -> esq) , arv_altura(raiz -> dir));
    aux -> alt = 1 + max(arv_altura(aux -> esq) , arv_altura(aux -> dir));

    return aux;
}


tree * rotacaoDuplaEsquerda(tree * raiz){
    raiz -> dir = rotacaoDireita(raiz -> dir);
    return rotacaoEsquerda(raiz);
}

tree * rotacaoDuplaDireita(tree * raiz){
    raiz -> esq = rotacaoEsquerda(raiz -> esq);
    return rotacaoDireita(raiz);
}

//como que eu soluciono isso 
tree * arv_insereAVL(tree * raiz , char * palavra){
    if( raiz == NULL){
        No novoNode;
        strcpy(novoNode.palavra , palavra);
        return arv_criaNo(novoNode);
    }

    if (strcmp(palavra, raiz->node.palavra) < 0 ){
        return arv_insereAVL(raiz -> esq , palavra);
    }
    else if(strcmp(palavra, raiz->node.palavra) > 0){
        return arv_insereAVL(raiz -> dir , palavra);
    }

    else{

        printf("Palavra já foi adicionada na AVL ");
        return raiz; 
    }

    raiz -> alt = 1 + max(arv_altura(raiz -> esq) , arv_altura(raiz -> dir));

    int fb = fatorBalanceamento(raiz);

    if( fb > 1 && strcmp(palavra , raiz -> esq -> node.palavra) < 0 ){
        return rotacaoDireita(raiz);
    }

    if( fb < -1 && strcmp(palavra , raiz -> dir -> node.palavra) > 0){
        return rotacaoEsquerda(raiz);
    }

    if( fb > 1 && strcmp(palavra , raiz -> esq -> node.palavra) > 0){
        return rotacaoDuplaDireita(raiz);
    }

    if (fb < -1 && strcmp(palavra , raiz -> dir -> node.palavra) < 0){
        return rotacaoDuplaEsquerda(raiz);
    }

    return raiz;

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


bool arv_removeAVL(tree **raiz , char * palavra){
    
    if ( (*raiz) == NULL){
        printf("Arvore vazia, nada a remover ");
        return false;
    }

    if( strcmp(palavra , (*raiz)->node.palavra) < 0){
        return arv_removeAVL( (*raiz) -> esq , palavra);
    }

    else if( strcmp(palavra , (*raiz) -> node.palavra) > 0){
        return arv_removeAVL((*raiz)->dir , palavra);
    }

    else {

        if( (*raiz) -> esq == NULL && (*raiz) -> dir == NULL){
            free (*raiz);
            *raiz = NULL;
            return true;
        }

        if( (*raiz) -> esq == NULL || (*raiz) -> dir == NULL){

            tree *aux = (*raiz) -> esq ? (*raiz) -> esq : (*raiz) -> dir;

            free (*raiz);
            *raiz = aux;
            return true;
        }

        tree * aux = (*raiz) -> dir;

        while( aux -> esq != NULL){
            aux = aux -> esq;
        }

        (*raiz) -> node = aux -> node;

        arv_removeAVL( &(*raiz) -> dir , aux -> node.palavra);
    }

    //dúvida
}