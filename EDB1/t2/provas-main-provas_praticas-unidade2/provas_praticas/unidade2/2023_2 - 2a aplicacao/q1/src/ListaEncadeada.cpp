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
    this->quantidade = 0;
}

ListaEncadeada::~ListaEncadeada(){}

void ListaEncadeada::inserirNoInicio(int e){auto n = new No<int>(e);if( inicio == nullptr ) inicio = n;else { n->setProximo( inicio );inicio = n;} this->quantidade++;}

void ListaEncadeada::rotacionar(int x)
{

    //caso base 
    if (inicio == nullptr || x <= 0 || inicio->getProximo() == nullptr) {
        return;
    }

    x = x % quantidade;
    if(x == 0)
    {
        return;
    }

    auto aux = inicio;
    for(int i = 0 ; i < quantidade - x - 1; i++)
    {
        aux = aux -> getProximo();
    }

    auto aux2 = aux -> getProximo();

    auto ultimo = aux2;

    while(ultimo -> getProximo() != nullptr){
        ultimo = ultimo -> getProximo();
    }
    ultimo -> setProximo(inicio);

    aux -> setProximo(nullptr);

    inicio = aux2;

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

