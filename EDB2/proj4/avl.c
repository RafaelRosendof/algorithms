#include "avl.h"
#include <string.h>


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


tree * arv_criaNo(char palavra[100]){
    tree * novo = (tree*)malloc(sizeof(tree));

    if(novo == NULL) {
        printf("Erro ao alocar memória\n");
        return NULL;
    }
    strcpy(novo->palavra, palavra);
    // novo -> palavra = palavra
    novo -> esq = NULL;
    novo -> dir = NULL;
    novo -> alt = 1;
    novo -> num_filhos = 0;

    return novo;
}


tree * rotacaoDireita(tree * raiz){
    tree * aux = raiz -> esq;

    // A subárvore direita de 'aux' se torna a subárvore esquerda de 'raiz' após a rotação.

    raiz -> esq = aux -> dir;

    aux -> dir = raiz;

    //pega o máximo da raiz e aux
    raiz -> alt = 1 + max(arv_altura(raiz -> esq) , arv_altura(raiz -> dir));
    aux -> alt = 1 + max(arv_altura(aux -> esq) , arv_altura(aux -> dir));

    return aux;
}

tree * rotacaoEsquerda(tree * raiz){
    tree * aux = raiz -> dir;

    // mesma coisa aqui sendo que invertido

    raiz -> dir = aux -> esq;
    aux -> esq = raiz;

    //
    raiz -> alt = 1 + max(arv_altura(raiz -> esq) , arv_altura(raiz -> dir));
    aux -> alt = 1 + max(arv_altura(aux -> esq) , arv_altura(aux -> dir));

    return aux;
}


//mesma coisa aqui porém com a comutação de duas funções
tree * rotacaoDuplaEsquerda(tree * raiz){
    raiz -> dir = rotacaoDireita(raiz -> dir);
    return rotacaoEsquerda(raiz);
}

tree * rotacaoDuplaDireita(tree * raiz){
    raiz -> esq = rotacaoEsquerda(raiz -> esq);
    return rotacaoDireita(raiz);
}

/*

}
*/

//corrigindo erro de leitura
char* normalizaPalavra(const char* original) {
    if (original == NULL) return NULL;


    int len = strlen(original);
    char* normalizada = (char*)malloc(len + 1);
    int j = 0;


    for (int i = 0; original[i] != '\0'; i++) {
        char c = original[i];

        // pula aqui
        if (c == ' ') continue;

        // mesma coisa da trie
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }


        if (c >= 'a' && c <= 'z') {
            normalizada[j++] = c;
        }
    }

    normalizada[j] = '\0';
    return normalizada;
}


tree* arv_insereAVL(tree** raiz, char* palavra) {

    char * palavraN = normalizaPalavra(palavra);
    if(palavraN == NULL) return *raiz;

    if (*raiz == NULL) {  //tem que ser duplo para alterar a raiz
        tree* novo = arv_criaNo(palavraN);
        //tree* novo = arv_criaNo(palavra);
        *raiz = novo;
        free(palavraN);
        return novo;
    }

    int cmp = strcmp(palavraN, (*raiz)->palavra);

    if (cmp < 0) {
        (*raiz)->esq = arv_insereAVL(&((*raiz)->esq), palavraN);
    }
    else if (cmp > 0) {
        (*raiz)->dir = arv_insereAVL(&((*raiz)->dir), palavraN);
    }
    else {
        return *raiz;
    }

    free(palavraN);

    (*raiz)->alt = 1 + max(arv_altura((*raiz)->esq), arv_altura((*raiz)->dir));


    int fb = fatorBalanceamento(*raiz);

    //balanceamento
    if (fb > 1 && strcmp(palavra, (*raiz)->esq->palavra) < 0) {
        *raiz = rotacaoDireita(*raiz);
    }
    else if (fb < -1 && strcmp(palavra, (*raiz)->dir->palavra) > 0) {
        *raiz = rotacaoEsquerda(*raiz);
    }
    else if (fb > 1 && strcmp(palavra, (*raiz)->esq->palavra) > 0) {
        (*raiz)->esq = rotacaoEsquerda((*raiz)->esq);
        *raiz = rotacaoDireita(*raiz);
    }
    else if (fb < -1 && strcmp(palavra, (*raiz)->dir->palavra) < 0) {
        (*raiz)->dir = rotacaoDireita((*raiz)->dir);
        *raiz = rotacaoEsquerda(*raiz);
    }

    return *raiz;
}

//ta dando erro de inserir, função para debugar o inserir
void auxiliar(tree* raiz, int level) {
    if (raiz == NULL) return;

    auxiliar(raiz->dir, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }
    printf("%s (h:%d, fb:%d)\n", raiz->palavra, arv_altura(raiz), fatorBalanceamento(raiz));

    auxiliar(raiz->esq, level + 1);
}


char * arv_busca(tree * raiz , char *palavra){
    if (raiz == NULL){
        return NULL;
    }
//deu match
    if (strcmp(raiz -> palavra , palavra) == 0){
        return raiz->palavra;
    }
//recursivo e palavra menor que a raiz
    else if(strcmp(raiz -> palavra , palavra) > 0){
        return arv_busca(raiz -> esq , palavra);
    }
//recursivo e palavra maior que a raiz
    else{
        return arv_busca(raiz -> dir , palavra);
    }

    printf("NÓ NÃO ENCONTRADO");

}

int arv_altura(tree* raiz) {
    if (raiz == NULL) {
        return 0;  // altura da árvore vazia e incrementando corretamente a altura
    }
    return 1 + max(arv_altura(raiz->esq), arv_altura(raiz->dir));
}

/*
//mesma coisa da BStree
int arv_altura(tree * raiz){
    if (raiz == NULL){
        return -1;
    }

    int h1 = arv_altura(raiz -> esq);
    int h2 = arv_altura(raiz -> dir);

    return (h1 > h2) ? h1 + 1 : h2 + 1;
}
*/

int max(int a , int b){ return a > b ? a : b;}

int fatorBalanceamento(tree * raiz){
    if (raiz == NULL){
        return 0;
    }
    //altura da esquerda - altura da direita
    return arv_altura(raiz -> esq) - arv_altura(raiz -> dir);
}

//cópia da BStree
void arv_libera(tree * raiz){
    if (raiz == NULL) return;

    arv_libera(raiz -> esq);
    arv_libera(raiz -> dir);

    free(raiz);
}

//cópia da BStree sendo que para str
void imprimeAlfabetico(tree * raiz){
    if (raiz == NULL) return;

    imprimeAlfabetico(raiz -> esq);
    printf("%s\n" , raiz -> palavra);
    imprimeAlfabetico(raiz -> dir);
}


//cópia da BStree porém com balanceamento
bool arv_removeAVL(tree **raiz , char * palavra){

    if (*raiz == NULL){
        printf("Árvore vazia, nada a remover\n");
        return false;
    }

    if(strcmp(palavra, (*raiz)->palavra) < 0){
        return arv_removeAVL(&(*raiz)->esq, palavra);
    }
    else if(strcmp(palavra, (*raiz)->palavra) > 0){
        return arv_removeAVL(&(*raiz)->dir, palavra);
    }
    else {
        // Nó folha
        if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
            free(*raiz);
            *raiz = NULL;
            return true;
        }

        // Nó com um filho
        if((*raiz)->esq == NULL || (*raiz)->dir == NULL){
            tree *aux = (*raiz)->esq ? (*raiz)->esq : (*raiz)->dir;
            free(*raiz);
            *raiz = aux;
            return true;
        }

        // Nó com dois filhos
        tree *aux = (*raiz)->dir;
        while(aux->esq != NULL){
            aux = aux->esq;
        }

        strcpy((*raiz)->palavra, aux->palavra);
        return arv_removeAVL(&(*raiz)->dir, aux->palavra);
    }

    //Copiado da inserção!!! -> lembrar de fazer o ponteiro para a raiz argumento é ponteiro duplo
    // Atualiza altura
    (*raiz)->alt = 1 + max(arv_altura((*raiz)->esq), arv_altura((*raiz)->dir));

    int fb = fatorBalanceamento(*raiz);

    // Rotação para balanceamento
    if (fb > 1 && fatorBalanceamento((*raiz)->esq) >= 0) {
        *raiz = rotacaoDireita(*raiz);
    }
    else if (fb > 1 && fatorBalanceamento((*raiz)->esq) < 0) {
        *raiz = rotacaoDuplaDireita(*raiz);
    }
    else if (fb < -1 && fatorBalanceamento((*raiz)->dir) <= 0) {
        *raiz = rotacaoEsquerda(*raiz);
    }
    else if (fb < -1 && fatorBalanceamento((*raiz)->dir) > 0) {
        *raiz = rotacaoDuplaEsquerda(*raiz);
    }

    return true;
}
