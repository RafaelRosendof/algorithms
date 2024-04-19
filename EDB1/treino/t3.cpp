#include<iostream>
#include<array>
#include<algorithm>
#include <iterator>

int soma_2(int n , int arr[], int soma){
    int left = 0;
    int rigth = n-1;

    while( left < rigth){
        int sum = arr[left] + arr[rigth];
        
        if(sum == soma){
            //return arr[left] , arr[rigth];
            return true;
        }
        else if(sum < soma){
            left++;
        }else{
            rigth--;
        }
    }
    return false; 
}

int segunda(int n , int arr[], int key){
    int left = 0;
    int rigth = n-1;
    int aux = -1;
    while(left < rigth){
        int mid = left + (rigth-left) / 2;

        if(arr[mid] == key){
            aux = mid;
            rigth = mid - 1;
        }else if(arr[mid] > key){
            //return segunda(mid - 1 , arr , key);
            rigth = mid - 1;
        }else{
            left = mid+1;
            //return segunda(, int *arr, int key)

        }
    }
    return aux;
}

int segunda_1(int n , int arr[] , int key){
    // pode usar duas funções binárias uma para encontrar cada extremo e depois subtrair os extremos 

    int aux1 = -1;
    int aux2 = segunda(n, arr,key);
    int aux3 = aux1 - aux2;
    int left = 0;
    int rigth = n - 1;

    while(left < rigth){
        int mid = left + (rigth - left) / 2;

        if(arr[mid] == key){
            aux1 = mid;
            left = mid + 1;
        }else if(arr[mid] < key){
            left = mid + 1;
        }else{
            rigth = mid - 1;
        }
    }
    return aux1; //é nessa pegada aí 
}

int main(){

    int n = 15;
   // std::array<int,15>arr = {32,45,42,56,78,65,43,23,10,20,45,67,86,54,12};
   int arr[] = {0,3,3,3,3,3,4,4,5,5,6 ,6 , 6,7,8};
    //std::sort(arr.begin() , arr.end());
    int soma = 20;
    int figas = soma_2(n, arr,soma);
    int sum = segunda(15, arr, 3);
    int sum1 = segunda_1(15, arr, 3);

    std::cout << "resultado foi : " <<sum1 <<std::endl;

    return 0;
}