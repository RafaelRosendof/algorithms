#include <cmath>
#include <cstddef>
#include <iostream>
#include "RedBlack.hpp"
#include <algorithm>
#include <memory>


Tree::Tree() : raiz(nullptr) {}
Tree::~Tree(){}

std::shared_ptr<Node> Tree::arv_CriarArv(){
    return nullptr;
}

bool Tree::arv_Vazia(std::shared_ptr<Node> raiz){
    return raiz == nullptr ? true : false;
}

void Tree::arv_ImprimeNode(std::shared_ptr<Node> no){
    if( no != nullptr){
        std::cout << "Code: " << no->getCode() << " Score: " << no -> getScore() << " \n "<<
        "Nome: " << no->getNome() << " Cor: " << no->getColor() << std::endl;
    }
}

void Tree::arv_ImprimeOrdem(std::shared_ptr<Node> raiz){
    if (raiz != nullptr){
        arv_ImprimeOrdem(raiz -> getEsq());
        arv_ImprimeNode(raiz);
        arv_ImprimeOrdem(raiz -> getDir());
    }
}

void Tree::arv_ImprimePosOrdem(std::shared_ptr<Node> raiz){
    if (raiz != nullptr){
        arv_ImprimePosOrdem(raiz -> getEsq());
        arv_ImprimePosOrdem(raiz -> getDir());
        arv_ImprimeNode(raiz);
    }
}

std::shared_ptr<Node> Tree::arv_buscaArv(std::shared_ptr<Node> raiz , int code){
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

std::shared_ptr<Node> Tree::arv_CriaNode(Node no){

    return std::make_shared<Node>(no.getCode() , no.getScore() , no.getNome(), no.getColor());
}

void Tree::rotationLeft(std::shared_ptr<Node> raiz,std::shared_ptr<Node> no){
    auto y = no -> getDir();

    if (!y) return;

    no -> setDir(y -> getEsq());

    if (y -> getEsq()){ y -> getEsq() -> setPai(no);}

    if (auto pai = no -> getPai().lock()){
       y -> setPai(pai);

       if( no == pai -> getEsq()){
           pai -> setEsq(y);
       } else{
           pai -> setDir(y);
       }
    } else {
        y -> setPai(std::weak_ptr<Node>());
    }

    y -> setEsq(no);
    no -> setPai(y);
}

void Tree::rotationRigth(std::shared_ptr<Node> raiz,std::shared_ptr<Node> no){

    auto y = no -> getEsq();

    if (!y) return;

    no -> setEsq(y -> getDir());

    if( y -> getDir()){ y -> getDir() -> setPai(no);}

    if(auto pai = no -> getPai().lock()){
        y -> setPai(pai);

        if( no == pai -> getEsq()){
            pai -> setEsq(y);
        }else {
            pai -> setDir(y);
        }
    } else{
        y -> setPai(std::weak_ptr<Node>());
    }

    y -> setDir(no);
    no -> setPai(y);
}

void Tree::transplant(std::shared_ptr<Node> raiz ,std::shared_ptr<Node> u , std::shared_ptr<Node> v){
    auto paiU = u -> getPai().lock();
    if(!paiU){
       raiz = v;
    }

    else if ( u == paiU -> getEsq()){
        paiU -> setEsq(v);
    }

    else{
        paiU -> setDir(v);
    }

    if (!v){
        v -> setPai(paiU);
    }
}


std::shared_ptr<Node> Tree::minimum(std::shared_ptr<Node> node){

    if(node -> getEsq() == nullptr){
        return node;
    }

   return minimum(node -> getEsq());
}

int Tree::arv_Altura(std::shared_ptr<Node> raiz){

    if(raiz == nullptr){
        return 0;
    }

    auto alt1 = arv_Altura(raiz -> getEsq());
    auto alt2 = arv_Altura(raiz -> getDir());

    if( alt1 > alt2){
        return alt1 + 1;
    }

    return alt2 + 1;
}

void Tree::arv_InsereRB(std::shared_ptr<Node> &raiz , std::shared_ptr<Node> no){
    if(raiz == nullptr){ //primeiro caso
        no -> setCor(BLACK);
        raiz = no;
        return;
    }

    std::shared_ptr<Node> y = nullptr;

    auto x = raiz;

    while(x != nullptr){
        y = x;

        if( no -> getScore() < x -> getScore()){
           x = x -> getEsq();
        } else{
            x = x -> getDir();
        }
    }

    no -> setPai(y);

    if( y == nullptr){
        raiz = no;
    }
    if( no -> getScore() < y -> getScore()){
        y -> setEsq(no);
    }else{
        y -> setDir(no);
    }

    no -> setEsq(nullptr);
    no -> setDir(nullptr);
    no -> setCor(RED);

    cor_Insert(raiz, no); // precisa da referência da arvore ou raiz?
}

void Tree::cor_Insert(std::shared_ptr<Node> &raiz ,std::shared_ptr<Node> node){

}

void Tree::arv_Remove(std::shared_ptr<Node> &raiz , int codigo){

}

void Tree::cor_Remove(std::shared_ptr<Node> &raiz,std::shared_ptr<Node> no){

}
