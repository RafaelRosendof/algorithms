//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "ListaEncadeada.h"
#include "No.h"
#include <iostream>
#include <string>

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

bool ListaEncadeada::remover(std::string val){
    if(inicio == nullptr){
        return false;
    }

    if(inicio -> getValor() == val){
        auto temp = inicio;
        inicio = inicio -> getProximo();
        delete temp;
        quantidade--;
        return true;
    }
    auto aux = this -> inicio;

    while(aux -> getProximo() != nullptr){
        if(aux -> getProximo() -> getValor() == val){
          auto temp = aux -> getProximo();
          aux -> setProximo(temp -> getProximo());
          delete temp;
          quantidade--;
          return true;
        }

        aux = aux -> getProximo();
    }

    return false;
}


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

