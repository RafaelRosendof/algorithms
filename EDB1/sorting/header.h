
#ifndef SORTING_H
#define SORTING_H

#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <iterator>

#include <string>
#include <utility> // std::move
#include <vector>  // std::vector

// Aqui vai os headers e as assinaturas das funções

namespace sa {
// assinatura de todas as funções
// Incluindo a bool Compare

constexpr bool Compare(const int &a, const int &b) { return (a < b); }

//função para printar o array, para eu conseguir visualizar melhor 
template <typename ForwardItr>
void printArray(ForwardItr first, ForwardItr last) {
  for (auto it = first; it != last; ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename ForwardItr, typename Compare>
void insertion(ForwardItr first, ForwardItr last, Compare cmp) {
  for (ForwardItr i = first; i != last; ++i) {
    if (cmp(*i, *std::next(i))) {
      std::iter_swap(i, std::next(i));
    }
    for (ForwardItr j = std::next(i); j != first && cmp(*j, *std::prev(j));
         --j) {
      std::iter_swap(j, std::prev(j));
    }
  }
}

// tem algo de errado aqui, vou tentar implementar melhor depois. ta muito
// complexo

template <typename ForwardItr, typename Compare>
void bubble(ForwardItr first, ForwardItr last, Compare cmp) {
  for (ForwardItr i = first; i != last; ++i) {
    for (ForwardItr ii = first; ii != last - 1; ii++) {
      if (cmp(*std::next(ii), *ii)) {
        std::iter_swap(ii, std::next(ii));
      }
    }
  }
}

template <typename ForwardItr, typename Compare>
void selection(ForwardItr first, ForwardItr last, Compare cmp);

template <typename ForwardItr, typename Compare>
void quick(ForwardItr first, ForwardItr last, Compare cmp);

template <typename ForwardItr, typename Compare>
void mergesort(ForwardItr first, ForwardItr last, Compare cmp);

template <typename ForwardItr, typename Compare>
void shell(ForwardItr first, ForwardItr last, Compare cmp) {
    ForwardItr f = first;
    ForwardItr l = last;
  int size = std::distance(first, last);
  for (int i = size / 2; i > 0; i /= 2) { // O loop externo controla o espaçamento entre os elementos a serem comparados e trocados
    for (int comp = i; comp < size; ++comp) { //loop interno que percorre os elementos do array a partir do índice i
      auto tmp = std::move(*(first + comp)); //armezenando temporariamente o elemento a ser movido 
      int comp1 = comp; //variável para rastrear a posição do elemento a ser comparado

      for (; comp1 >= i && cmp(tmp, *(first + comp1 - i)); comp1 -= i) { // Loop para inserir o elemento na posição correta
        *(first + comp1) = std::move((*first + comp1 - i)); //move o elemento anterior uma posição a frente 
        printArray(f,  l); //printando para saber né 
      }
      *(first + comp1) = std::move(tmp); //inserindo o elemento na posição correta
      printArray(f,  l);
    }
  }
}

template <typename DataType> void radix(DataType *first, DataType *last);

// feito as assinaturas, agora vamos para a implementação.

} // namespace sa

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