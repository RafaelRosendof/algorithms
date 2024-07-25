#include "listaDup.h"

ListaDupla::ListaDupla(){

    this->head = new No<std::string>("ESSE_E_O_CONTEUDO_DA_CABECA_--NAO_DEVE_SER_ACESSADA");
    this-> tail = new No<std::string>("ESSE_E_O_CONTEUDO_DA_CAUDA_--CAUDA_NAO_DEVE_SER_ACESSADA");

    this->head->setNext(this->tail);
    this->head->setPrevious(nullptr);

    this->tail->setNext(nullptr);
    this->tail->setPrevious(this->head);

    this->quantity = 0;

} //constructor

ListaDupla::~ListDupla(){
    No<std::string>* aux = this->head;
    No<std::string>* next = this->head->getNext();

    while(next != this->tail){
        delete aux;
        aux = next;
        next = next->getNext();
    }   

    delete aux;
    delete next;
} //destructor lets test latter

No<std::string>* ListaDupla::getHead(void){
    return this->head;
}

No<std::string>* ListaDupla::getTail(void){
    return this->tail;
}

int ListaDupla::size(void){
    return this->quantity;
}

bool ListaDupla::empty(void){
    return this->size() == 0;
}

//testing this method
std::string ListaDupla::recover(int i){

    No<std::string>* novo = new No<std::string>(s);
    No<std::string>* aux = this->head->getNext();
    int j = 0;

    while (aux != this->tail && j < i) {
        aux = aux->getNext();
        j++;
    }

    novo->setPrevious(aux->getPrevious());
    novo->setNext(aux);
    aux->getPrevious()->setNext(novo);
    aux->setPrevious(novo);

    ++quantity;

    return true;
 //testing this method 
}

std::string ListaDupla::removeHead(void){
    if(this->empty()){
        return "";
    }
    //todo
}

std::string ListaDupla::removeTail(void){
    if(this->empty()){
        return "";
    }
    //todo
}

std::string ListaDupla::remove(int i){
    
}

