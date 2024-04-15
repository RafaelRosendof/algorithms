#include<iostream>
#include<array>

int maior(int n , int arr[]){
  if(n==0){
    return arr[0];
  }
  int max = maior(n-1 , arr);

  return (arr[n] > max) ? arr[n] : max; //if arr[n] > max return arr[n] else max 
}

int menor(int n , int arr[]){
  if(n==0){ return arr[0];}

  int max = menor(n-1 , arr);

  return (arr[n] < max) ? arr[n] : max;
} 

int pares(int n , int arr[]){
  if(n==0){return arr[0] % 2 ? 1 : 0 ;} //caso base 

  else{
    int count = pares(n-1 , arr);
    if(arr[n] % 2 == 0){
      count++;
    }
    return count;
  }
}

int impares(int n , int arr[]){
  if(n == 0){return arr[0] % 2 ? 1 : 0;}

  else{
    int count = impares(n-1 , arr);
    if(arr[n] % 2 != 0){
      count++;
    }
    return count;
  }
}

int soma(int n , int arr[]){
  if(n == 0){return 0;}
  else{
    int sum = soma(n-1 , arr);
    if(arr[n] != 0){
      sum += arr[n];
    }
    return sum;
  }
}

int media(int n , int arr[]){
  int size = n;
  double figas;
  if(n == 0){return 0;}
  else{
    int soma = media(n-1 , arr);
    if(arr[n] != 0){
      soma += arr[n];
    }
    double value = soma/size;
    return value;
  }

}

//parte 2
//esse aqui na vdd é a soma dos digitos 
int menor_1(int n){
  if(n == 0){return 0;}

  else{
    int count = menor_1(n/10);
    if(n!=0){
      count += n%10;
    }
    return count;
  }
}

double media_2(int n) {
    if (n == 0) {
        return 0.0;
    } else {
        double count = media_2(n / 10);
        int size = 1;
        if (n != 0) {
            count += n % 10;
            size += media_2(n/10);
        }
        double media = menor_1(n) / size;
        return media;
    }
}

int menor_vdd(int n){ //maior é assim tbm, vou pular 
  if(n < 10) {return n;}

  else {
    int atual = n % 10;
    int att = menor_vdd(n/10);

    if(atual > att){
      return att;
    }else{
      return atual;
    }
  }
}

int pares_1(int n){

  if(n<10){return (n % 2 == 0) ? 1 : 0;}

  else{
    int iter = pares_1(n/10);
    if((n%10) % 2 == 0){
      iter++;
    }
    return iter;
  }
}

int impares_1(int n){
  if(n<10) {return (n % 2 != 0) ? 1 : 0;}

  else{
    int iter = impares_1(n/10);
    if((n%10) % 2 != 0){
      iter++;
    }
    return iter;
  }
}

void binario(int n){
  if(n >1){
    binario(n/2);
  }
  std::cout<< "   " << n%2;
}


int main() {
    int arr[] = {10, 30, 20, 50, 40};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Encontra o índice do maior elemento no array
    //int maxIndex = maior(5 , arr);
    int min_ind = menor(5 , arr);
    int par = pares(5, arr);
    int impar = impares(5,arr);
    int sum = soma(5,arr);
    int med = media(5, arr);
    int men_1 = menor_1(2117);
    int med_1 = media_2(2117);
    int min_1 = menor_vdd(2117);
    int par_1 = pares_1(2222);
    int imp_1 = impares_1(2117);
   // int figas = binario(2117);
    int exp = 2117;
    binario(exp);
    // Imprime o resultado
    //if (med != -1)
    //    std::cout << "O maior elemento do array está no índice: " << med << std::endl;
    //else
    //    std::cout << "O array está vazio." << std::endl;

   // std::cout<<"valor foi: " << imp_1<<std::endl;
    return 0;
}


