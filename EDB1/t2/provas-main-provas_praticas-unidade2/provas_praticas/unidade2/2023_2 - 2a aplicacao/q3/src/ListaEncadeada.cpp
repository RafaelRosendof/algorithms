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

void ListaEncadeada::inverter() {
    auto anterior = nullptr; 
    auto atual = inicio; 
    auto proximo = nullptr; 

    // Ajustar o ponteiro do início para o final da lista
    if (inicio == nullptr) return;  // Lista vazia, nada a fazer
    
    // Continuar até o final da lista
    while (atual != nullptr) {
        // Armazenar o próximo nó
        proximo = atual->getProximo();
        
        // Inverter o ponteiro do nó atual
        atual->setProximo(anterior);
        
        // Avançar os ponteiros
        anterior = atual;
        atual = proximo;
    }
    
    // O ponteiro anterior será o novo início da lista
    inicio->setProximo(nullptr);  // O antigo início se torna o final
    inicio = anterior;
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

