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
Trie * raizTrie = NULL;

//tabuleiro para ficar mais fácil de acessar
char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE];


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
    //No node;
    //strcpy(node.palavra , palavra);
    raizAVL = arv_insereAVL(raizAVL , palavra);
}

//Copiado dos outros projetos
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
            if(linha[j] != '\n'){ //até o final da linha
                tabuleiro[i][j] = linha[j];
            }
        }
        i++;
    }

    fclose(arq);

    return true;
}

//função de busca
void buscar_Tabu(Trie *raiz, char tabuleiro[TABULEIRO_SIZE][TABULEIRO_SIZE]){
    char palavra[100];
    int linhas = TABULEIRO_SIZE;
    int colunas = TABULEIRO_SIZE;

    for(int i = 0 ; i < linhas ; i++){
        for(int j = 0 ; j < colunas ; j++){
            //percorrido a matriz agora são as diagonais
            for(int Di = -1 ; Di <= 1 ; Di++){
                for(int Dj = -1 ; Dj <= 1 ; Dj++){

                    if(Di == 0 && Dj == 0) continue; // direção estática, caso não tenha movimento

                    int x = i, y = j , pos = 0; // cordenadas iniciais

                    //percorre na direção atual até o limite
                    while(x >= 0 && x < linhas && y >= 0 && y < colunas){
                        palavra[pos++] = tabuleiro[x][y]; //adiciona letras ao buffer
                        palavra[pos] = '\0';//quebrador de palavras

                        if(buscaTrie(raiz , palavra)){
                            inserir_palavraAVL(palavra); //verificando na trie
                        }
                        x += Di; //atualizando
                        y += Dj; //atualizando as coordenadas para a proxima direção
                    }
                }
            }
        }
    }
}

void imprimir_resultados(){
    imprimeAlfabetico(raizAVL);
}

void fluxoJogo(char * arquivoTab , char * arqP){

    iniciar_arvores();           // inicializa AVL e Trie
    ler_palavras(arqP); // carrega palavras na Trie
    ler_tabuleiro(arquivoTab); // carrega tabuleiro

    buscar_Tabu(raizTrie, tabuleiro); // busca palavras no tabuleiro
    imprimir_resultados(); // exibe resultados ordenados pela AVL

    liberaTrie(raizTrie); // libera Trie
    //raizAVL = arv_liberaAVL(raizAVL); // libera AVL

}
