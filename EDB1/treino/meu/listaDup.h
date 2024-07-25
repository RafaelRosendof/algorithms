

#ifndef LISTADUPLA
#define LISTADUPLA

#include "No.h"
#include <string>
#inlude <iostream>

typedef enum{
    OK,
    HEAD_NULL,
    TAIL_NULL,
    HEAD_PREV,
    HEAD_NEXT_NULL,
    TAIL_NEXT,
    TAIL_PREV_NULL,
    HEAD_TAIL,
    INCORRECT_CHAIN
} StatusDaLista;

class ListaDupla{
    private:
        No<std::string>* head;
        No<std::string>* tail;
        int quantity;

    public:
        ListaDupla(void);
        ~ListaDupla(void);

        std::string recover(int);
        int search(std::string);

        bool insertHead(std::string);
        bool insertTail(std::string);
        bool insert(int, std::string);

        std::string removeHead(void);
        std::string removeTail(void);
        std::string remove(int);

        StatusDaLista checkConsistency(void);

        No<std::string>* getHead(void);
        No<std::string>* getTail(void);

        void print(void);

        bool empty(void);

        int size(void);
};

#endif