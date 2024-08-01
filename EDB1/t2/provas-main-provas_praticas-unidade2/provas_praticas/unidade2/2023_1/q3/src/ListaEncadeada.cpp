//
//  ListaEncadeada.cpp
//
//

#include "../include/ListaEncadeada.h"
#include "../include/No.h"
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

void  ListaEncadeada::ordenar()
{

    if (inicio == nullptr || inicio->getProximo() == nullptr) {
        return; // Lista vazia ou com um único elemento já está ordenada
    }
    
    //bouble sort 
    for(auto p1 = inicio -> getProximo() ; p1 != nullptr ; p1 = p1 -> getProximo()){
        for(auto p2 = p1 -> getProximo() ; p2 != nullptr ; p2 = p2 -> getProximo()){
            if(p1 -> getValor() > p2 ->getValor()){
                p1 -> setProximo(p2 -> getProximo());
                p2 -> setProximo(p1);
            }
        }
    }
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

bool ListaEncadeada::checarOrdenacao()
{
    if(this->tamanho() == 0 || this->tamanho() == 1)
    {
        return true;
    }

    for(auto no = this->inicio; no->getProximo() != nullptr; no = no->getProximo())
    {
        auto noProx = no->getProximo();

        if(no->getValor() > noProx->getValor())
        {
            return false;
        }
    }
    return true;
}
