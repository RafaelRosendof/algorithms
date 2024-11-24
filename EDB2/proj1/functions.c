#include "headers.h"

typedef struct No No;
typedef struct Arvore Arvore;

Arvore *arvore_criaVazia() {
    return NULL;
}

bool arv_vazia(Arvore *arv) {
    return (arv == NULL) ? true : false;
}

Arvore *arv_criaNo(No livro) {
    Arvore *novo_no = (Arvore *)malloc(sizeof(Arvore));

    if (novo_no == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }

    novo_no -> livro = livro;
    novo_no -> esq = NULL;
    novo_no -> dir = NULL;
    novo_no -> num_filhos = 0;
    
    return novo_no;
}


void arvore_libera(Arvore *raiz){

    if (raiz == NULL) { return; }

    arvore_libera(raiz -> esq);
    arvore_libera(raiz -> dir);

    free(raiz);
}

Arvore *arvore_insere(Arvore *raiz , No livro){
    if(raiz == NULL){
        return arv_criaNo(livro);
    }

    if(livro.codigo < raiz -> livro.codigo){
        raiz -> esq = arvore_insere(raiz -> esq , livro);
    }
    else if(livro.codigo > raiz -> livro.codigo){
        raiz -> dir = arvore_insere(raiz -> dir , livro);
    }
    else{
        printf("Livro já cadastrado código = %d \n \n" , livro.codigo);
    }

    return raiz;
}

Arvore *arvore_busca(Arvore *raiz , int codigo){
    if(raiz == NULL || raiz -> livro.codigo == codigo){ return raiz; }

    if(codigo < raiz -> livro.codigo){
        return arvore_busca(raiz -> esq , codigo);
    }

    return arvore_busca(raiz -> dir , codigo);
}

void arvore_imprimeOrdem(Arvore *raiz){
    if(raiz == NULL){return;}

    arvore_imprimeOrdem(raiz -> esq);
    printf("Codigo: %d , Titulo : %s , Autor : %s , Genero : %s , Ano : %d , Editora : %s , NumPaginas : %d \n" , raiz -> livro.codigo , raiz -> livro.titulo , raiz -> livro.autor , raiz -> livro.genero , raiz -> livro.ano , raiz -> livro.editora , raiz -> livro.numPaginas);
    arvore_imprimeOrdem(raiz -> dir);
}

void arvore_imprimePreOrdem(Arvore *raiz){
    if(raiz == NULL){return;}

    printf("Codigo: %d , Titulo : %s , Autor : %s , Genero : %s , Ano : %d , Editora : %s , NumPaginas : %d \n" , raiz -> livro.codigo , raiz -> livro.titulo , raiz -> livro.autor , raiz -> livro.genero , raiz -> livro.ano , raiz -> livro.editora , raiz -> livro.numPaginas);
    arvore_imprimePreOrdem(raiz -> esq);
    arvore_imprimePreOrdem(raiz -> dir);
}

void arvore_imprimePosOrdem(Arvore *raiz){
    if(raiz == NULL){return;}

    arvore_imprimePosOrdem(raiz -> esq);
    arvore_imprimePosOrdem(raiz -> dir);
    printf("Codigo: %d , Titulo : %s , Autor : %s , Genero : %s , Ano : %d , Editora : %s , NumPaginas : %d \n" , raiz -> livro.codigo , raiz -> livro.titulo , raiz -> livro.autor , raiz -> livro.genero , raiz -> livro.ano , raiz -> livro.editora , raiz -> livro.numPaginas);
}


void arvore_buscaPorGenero(Arvore *raiz , const char genero[]){
    if (raiz == NULL) {
        return;
    }

    if (strcmp(raiz->livro.genero, genero) == 0) {
        printf("Livro encontrado:\n");
        printf("Código: %d\n", raiz->livro.codigo);
        printf("Título: %s\n", raiz->livro.titulo);
        printf("Autor: %s\n", raiz->livro.autor);
        printf("Gênero: %s\n", raiz->livro.genero);
        printf("Ano: %d\n", raiz->livro.ano);
        printf("Editora: %s\n", raiz->livro.editora);
        printf("Número de Páginas: %d\n\n", raiz->livro.numPaginas);
    }

    arvore_buscaPorGenero(raiz->esq, genero);
    arvore_buscaPorGenero(raiz->dir, genero);
}

bool arvore_pertence(Arvore * raiz , int codigo){
    if(raiz == NULL){return false;}

    if(raiz -> livro.codigo == codigo){
        printf("Livro encontrado\n");
        return true;
    }

    if(codigo < raiz -> livro.codigo){
        return arvore_pertence(raiz -> esq , codigo);
    }

    else{
        return arvore_pertence(raiz -> dir , codigo);
    }

}

int arvore_altura(Arvore *raiz){
    if(raiz == NULL){return 0;}

    int hh = 0;

    int h1 = arvore_altura(raiz -> esq);
    int h2 = arvore_altura(raiz -> dir);

    return (h1 > h2) ? h1+1 : h2+1;
}

//ponteiro duplo para alterar o conteúdo 
bool removeNo(Arvore **raiz, int codigo) {
    if (raiz == NULL) {
        printf("Arvore vazia\n");
        return false;
    }
//se for menor que o código do nó atual, vai para a esquerda ou direita caso for maior 
    if(codigo < (*raiz) -> livro.codigo){
        return removeNo(&(*raiz) -> esq , codigo);
    } else if(codigo > (*raiz) -> livro.codigo){
        return removeNo(&(*raiz) -> dir , codigo);
    }
//aqui entra se o código for igual ao código do nó atual
    else{
        //nos sem filhos 
        if((*raiz) -> esq == NULL && (*raiz) -> dir == NULL){
            free(*raiz);
            *raiz = NULL;
            return true;
        }

        //nos com um filho
        if((*raiz) -> esq == NULL || (*raiz) -> dir == NULL){
//vou verificar qual dos dois filhos não é nulo e atribuir a aux
            Arvore *aux = (*raiz) -> esq ? (*raiz) -> esq : (*raiz) -> dir;

            free(*raiz);
            *raiz = aux;
            return true;

        }

        //nos com dois filhos, percorre a arvore até achar o nó mais a esquerda da subarvore da direita
        Arvore *aux = (*raiz) -> dir;
        while(aux -> esq != NULL){
            aux = aux -> esq;
        }
        (*raiz) -> livro = aux -> livro;
        return removeNo(&(*raiz) -> dir , aux -> livro.codigo);
    }

}

Arvore *carregarCSV(const char *nomeArq , Arvore *raiz){
    FILE * arq = fopen(nomeArq , "r");

    if(!arq){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    char linha[1000];
    int first = 1; 

    while(fgets(linha , sizeof(linha) , arq)){
        if(first){ 
            first = 0;
            continue;
        }

        No livro;
        //expressões regulares para pegar os dados do csv
        sscanf(
            linha , "%d,%99[^,],%99[^,],%49[^,],%d,%99[^,],%d",
               &livro.codigo,
               livro.titulo,
               livro.autor,
               livro.genero,
               &livro.ano,
               livro.editora,
               &livro.numPaginas        
        );

        raiz = arvore_insere(raiz , livro);
    }
    fclose(arq);
    return raiz;
}



