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

char normalizaCaractere(char c) {
    if (isalpha(c)) { // Verifica se é uma letra
        return tolower(c); // Converte para minúscula
    }
    return '\0'; // Retorna caractere nulo para indicar inválido
}

//retornar palavra na trie
/*
char * verificaTrie(Trie * raiz , char * palavra){
    if (raiz == NULL){
        printf("Trie vazia\n");
        return NULL;
    }

    Trie * aux = raiz;

    for(int i = 0; i < palavra[i] != '\0'; i++){
        //int index = palavra[i] - 'a'; //varrendo as palavras

        if(aux -> filhos[index] == NULL){
            printf("Impossível de capturar");
            return NULL; //caminho inexistente -> proxima letra não existe
        }

        aux = aux -> filhos[index]; //pula para a proxima letra
    }

    if(aux != NULL && aux -> folha) {return palavra; } //lambda

    return NULL;
}
*/
char * verificaTrie(Trie * raiz , char * palavra) {
    if (raiz == NULL) {
        printf("Trie vazia\n");
        return NULL;
    }

    Trie * aux = raiz;

    for (int i = 0; palavra[i] != '\0'; i++) {
        char c = normalizaCaractere(palavra[i]);

        if (c == '\0') { // Caractere inválido
            printf("Caractere inválido encontrado: %c\n", palavra[i]);
            return NULL;
        }

        int index = c - 'a'; // Calcula o índice no alfabeto

        if (aux->filhos[index] == NULL) {
            printf("Caminho inexistente para a letra: %c\n", c);
            return NULL;
        }

        aux = aux->filhos[index];
    }

    if (aux != NULL && aux->folha) {
        return palavra; // Palavra encontrada
    }

    return NULL; // Palavra não encontrada
}


//gcc -O0 -g -o figas jogo.c main.c avl.c trie.c
//gdb ./figas
//Boleano para o retorno da trie

bool buscaTrie(Trie * raiz, char * palavra) {
    if(raiz == NULL) {
        printf("Trie vazia\n");
        return false;
    }

    Trie * aux = raiz;
    for(int i = 0; palavra[i] != '\0'; i++) {
        char c = palavra[i];

        // Ignorar espaços
        if (c == ' ') continue;

        // Converter maiúsculas para minúsculas
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }

        // Verificar se o caractere é válido
        if (c < 'a' || c > 'z') {
            return false; // Caractere não permitido
        }

        int idx = c - 'a';  // Use the normalized character
        if(aux->filhos[idx] == NULL) {
            return false;
        }
        aux = aux->filhos[idx];
    }

    return (aux != NULL && aux->folha);
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
        criaNo();
        return;
    }

    Trie * aux = raiz;

    for(int i = 0 ; i < strlen(palavra) ; i++){
        int idx = palavra[i] - 'a'; //qual o motivo disso?

        if(aux -> filhos[idx] == NULL){
            aux -> filhos[idx] = criaNo();
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
