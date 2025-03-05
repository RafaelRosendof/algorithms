#include "header.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <chrono>

//Tree::Tree(const Node &no): no(no), num_filhos(0), esq(nullptr), dir(nullptr){}

//Tree::~Tree(){}

int main(){

//inserir Nodes, remover, buscar , imprimir e retornar altura e afins
//medir tempo de execução

    std::unique_ptr<Tree> raiz = std::make_unique<Tree>(Node(0 , 0 , "", ""));

    auto start = std::chrono::high_resolution_clock::now();


    Node no1(1, 100, "123.456.789-00", "Alice");
    Node no2(2, 50, "987.654.321-00", "Bob");
    Node no3(3, 150, "111.222.333-44", "Charlie");
    Node no4(4, 75, "555.666.777-88", "David");
    Node no5(5, 25, "999.888.777-66", "Eve");

    raiz->arv_insere(raiz.get(), no1);
    raiz -> arv_insere(raiz.get(), no2);
    raiz -> arv_insere(raiz.get(), no3);
    raiz -> arv_insere(raiz.get(), no4);
    raiz -> arv_insere(raiz.get(), no5);

    raiz -> arv_imprimeOrdem(raiz.get());

    std::cout<< "\n\n removido elemento 3" <<std::endl;
    raiz -> arv_removeNode(raiz , 3);

    raiz -> arv_imprimePosOrdem(raiz.get());
    return 0;
}
