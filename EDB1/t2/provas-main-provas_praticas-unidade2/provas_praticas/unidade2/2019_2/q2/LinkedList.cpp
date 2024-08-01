//
//  LinkedList.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    this->head = new Node<string>();
    this->tail = new Node<string>();
    
    this->head->setNext(this->tail);
    this->head->setPrevious(NULL);

    this->tail->setNext(NULL);
    this->tail->setPrevious(this->head);

    this->quantity = 0;
}

LinkedList::~LinkedList()
{
    Node<string>* n = this->head;
    
    while(n != this->tail)
    {
        Node<string>* toDestroy = n;
        
        n = n->getNext();
        
        delete toDestroy;
    }
    
    delete this->tail;
}

Node<string>* LinkedList::getHead(void)
{
    return this->head;
}

Node<string>* LinkedList::getTail(void)
{
    return this->tail;
}

int LinkedList::getQuantity(void)
{
    return this->quantity;
}

bool LinkedList::isEmpty(void)
{
    return this->quantity == 0;
}

void LinkedList::print(void)
{
    std::cout << "{ ";
    for(Node<string>* n = this->head->getNext(); n != this->tail; n = n->getNext())
    {
        std::cout << n->getValue() << ":" << n->getCount() << " ";
    }
    std::cout << "}" << std::endl;
}

ListStatus LinkedList::checkConsistency()
{
    if( this->head == NULL )
    {
        return HeadNull;
    }
    else if( this->head->getNext() == NULL )
    {
        return HeadNextNull;
    }
    else if( this->head->getNext()->getPrevious() != this->head )
    {
        return IncorrectLink;
    }
    else if( this->head->getPrevious() != NULL )
    {
        return HeadPrevious;
    }
    
    if( this->tail == NULL )
    {
        return TailNull;
    }
    else if( this->tail->getPrevious() == NULL )
    {
        return TailPreviousNull;
    }
    else if( this->tail->getPrevious()->getNext() != this->tail )
    {
        return IncorrectLink;
    }
    else if( this->tail->getNext() != NULL )
    {
        return TailNext;
    }
    
    if(this->isEmpty())
    {
        if( this->head->getNext() != this->tail )
        {
            return HeadTail;
        }
        
        if( this->head != this->tail->getPrevious() )
        {
            return HeadTail;
        }
    }
    else
    {
        // Verifica encadeamento dos elementos
        for(Node<string>* i = this->head->getNext(); i != this->tail; i=i->getNext())
        {
            if( i->getNext()->getPrevious() != i )
            {
                return IncorrectLink;
            }
            if( i->getPrevious()->getNext() != i )
            {
                return IncorrectLink;
            }
        }
    }
    
    return OK;
}

bool LinkedList::insertEnd(string s)
{
    auto aux = this -> tail -> getPrevious();
    auto novo = new Node<std::string>(s);

    novo -> setNext(tail);
    novo -> setPrevious(aux);
    aux -> setNext(novo);
    tail -> setPrevious(novo);

    quantity++;
    return true;

}

Node<string>* LinkedList::searchCF(string key)
{
    auto aux = head -> getNext();

    while(aux != tail){

        if(aux -> getValue() == key){

        aux -> incrementCount();

        auto temp = aux;

        while(temp != head -> getNext() && temp -> getCount() > temp-> getPrevious()->getCount()){
            auto prev = temp -> getPrevious();
            auto next = temp -> getNext();

            prev -> getPrevious() -> setNext(temp);
            temp -> setPrevious(prev -> getPrevious());

            temp -> setNext(prev);
            prev -> setPrevious(temp);

            prev -> setNext(next);
            next -> setPrevious(prev);
        }
        return aux;
    }
    aux = aux -> getNext();
    }

    return nullptr;
}
