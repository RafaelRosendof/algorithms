

#ifndef NO
#define NO

#include <iostream>

template <typename T>
class No{

    private:
        T value;
        No* next;
        No* previous;

    public:
    No(); //constructor

    No(T); //constructor

    No(T, No*, No*); //constructor

    T getValue(); //getter

    void setValue(T val); //setter

    No* getNext(); //getter

    void setNext(No*); //setter

    No* getPrevious(); //getter

    void setPrevious(No*); //setter
};

template<typename T>
No<T>::No(void):
next(NULL) {}

template<typename T>
No<T>::No(T val):

value(val) , next(NULL), previous(NULL) {}

template<typename T>
No<T>::No(T val , No* n , No* p):
value(val), next(n), previous(p) {}

template<typename T>
T No<T>::getValue(void){
    return this->value;
}

template<typename T>
void No<T>::setValue(T t){
    this->value = t;
}

template<typename T>
No<T>* No<T>::getNext(void){
    return this->next;
}

template<typename T>
void No<T>::setNext(No* n){
    this->next = n;
}

template<typename T>
No<T>* No<T>::getPrevious(void){
    return this->previous;
}

template<typename T>
void No<T>::setPrevious(No* p){
    this->previous = p;
}

#endif