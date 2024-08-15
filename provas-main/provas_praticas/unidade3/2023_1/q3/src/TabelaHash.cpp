//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>


/*
//tem um detalhe defeituoso, erro de pointer 
void TabelaHash::redimensionar(const std::size_t& tamanhoNovo)
{
    auto novaTabela = new Par<std::string , std::string>*[tamanhoNovo];

    for(std::size_t i = 0 ; i < tamanhoNovo ; i++)
    {
        novaTabela[i] = nullptr;
    }

    auto tabelaAntiga = this -> tabela;
    auto tamanhoAntigo = this -> getTamanho();

    //novo tamanho;
    this -> setTamanho(tamanhoNovo);

    //iniciando nova tabela
    this -> tabela = novaTabela;
    this -> quantidade = 0;

    //percorrendo e preenchendo a nova tabela
    for(std::size_t i = 0 ; i < tamanhoAntigo ; i++){
        if(tabelaAntiga[i] != nullptr && tabelaAntiga[i]->getChave() != "REMOVIDO"){
            std::string chave = tabelaAntiga[i] -> getChave();
            std::string valor = tabelaAntiga[i] -> getValor();

            auto novoIndice = this -> preHash(chave) % tamanhoNovo;

            //sondagem linear
            while(novaTabela[novoIndice] != nullptr){
                novoIndice = (novoIndice + 1) % tamanhoNovo;
            }

            novaTabela[novoIndice] = new Par<std::string , std::string>(chave , valor);
            this -> quantidade++;

        }
        delete tabelaAntiga[i];
    }
    delete [] tabelaAntiga;
}
*/

void TabelaHash::redimensionar(const std::size_t& tamanhoNovo){
    auto novaTabela = new Par<std::string , std::string>*[tamanhoNovo];

    for(std::size_t i = 0 ; i < tamanhoNovo ; i++){
        novaTabela[i] = nullptr;
    }

    for(unsigned long i = 0 ; i < this -> getTamanho() ; i++){
        auto entry = this -> tabela[i];

        if(entry != nullptr && entry != REMOVIDO){
            std::string chave = entry->getChave();
            //unsigned long newHash = this -> preHash(entry -> getChave()) % tamanhoNovo;
            unsigned long newHash = this->preHash(chave) % tamanhoNovo;

            while(novaTabela[newHash] != nullptr){
                newHash = (newHash + 1) % tamanhoNovo;
            }
            novaTabela[newHash] = entry;
        }
    }

    delete[] this -> tabela;
    this -> tabela = novaTabela;
    this -> tamanho = tamanhoNovo;
}


TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->tabela = new Par<std::string, std::string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->tabela[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        auto entry = this->tabela[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] tabela;
}

float TabelaHash::fatorDeCarga()
{
    return (float)this->getQuantidade() / (float)this->getTamanho();
}

void TabelaHash::aumentar()
{
    std::size_t tamanhoNovo = 2*this->getTamanho() + 1;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::diminuir()
{
    std::size_t metadeTamanho = this->getTamanho()/2;
    std::size_t tamanhoNovo = metadeTamanho % 2 == 0 ? metadeTamanho + 1 : metadeTamanho;
    this->redimensionar(tamanhoNovo);
}

std::size_t TabelaHash::preHash(std::string& chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(std::string& chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(const std::size_t& tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        auto elemento = tabela[i];
        if( elemento == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( elemento != nullptr )
        {
            std::cout << i << ": " << elemento->getChave() << ":" << elemento->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
