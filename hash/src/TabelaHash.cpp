//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

using namespace std;

Par<std::string, std::string> *REMOVIDO = (Par<std::string,std::string>*)(-1);

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
    this->tabela = new Par<std::string, string>*[ this->getTamanho() ];
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
        Par<string, string>* entry = this->tabela[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] tabela;
}

/**
 Este método deve inserir na tabela um novo Par com 'chave' e 'valor' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um Par com atributo 'chave' == parâmetro 'chave', deve apenas atualizar o atributo 'valor' do Par. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool TabelaHash::inserir(const string chave, const string valor)
{
    return false;
}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
    return "NÃO ACHOU";
}

/**
 Este método deve remover da tabela o Par cujo atributo 'chave' == parâmetro 'chave'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um Par com atributo 'chave' == parâmetro 'chave',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool TabelaHash::remover(const string chave)
{
    return false;
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

void TabelaHash::redimensionar(std::size_t tamanhoNovo)
{
    
}

std::size_t TabelaHash::preHash(const string chave)
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

std::size_t TabelaHash::hash(const string chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(std::size_t tamanhoNovo)
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

bool TabelaHash::verificarDuplicatas()
{
    
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->tabela[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->tabela[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        Par<string, string> * entry = tabela[i];
        if( entry == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getChave() << ":" << entry->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
