#include <iostream>
#include <cassert>
#include "DadosEntrada.h"

using namespace std;

bool soma2(int[], int, int);

int main(void)
{
    cout << "\t---\tQuestão 03: Início\t---" << endl;

    // Obs.: array1 e tamanho1 estão definidos no arquivo DadosEntrada.h

    // Testes cuja soma é feita com base em 2 elementos que estão no array e são distintos
    assert( soma2(array1, tamanho1, array1[0] + array1[tamanho1-1]) == true  );
    assert( soma2(array1, tamanho1, array1[0] + array1[tamanho1-2]) == true  );
    assert( soma2(array1, tamanho1, array1[1] + array1[tamanho1-1]) == true  );
    assert( soma2(array1, tamanho1, array1[1] + array1[tamanho1-2]) == true  );

    int meio = tamanho1/2;

    // Testes cuja soma é feita com base em 2 elementos que estão no array e são distintos
    assert( soma2(array1, tamanho1, array1[meio] + array1[meio+1]) == true  );
    assert( soma2(array1, tamanho1, array1[meio] + array1[meio+2]) == true  );
    assert( soma2(array1, tamanho1, array1[meio-1] + array1[meio+1]) == true  );
    assert( soma2(array1, tamanho1, array1[meio-1] + array1[meio+2]) == true  );

    // Testes cuja soma é feita com base em 2 elementos que estão no array mas são iguais
    assert( soma2(array1, tamanho1, array1[0] + array1[0]) == false  );
    assert( soma2(array1, tamanho1, array1[1] + array1[1]) == false  );
    assert( soma2(array1, tamanho1, array1[tamanho1-1] + array1[tamanho1-1]) == false  );

    // Testes cuja soma não é possível de se conseguir no array de entrada
    assert( soma2(array1, tamanho1, 0) == false  );
    assert( soma2(array1, tamanho1, 20) == false  );
    assert( soma2(array1, tamanho1, 99999) == false  );

    cout << "\t---\tQuestão 03: Passou em todos os testes\t---" << endl;

    return 0;
}

bool soma2(int array[], int tamanho, int soma)
{
 //busca binária
  //complexidade precisa ser n*log(n)
  int inicio = 0;
  int fim = tamanho - 1;
  
  while(inicio < fim){
    int atual = array[inicio] + array[fim];

    if(atual == soma){
      return true;
    }
    else if(atual < soma){
      inicio++;
  
    }else{
      fim--;
    }

  }
  return false;
    
  }



