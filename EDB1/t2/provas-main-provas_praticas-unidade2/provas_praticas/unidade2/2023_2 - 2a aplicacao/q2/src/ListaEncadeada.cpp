//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "ListaEncadeada.h"
#include "No.h"
#include <iostream>
#include <string>
#include <sstream>

ListaEncadeada::ListaEncadeada()
{
    this->inicio = nullptr;
}

ListaEncadeada::~ListaEncadeada()
{
    // To-Do
}

void ListaEncadeada::inserirNoInicio(int e){auto n = new No<int>(e);if( inicio == nullptr ) inicio = n;else { n->setProximo( inicio );inicio = n;}}

int ListaEncadeada::removerRepetidos()
{
    int removidos = 0;
    if(inicio == nullptr || inicio->getProximo() == nullptr)
    {
        return 0;
    }

    auto aux = inicio;

    while(aux -> getProximo() != nullptr){
        auto aux2 = aux -> getProximo();

        if(aux -> getValor() == aux2 -> getValor()){
            aux -> setProximo(aux2 -> getProximo());
            delete aux2;
            removidos++;
        }
        else{
            aux = aux -> getProximo();
        } 
    }
    return removidos;
}

No<int>* ListaEncadeada::getInicio()
{
    return this->inicio;
}

std::string ListaEncadeada::imprimir()
{
    std::stringstream resultado;
    
    auto no = this->getInicio();

    while(no != nullptr)
    {
        resultado << no->getValor() << "->" ;
        no = no->getProximo();
    }
    resultado << "null";

    return resultado.str();
}

