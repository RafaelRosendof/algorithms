#ifndef INFO_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Carro Carro;

struct Carro {
    char[50] marca;
    int ano;
    double preco;
    char[50] tipo;
    Arv *esq;
    Arv *dir;
};

Carro *cria_carro(char marca[50], int ano, double preco, char tipo[50]);
Carro cria_arv();
bool arv_vazia(Carro *carro);
void libera(Carro *carro);
bool insere_arv(Carro *carro, Carro c);
void imprime_arvPreOrdem(Carro *carro);
void imprime_arvPosOrdem(Carro *carro);
void imprime_larg(Carro *carro);
bool pertence(Carro *carro, Carro c);
int altura_arv(Carro *carro);
bool remove_node(Carro *carro, Carro c);   

void inserir_lista(char[200] lista);

Carro buscarMarca(Carro *carro, char[50] marca);

/*
1. Implemente a estrutura de dados da ´arvore bin´aria em que cada n´o armazene uma entrada de
autom´ovel com os atributos listados. OK
2. Insira os autom´oveis na ´arvore de acordo com a organiza¸c˜ao em nota¸c˜ao textual.
3. Implemente uma fun¸c˜ao para buscar uma marca espec´ıfica na ´arvore e retornar as informa¸c˜oes do
autom´ovel correspondente.
4. Verifique se a ´arvore est´a organizada conforme o modelo em nota¸c˜ao textual e a representa¸c˜ao
visual.
*/