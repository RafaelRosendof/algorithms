//
//  HashTable.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "HashTable.h"
#include <string>
#include <iostream>

using namespace std;

HashEntry<std::string, std::string> *ENTRY_DELETED = (HashEntry<std::string,std::string>*)(-1);

HashTable::~HashTable()
{
    for( int i = 0; i < this->getSize(); i++ )
    {
        auto entry = this->data[i];
        
        if( entry != nullptr && entry != ENTRY_DELETED )
        {
            delete entry;
        }
    }
    delete [] data;
}

/**
 Este método deve fazer o reajuste do tamanho do array interno da tabela.

 */
//o teste não funcionou por motivos tecnicos, mas tem uma qustão parecida em 2023_1
void HashTable::resize(const unsigned long newSize)
{
    auto novaTabela = new HashEntry<std::string, std::string>*[newSize];
    //Par<std::string , std::string> *novaTabela;

    for(unsigned long i = 0 ; i < newSize ; i++){
        novaTabela[i] = nullptr;
    }

    for(unsigned long i = 0 ; i < this -> getSize() ; i++){
        HashEntry<std::string, std::string> *entry = this -> data[i];
        if(entry != nullptr && entry != ENTRY_DELETED){
            //calcula o novo indice 
            unsigned long newHash = this -> preHash(entry -> getKey()) % newSize;

            while(novaTabela[newHash] != nullptr){
                newHash = (newHash + 1) % newSize;
            }

            novaTabela[newHash] = entry;
        }
    }

    delete [] this -> data;
    this -> data = novaTabela;
    this -> size = newSize;
    
}
/***
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 !!!!!! NÃO MUDE QUALQUER FUNÇÃO DAQUI PARA BAIXO !!!!!! 
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ***/

HashTable::HashTable(const unsigned long size)
{
    this->size = size;
    this->data = new HashEntry<std::string, string>*[this->getSize()];
    this->quantity = 0;
    for( int i = 0; i < this->getSize(); i++ )
    {
        // Atribui-se nulo às posições da tabela para termos certeza de que estão vazias
        this->data[i] = nullptr;
    }
}

unsigned long HashTable::preHash(const string key)
{
    unsigned long x = 0;
    for(unsigned int i = 0; i < key.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += key.at(i);
    }
    return x;
}

unsigned long HashTable::hash(const string key)
{
    unsigned long hashValue = this->preHash(key);
    return hashValue % this->getSize();
}

unsigned long HashTable::getSize()
{
    return this->size;
}

unsigned long HashTable::getQuantity()
{
    return this->quantity;
}

bool HashTable::isEmpty()
{
    return this->quantity == 0;
}

bool HashTable::isFull()
{
    return this->quantity == this->getSize();
}

void HashTable::print()
{
    for(int i = 0; i < this->getSize(); i++)
    {
        HashEntry<string, string> * entry = data[i];
        if( entry == ENTRY_DELETED )
        {
            std::cout << i << ": DELETED" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getKey() << ":" << entry->getValue() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
