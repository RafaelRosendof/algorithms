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

HashTable::HashTable(const unsigned long size)
{
    this -> size = size;
    this -> quantity = 0;
    this -> data = new HashEntry<string , string>*[size];

    for(unsigned long i = 0 ; i < size ; i++){
        this -> data[i] = nullptr;
    }
}

HashTable::~HashTable()
{
    for(unsigned long i = 0 ; i < this -> size ; i++){
        if(this -> data[i] != nullptr && this -> data[i] != ENTRY_DELETED){
            delete this -> data[i];
        }
    }
    delete[] this -> data;
}

/**
 Este método deve inserir na tabela um novo HashEntry com 'key' e 'value' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um HashEntry com atributo 'key' == parâmetro 'key', deve apenas atualizar o atributo 'value' do HashEntry. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
/*
bool HashTable::put(const string key, const string value)
{
    unsigned long index = hash(key);
    unsigned long origin = index;

    while (this -> data[index] != nullptr && this -> data[index] != ENTRY_DELETED ){
        if(this -> data[index] -> getKey() == key){
            this -> data[index] -> setValue(value);
            return true;
        }
        index = (index + 1) % this -> size;
        if(index == origin){
            return false;
        }
    }

    this -> data[index] = new HashEntry<string , string> (key , value);
    this -> quantity++;
    return true;
}
*/
/**
 Este método deve remover da tabela o HashEntry cujo atributo 'key' == parâmetro 'key'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um HashEntry com atributo 'key' == parâmetro 'key',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */

//método correto!!!!!
bool HashTable::put(const string key, const string value)
{
    unsigned long hashIndex = hash(key);
    unsigned long origin = hashIndex;
    int deletedIndex = -1;

    while (this->data[hashIndex] != nullptr) {
        if (this->data[hashIndex] == ENTRY_DELETED) {
            // Marcar a primeira posição deletada encontrada
            if (deletedIndex == -1) {
                deletedIndex = hashIndex;
            }
        } else if (this->data[hashIndex]->getKey() == key) {
            // Atualiza o valor se a chave já existir
            this->data[hashIndex]->setValue(value);
            return true; // Retorna true se a atualização foi feita
        }

        hashIndex = (hashIndex + 1) % this->size;

        // Se voltarmos à posição original, saímos do loop
        if (hashIndex == origin) {
            break;
        }
    }

    // Se encontramos uma posição deletada, usamos ela
    if (deletedIndex != -1) {
        hashIndex = deletedIndex;
    } else if (this->data[hashIndex] != nullptr) {
        // Se não encontramos espaço livre, a tabela está cheia
        return false;
    }

    // Inserir novo item na tabela
    this->data[hashIndex] = new HashEntry(key, value);
    this->quantity++;
    return true; // Retorna true se a inserção foi feita
}


bool HashTable::remove(const string key)
{

    unsigned long hashIndex = hash(key);
    unsigned long origin = hashIndex;

    while(this -> data[hashIndex] != nullptr){
        if(this -> data[hashIndex] != ENTRY_DELETED && this -> data[hashIndex] -> getKey() == key){
            delete this->data[hashIndex];
            this -> data[hashIndex] = ENTRY_DELETED;
            this -> quantity--;
            return true;
        }
        hashIndex = (hashIndex + 1) % this -> size;

        if(hashIndex == origin){
            return false;
        }
    }

    return false;
}


/***
 
 NÃO MUDE QUALQUER FUNÇÃO DAQUI PARA BAIXO
 
 ***/

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
