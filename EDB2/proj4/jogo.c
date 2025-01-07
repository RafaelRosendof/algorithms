#include "jogo.h"
#include "trie.h"
#include "avl.h"

/*
ler tabuleiro -> file.txt 
ler palavras -> file.txt

buscar_palavras 
imprimir resultados (palavras encontradas e armazenadas na AVL)
*/

tree * raizAVL = NULL;
tree * raizTrie = NULL; 

void iniciar_arvores(){
    raizAVL = arv_criaVazia();
    raizTrie = criaNo();
}

void inserir_palavraTrie(char * palavra){
    insereTrie(raizTrie , palavra); //colocar a insereTrie como tree ou mudar a lógica aqui 
}

//INCOMPLETO -> FALTA VALIDAR NA TRIE 
//Somente caso seja validado na trie
void inserir_palavraAVL(char * palavra){
    No node;
    strcpy(node.palavra , palavra);
    raizAVL = arv_insereAVL(raizAVL , palavra);
}

bool ler_palavras(char * file){
    FILE * arq = fopen(file , "r");

    if(!arq){
        printf("Erro ao abrir o arquivo das palavras\n");
        return false;
    }

    char linha[1000];
    while(fgets(linha , sizeof(linha) , arq)){
        char palavra[100];
        sscanf(linha , "%s" , palavra);
        //insere_palavra(palavra);
        inserir_palavraTrie(palavra);
    }

    fclose(arq);

    return true;
}

bool ler_tabuleiro(char * file){
    FILE * arq = fopen(file , "r");

    if(!arq){
        printf("Erro ao abrir o arquivo do tabuleiro\n");
        return false;
    }

    char linha[1000];
    int i = 0;

    while(fgets(linha , sizeof(linha) , arq)){
        for(int j = 0 ; j < strlen(linha) ; j++){
            if(linha[j] != '\n'){
                tabuleiro[i][j] = linha[j];
            }
        }
        i++;
    }

    fclose(arq);

    return true;
}


void imprimir_resultados(){
    imprimeAlfabetico(raizAVL);
}

void fluxoJogo(char * tabuleiro , char * palavras){

    ler_palavras(palavras);
    ler_tabuleiro(tabuleiro);

    iniciar_arvores();

    buscar_palavras(raizTrie , tabuleiro);

    imprimir_resultados();

}