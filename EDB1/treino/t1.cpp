#include <iostream>
#include <array>
int maior(int arr[], int size){
  int max = 0;
  int atual = arr[0];
  //int size = arr.size();
  if(atual == size){
    return max;
  }

  if(arr[atual] > arr[max]){
    max = atual;
  }
  atual++;

  return maior(arr, size);

}

int menor(int arr[] , int size , int atual){
  int min = 9999;
  if(atual == size){
    return min;
  }
  if(arr[atual] < arr[min]){
    min = atual;
  }
  return menor(arr , size , atual +1);
}

int soma(int arr[] , int size , int soma , int atual){
  if(atual == size){
    return soma;
  }
  soma += arr[atual];

//  return soma(arr , size , soma, atual+1);
}

int pares(int arr[] , int size , int contador , int atual ){
  if(atual == size){
    return contador;
  }

  if(arr[atual] % 2 == 0){
    contador++;
  }
  return pares(arr,size,contador,atual+1);
}

int impares(int arr[] , int size , int contador , int atual){
  if(atual == size){
    return contador;
  }
  if(arr[atual] % 2 != 0){
    contador++;
  }
  return impares(arr , size , contador , atual+1);

}

int media(int arr[] , int size , int contador , int atual){
  if(atual == size){
    return (contador / atual);
  }

  soma(arr , size , contador , atual);

 // double res = soma / size;
//  return res ; //kkkkkkkk era para ser recursivo e fui alem kkkkk
}

//////////////////////////// parte 2 
///

int maior_1(int n , int max){
  
  if(n == 0){
    return max;
  }

  int atual = n % 10;

  if( atual > max){
    max = atual;
  }

  return maior_1(n/10 , max);

}

int par_2(int n , int cont){
  if(n==0){
    return cont;
  }
  int atual = n % 10;

  if(atual % 2 == 0){
    cont++;
  }
  return par_2(n/10 , cont);
}

int impar_2(int n , int cont){
  if(n==0){
    return cont;
  }
  int atual = n % 10;

  if(atual % 2 != 0){
    cont++;
  }
  return impar_2(n/10 , cont);
}

int soma_2(int n , int sum){
  if(n==0){
    return sum;
  }

  int atual = n % 10;

  sum += atual;

  return soma_2(n/10 , sum);
}

int media(int n , int sum , int size){
  if(n==0){return sum/size;}

  int atual = n % 10;
  size++;

  sum += atual;

  return( n/10 ,sum,size);
}



int main() {
    // Testando operações em arrays
    int arr[] = {10, 30, 20, 50, 40};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
   /* 
    int maior = findMaxIndex(arr, arrSize);
    int minIndex = findMinIndex(arr, arrSize);
    int totalSum = sumArray(arr, arrSize);
    
    std::cout << "Índice do maior elemento do array: " << maxIndex << std::endl;
    std::cout << "Índice do menor elemento do array: " << minIndex << std::endl;
    std::cout << "Soma de todos os elementos do array: " << totalSum << std::endl;

    // Testando operações em números inteiros
    int num = 211721172117;
    int evenCount = countEvenDigits(num);
    int oddCount = countOddDigits(num);
    int digitSum = sumDigits(num);
    
    std::cout << "Quantidade de dígitos pares de " << num << ": " << evenCount << std::endl;
    std::cout << "Quantidade de dígitos ímpares de " << num << ": " << oddCount << std::endl;
    std::cout << "Soma de todos os dígitos de " << num << ": " << digitSum << std::endl;
  */
  int max = maior(arr , arrSize);
  std::cout<< "  "<<max <<std::endl;
    return 0;
}
