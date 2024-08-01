//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "ListaEncadeada.h"
#include "No.h"
#include <iostream>
#include <string>
#include <stack>

ListaEncadeada::ListaEncadeada()
{
    this->inicio = nullptr;
    this->quantidade = 0;
}

ListaEncadeada::~ListaEncadeada()
{
    // To-Do
}

void ListaEncadeada::inserirNoInicio(std::string elemento)
{
    ++this->quantidade;
    auto novo = new No<std::string>(elemento);
    if( this->inicio == nullptr )
    {
        this->inicio = novo;
    }
    else
    {
        novo->setProximo( this->inicio );
        this->inicio = novo;
    }
}

bool  ListaEncadeada::e_simetrica()
{
    if(inicio == nullptr || inicio -> getProximo() == nullptr){
        return true;
    }
    std::stack<std::string> pile;

    auto aux = inicio;
    for(int i =0 ; i < quantidade/2 ; i++){
        pile.push(aux ->getValor());
        aux = aux -> getProximo();
    }

    if(quantidade % 2 != 0){
        aux = aux -> getProximo();
    }

    while(aux != nullptr){
        if(pile.top() != aux -> getValor()){
            return false;
        }
        else{
            pile.pop();
            aux = aux -> getProximo();
        }
    }
    return true;
}



/*
    if(inicio == nullptr || inicio -> getProximo() == nullptr){
        return true;
    }
    std::stack<std::string> pilha;
    auto aux = inicio;

    for(int i = 0 ; i < quantidade/2 ; i++){
        pilha.push(aux -> getValor());
        aux = aux -> getProximo();
    }

    if(quantidade % 2 != 0){
        aux = aux -> getProximo();
    }

    while(aux != nullptr){
        if(pilha.top() != aux ->getValor()){
            return false;
        }
        pilha.pop();
        aux = aux -> getProximo();
    }

    return true;
*/
bool ListaEncadeada::vazia()
{
    return this->inicio == nullptr;
}

int ListaEncadeada::tamanho()
{
    return this->quantidade;
}

No<std::string>* ListaEncadeada::getInicio()
{
    return this->inicio;
}

void ListaEncadeada::imprimir()
{
    if(this->tamanho() > 0 )
    {
        auto no = this->getInicio();

        std::cout << "\t{";
        while(no != nullptr)
        {
            std::cout << no->getValor() << ", " ;
            no = no->getProximo();
        }
        std::cout << "}" << std::endl;
    }
}

