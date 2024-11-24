//#include "functions.c"
#include "headers.h"


int main(){

    const char *arquivo = "dados.csv";
    Arvore *raiz = NULL;

    raiz = carregarCSV(arquivo, raiz);

    arvore_imprimeOrdem(raiz);

    printf("\n\n");

    arvore_imprimePreOrdem(raiz);

    printf("\n\n");

    arvore_imprimePosOrdem(raiz);


    arvore_pertence(raiz, 1);
    arvore_pertence(raiz, 10);

    printf("\n\n");
    printf("Altura da arvore = %d\n", arvore_altura(raiz));

    printf("\n\n");

    arvore_buscaPorGenero(raiz, "Terror");
    arvore_buscaPorGenero(raiz, "Romance");

    removeNo(&raiz, 10);
    removeNo(&raiz, 11);
    removeNo(&raiz, 12);

    printf("\n\n");
    
    arvore_imprimeOrdem(raiz);

    printf("\n\n");

    arvore_imprimePreOrdem(raiz);

    printf("\n\n");

    arvore_imprimePosOrdem(raiz);
    return 0;
}

