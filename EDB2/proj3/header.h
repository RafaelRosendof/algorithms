#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No No ;
typedef struct tree tree ;

struct tree{
    int alt;
    No node;
    int num_filhos;
    tree * esq;
    tree *dir;
};

struct No{
    int age;
    char name[100];
    int score;
};

//Métodos TODO




#endif //HEADER_H
