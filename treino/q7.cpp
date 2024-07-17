#include <cassert>
#include <iostream>

bool existeSoma3(int array[], int tamanho, int soma)
{
  for(int i =0 ; i< tamanho ; i++){
    for(int j = 0 ; j < tamanho ; j++){
      int k = soma - (array[i] + array[j]);

      int esq = 0 , dir = tamanho;

      while(esq <= dir){
        int mid = esq + (dir - esq) / 2;

        if(k == array[mid]){
          return true;
        }
        else if (k < array[mid]) {
          dir = mid - 1; 
        }
        else {
          esq = mid + 1;
        }
      }
    }
  }
	return false;
}

int main(void)
{
	int v1[] = {0, 1, 1, 3, 4, 4, 4, 4, 5, 6, 7, 8, 8, 8, 8, 8, 9, 10, 10, 10 };
	int tamanho1 = sizeof(v1)/sizeof(int);

	assert( existeSoma3(v1, tamanho1,  0) == true); //  0 == 0 + 0 + 0
	assert( existeSoma3(v1, tamanho1,  4) == true); //  4 == 0 + 1 + 3  || 0 + 0 + 4
	assert( existeSoma3(v1, tamanho1, 22) == true); // 22 == 4 + 8 + 10 || 5 + 7 + 10 || ...
	assert( existeSoma3(v1, tamanho1, 33) == false); 
	assert( existeSoma3(v1, tamanho1, -1) == false); 

	std::cout << "\n!!!! Q3 - Passou em todos os testes !!!! " << std::endl;
	return 0;
}

