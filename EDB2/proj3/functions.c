#include "header.h"

/*
 *
 * tree* rotacaoDireita(tree* raiz) {
    tree* aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;

    raiz->alt = 1 + max(arv_altura(raiz->esq), arv_altura(raiz->dir));
    aux->alt = 1 + max(arv_altura(aux->esq), arv_altura(aux->dir));

    return aux;
}

tree* rotacaoEsquerda(tree* raiz) {
    tree* aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;

    raiz->alt = 1 + max(arv_altura(raiz->esq), arv_altura(raiz->dir));
    aux->alt = 1 + max(arv_altura(aux->esq), arv_altura(aux->dir));

    return aux;
}

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
    return novo;

}

tree * leitor_csv(tree * raiz , char * csv_file){
    FILE * arq = fopen(csv_file , "r");

    if(!arq){
        printf("Arquivo inválido ");
        return NULL;
    }

    char linha[10000];
    int first = 1;

    while(fgets(linha , sizeof(linha) , arq)){
        if(first){
            first = 0;
            continue;
        }

        No processo;

        sscanf(
            linha , "%d , %99[^,],%d",
            &processo.age,
            processo.name,
            &processo.score
        );

        raiz = arv_insereAVL(raiz , processo);
    }

    fclose(arq);
    return raiz;

}

tree * arv_insereAVL(tree *raiz , No node){

    if(raiz == NULL){
        return arv_criaNo(node);
    }

    if( node.score > raiz -> node.score){
        return arv_insereAVL(raiz -> dir , node);
    }
    else if(node.score < raiz -> node.score){
        return arv_insereAVL(raiz -> esq , node);
    }

    else{
        printf("Já foi cadastrado, não tem como inserir novamente: ");
        return raiz;
    }

    raiz -> alt = 1 + max(arv_altura(raiz->esq),arv_altura(raiz -> dir));

    //fazendo as verificações 

    int fb = fatorBalanceamento(raiz);

    if( fb > 1 && node.score < raiz -> esq -> node.score){
        return rotacaoDireita(raiz);
    }

    if(fb < -1 && node.score > raiz -> dir -> node.score){
        return rotacaoEsquerda(raiz);
    }

    if(fb > 1 && node.score > raiz -> esq -> node.score){
        raiz -> esq = rotacaoEsquerda(raiz -> esq);
        return rotacaoDireita(raiz);
    }

    if(fb < -1 && node.score < raiz -> dir -> node.score){
        raiz->dir = rotacaoDireita(raiz -> dir);
        return rotacaoEsquerda(raiz);
    }

    return raiz;
}


bool  arv_removeAVL(tree ** raiz , int score){
    if(raiz == NULL){
        printf("Arvore vazia, nada a remover ");
        return false;
    }

    if( (*raiz) -> node.score > score){
        return arv_removeAVL(&(*raiz) -> esq , score);
    }
    else if( (*raiz) -> node.score < score){
        return arv_removeAVL(&(*raiz) -> dir , score);
    }

    else {

        if ( (*raiz) -> esq == NULL && (*raiz) -> dir == NULL){
            free(*raiz);
            *raiz = NULL;
            return true;
        }

        if( (*raiz) -> esq == NULL || (*raiz) -> dir == NULL){
            tree *aux = (*raiz) -> esq ? (*raiz) -> esq : (*raiz) -> dir;

            free(*raiz);
            *raiz = aux;
            return true;
        }

        tree * aux = (*raiz) -> dir;

        while(aux -> esq != NULL){
            aux = aux -> esq;
        }

        (*raiz) -> node = aux -> node;

        //return arv_removeAVL( &(*raiz) -> dir , aux -> node.score);

        arv_removeAVL(&(*raiz) -> dir , aux -> node.score);
    }


    (*raiz) -> alt = max(arv_altura((*raiz) -> esq) , arv_altura((*raiz) -> dir)) - 1;

    int fb = fatorBalanceamento(raiz);

    if( fb > 1 && (*raiz) -> node.score < (*raiz) -> esq -> node.score){
        return rotacaoDireita(*raiz);
    }

    if(fb < -1 && (*raiz) -> node.score > (*raiz) -> dir -> node.score){
        return rotacaoEsquerda(*raiz);
    }

    if(fb > 1 && (*raiz) -> node.score > (*raiz) -> esq -> node.score){
        (*raiz) -> esq = rotacaoEsquerda(*raiz);
        return rotacaoDireita(*raiz);
    }

    if( fb < -1 && (*raiz) -> node.score < (*raiz) -> dir -> node.score){
        (*raiz) -> dir = rotacaoDireita(*raiz);
        return rotacaoEsquerda(*raiz);
    }

    return true;

}


bool * arv_busca(tree* raiz , int score){
    if(raiz == NULL) return false;

    else if(raiz -> node.score == score){
        printf("Node encontrado %d", raiz -> node.score);
        return true;
    }

    else if(raiz -> node.score < score){
        return arv_busca(raiz -> esq , score);
    }

    else{
        return arv_busca(raiz -> dir , score);
    }

    printf("NÓ NÃO ENCONTRADO");
    return false;
}

bool arv_vazia(tree *raiz){
    return raiz == NULL ? true : false;
}


void arv_libera(tree * raiz){
    if(raiz == NULL) return;

    arv_libera(raiz -> esq);
    arv_libera(raiz -> dir);
    free(raiz);
}

void imprimeOrdem(tree * raiz){
    if(raiz == NULL) return;

    imprimeOrdem(raiz -> esq);
    printf("Nome: %s , Idade: %d , Score: %d", raiz -> node.name , raiz -> node.age , raiz -> node.score);
    imprimeOrdem(raiz -> dir);
}

void imprimePreOrdem(tree * raiz){
    if(raiz == NULL) return;

    printf("Nome: %s , Idade: %d , Score: %d", raiz -> node.name , raiz -> node.age , raiz -> node.score);
    imprimePreOrdem(raiz -> esq);
    imprimePreOrdem(raiz -> dir);
}

int arv_altura(tree *raiz){
    if(raiz == NULL){
        return -1;
    }

    int h1 = arv_altura(raiz -> esq);
    int h2 = arv_altura(raiz -> dir);

    return h1 > h2 ? h1 + 1 : h2 + 1;
}

int max (int a , int b){
    return a > b ? a : b;
}

int fatorBalanceamento(tree * raiz){
    if(raiz == NULL ) return 0;

    return arv_altura(raiz -> esq) - arv_altura(raiz -> dir);
    // ou retornava a altura de cada no e fazia o max e retornava o maior 
}
