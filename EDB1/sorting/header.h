
#ifndef SORTING_H
#define SORTING_H

#include <iterator>
#include <iostream>
#include <array>
#include <algorithm>


//Aqui vai os headers e as assinaturas das funções 
using valor = int;
namespace sa {
    //assinatura de todas as funções 
    //Incluindo a bool Compare

    constexpr bool Compare(const valor &a ,const valor &b){ return (a < b); }


    template<typename ForwardItr , typename Compare>
    void insertion(ForwardItr first , ForwardItr last , Compare cmp){

    }


    template<typename ForwardItr , typename Compare>
    void bubble(ForwardItr first, ForwardItr last , Compare cmp){

    }

    template<typename ForwardItr , typename Compare>
    void selection(ForwardItr first , ForwardItr last , Compare cmp){

    }

    template< typename ForwardItr , typename Compare>
    void quick(ForwardItr first , ForwardItr last , Compare cmp){

    }

    template<typename ForwardItr , typename Compare>
    void mergesort(ForwardItr first , ForwardItr last , Compare cmp){

    }

    template<typename ForwardItr , typename Compare>
    void shell(ForwardItr firts , ForwardItr last , Compare cmp){

    }

    template<typename DataType>
    void radix(DataType *first , DataType *last ){

    }


//feito as assinaturas, agora vamos para a implementação. 

}

/*
shell
quicksort d
mergesort d
radix
bubble d 
select d
insertion d 

*/

#endif