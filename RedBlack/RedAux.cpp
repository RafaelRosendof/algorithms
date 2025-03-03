#include <cstddef>
#include <iostream>
#include "RedBlack.hpp"
#include <algorithm>
#include <memory>


Tree::Tree() : raiz(nullptr) {}
Tree::~Tree(){}

std::shared_ptr<Node> arv_CriaArv(){
    return nullptr;
}

bool arv_Vazia(std::shared_ptr<Node> raiz){
    return raiz == nullptr ? true : false;
}

void arv_ImprimeNode(std::shared_ptr<Node> no){
    if( no != nullptr){
        std::cout << "Code: " << no->getCode() << " Score: " << no -> getScore() << " \n "<<
        "Nome: " << no->getNome() << " Cor: " << no->getColor() << std::endl;
    }
}

void arv_ImprimeOrdem(std::shared_ptr<Node> raiz){
    if (raiz != nullptr){
        arv_ImprimeOrdem(raiz -> getEsq());
        arv_ImprimeNode(raiz);
        arv_ImprimeOrdem(raiz -> getDir());
    }
}

void arv_ImprimePosOrdem(std::shared_ptr<Node> raiz){
    if (raiz != nullptr){
        arv_ImprimePosOrdem(raiz -> getEsq());
        arv_ImprimePosOrdem(raiz -> getDir());
        arv_ImprimeNode(raiz);
    }
}

std::shared_ptr<Node> arv_buscaArv(std::shared_ptr<Node> raiz , int code){
    if(raiz -> getCode() == code || raiz == nullptr){
        return raiz;
    }

    if(raiz -> getEsq() != nullptr && raiz -> getEsq() -> getCode() > code){
        return arv_buscaArv(raiz -> getEsq() , code);
    }

    else if(raiz -> getDir() != nullptr && raiz -> getDir() -> getCode() < code){
        return arv_buscaArv(raiz -> getDir(),  code);
    }

    return raiz;

}
