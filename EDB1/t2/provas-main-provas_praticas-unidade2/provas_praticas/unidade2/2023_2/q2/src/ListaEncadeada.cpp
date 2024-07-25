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

bool ListaEncadeada::remover(std::string val)

//check if the list is empty, if it is, return false
//check if the first element is the one to be removed, if it is, remove it and return true
//if the element is not the first, iterate over the list until the element is found
//if the element is found, remove it and return true

{
    if (this->inicio == nullptr) {
        return false; // List is empty, nothing to remove
    }

    if (this->inicio->getValor() == val) {
        auto temp = this->inicio;
        this->inicio = this->inicio->getProximo();
        delete temp;
        --quantidade;
        return true; // Element removed successfully
    }

    auto current = this->inicio;
    while (current->getProximo() != nullptr) {
        if (current->getProximo()->getValor() == val) { //todo: draw this on the papper to understand better 
            auto temp = current->getProximo();
            current->setProximo(temp->getProximo());
            delete temp;
            --quantidade;
            return true; // Element removed successfully
        }
        current = current->getProximo(); //iterate over the list until the element is found
    }

    return false; // Element not found in the list
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

