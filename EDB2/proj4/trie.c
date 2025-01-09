#include "trie.h"


//Revisar aqui
Trie * criaNo(){
    Trie *no = (Trie *) malloc(sizeof(Trie));

    if(no == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    no -> folha = false; //não folha
    for(int i = 0 ; i < TAM_ALFABETO ; i++){
        no -> filhos[i] = NULL; //todos as letras ou filhos como nones
    }

    return no;
}

//retornar palavra na trie
char * verificaTrie(Trie * raiz , char * palavra){
    if (raiz == NULL){
        printf("Trie vazia\n");
        return NULL;
    }

    Trie * aux = raiz;

    for(int i = 0; i < strlen(palavra); i++){
        int index = palavra[i] - 'a'; //varrendo as palavras

        if(aux -> filhos[index] == NULL){
            return NULL; //caminho inexistente -> proxima letra não existe
        }

        aux = aux -> filhos[index]; //pula para a proxima letra
    }

    if(aux != NULL && aux -> folha) {return palavra; } //lambda

    return NULL;
}

//Boleano para o retorno da trie
//mesmo código de cima sendo que para bool
bool buscaTrie(Trie * raiz , char * palavra){
    if(raiz == NULL){
        printf("Trie vazia\n");
        return false;
    }

    Trie * aux = raiz;

    for(int i = 0 ; i < strlen(palavra); i++){
        int idx = palavra[i] - 'a';

        if(aux -> filhos[idx] == NULL){
            printf("Palavra nao encontrada\n");
            return false; //letra não encontrada
        }
        aux = aux -> filhos[idx]; //pula para o próximo
    }

    return aux != NULL && aux -> folha; //diferente pattern
}


//inspirado na BStree
void liberaTrie(Trie * raiz){
    if(raiz == NULL) return;

    for(int i = 0 ; i < TAM_ALFABETO ; i++){
        if (raiz -> filhos[i] != NULL){
            liberaTrie(raiz -> filhos[i]);
        }
    }
    free(raiz);
}

void insereTrie(Trie * raiz , char * palavra){
    if (raiz == NULL){ //ainda precisa?
        printf("Trie vazia\n");
        criaNo(palavra);
        return;
    }

    Trie * aux = raiz;

    for(int i = 0 ; i < strlen(palavra) ; i++){
        int idx = palavra[i] - 'a'; //qual o motivo disso?

        if(aux -> filhos[idx] == NULL){
            aux -> filhos[idx] = criaNo(palavra);
        }
        aux = aux -> filhos[idx];
    }
    aux -> folha = true;

}

//quase a mesma coisa de verificaTrie
void imprimeTrie(Trie * raiz , char * palavra , int pos){
    if (raiz == NULL){
        printf("Trie vazia\n");
        return;
    }

    if(raiz -> folha){
        palavra[pos] = '\0'; //fim da linha
        printf("%s\n", palavra);
    }

    for(int i = 0 ; i < TAM_ALFABETO ; i++){
        if(raiz -> filhos[i] != NULL){
            palavra[pos] = 'a' + i; //varrendo o alfabeto
            imprimeTrie(raiz -> filhos[i] , palavra , pos + 1); //recursive
        }
    }
}
