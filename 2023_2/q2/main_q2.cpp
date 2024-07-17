#include <iostream>
#include <cassert>
#include "DadosEntrada.h"

using namespace std;

void mergeSort(int[], int, int);
bool estaDecrescente(int [], int);

int main(void)
{
    cout << "\t---\tQuestão 02: Início\t---" << endl;

    int tamanho = 1000000;

    mergeSort(arrayAleatorio, 0, tamanho-1); // arrayAleatorio é definido dentro de DadosEntrada.h

    assert( estaDecrescente(arrayAleatorio, tamanho) );

    mergeSort(arrayCrescente, 0, tamanho-1); // arrayCrescente é definido dentro de DadosEntrada.h

    assert( estaDecrescente(arrayCrescente, tamanho) );
    

    cout << "\t---\tQuestão 02: Passou em todos os testes\t---" << endl;

    return 0;
}

void merge(int array[], int inicio1, int meio, int fim2)
{
    // definir incio 2, array temporário definir o i k e j
  int inicio2 = meio + 1;
  int tam = fim2 - inicio1 + 1;
  int i = inicio1 , k = 0 , j = inicio2;
  int *temp = new int [tam];  
  
  //comparar com um while i e j
  while(i <= meio && j<= fim2){
    if(array[i] > array[j]){
      temp[k++] = array[i++];
    }else {
      temp[k++] = array[j++];
    }
  }

  //após isso vamos devolver para o array original 
  while(i <= meio){
    array[i++] = temp[k++];
  }
  while(j <= fim2){
    array[j++] = temp[k++];
  }

  for(i = inicio1 , k = 0 ; i < fim2 , k < tam ; i++ , k++){
    array[i] = temp[k];
  }
}


void mergeSort(int array[], int esquerda, int direita)
{
    if(esquerda < direita)
    {
        int meio = (esquerda + direita) / 2;
        mergeSort(array, esquerda, meio);
        mergeSort(array, meio+1, direita);
        merge(array, esquerda, meio, direita);
    }
}

/**
 * Esta é uma função auxiliar que eu criei para poder testar se sua ordenação está correta. Não altere-a.
*/
bool estaDecrescente(int array[], int tamanho)
{
    for(int i = 0; i < tamanho-1; i++)
    {
        if( array[i] < array[i+1] )
        {
            return false;
        }
    }

    return true;
}
