#include <iostream>
#include <algorithm>

#include "list.h"

template<typename Object>
List<Object>::List(){
    init();
}

template<typename Object>
List<Object>::~List(){
    clear();
    delete head;
    delete tail;
}

template<typename Object>
void List<Object>::init(){
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}

template<typename Object>
int List<Object>::size() const{
    return theSize;
}

template<typename Object>
bool List<Object>::empty() const{
    return size() == 0;
}

template<typename Object>
void List<Object>::clear(){
    while(!empty()){
        pop_front();
    }
}

template<typename Object>
typename List<Object>::iterator List<Object>::begin(){
    return {head -> next}; // or return (head->next);
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::begin() const{ //todo: review
    return {head -> next};
}

template<typename Object>
typename List<Object>::iterator List<Object>::end(){
    return {tail};
}

template<typename Object>
typename List<Object>::const_iterator List<Object>::end() const{ //todo: review
    return {tail};
}

template<typename Object>
Object& List<Object>::front(){
    return *begin();
}

template<typename Object>
const Object& List<Object>::front() const{
    return *begin();
}

template<typename Object>
Object& List<Object>::back(){
    return *--end();
}

template<typename Object>
const Object& List<Object>::back() const{
    return *--end();
}

template<typename Object>
void List<Object>::push_front(const Object& x){
    insert(begin(), x);
}

template<typename Object>
void List<Object>::push_front(Object&& x){
    insert(begin(), std::move(x));
}

template<typename Object>
void List<Object>::push_back(const Object& x){
    insert(end(), x);
}

template<typename Object>
void List<Object>::push_back(Object&& x){
    insert(end(), std::move(x));
}

template<typename Object>
void List<Object>::pop_front(){
    remove(begin());
}

template<typename Object>
void List<Object>::pop_back(){
    remove(--end());
}

template<typename Object>
void List<Object>::printList() const{
    for(auto itr = begin(); itr != end(); ++itr){
        std::cout << *itr << " ";
    }
    std::cout << std::endl;
}

template<typename Object>
void List<Object>::insert(iterator itr, const Object& x){
    Node* p = itr.current;
    theSize++;
    Node* newNode = new Node{x, p->prev, p};
    p->prev->next = newNode;
    p->prev = newNode;
}

template<typename Object>
void List<Object>::insert(iterator itr, Object&& x){
    Node* p = itr.current;
    theSize++;
    Node* newNode = new Node{std::move(x), p->prev, p};
    p->prev->next = newNode;
    p->prev = newNode;
}

template<typename Object>
void List<Object>::remove(iterator itr){
    Node* p = itr.current;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;
}