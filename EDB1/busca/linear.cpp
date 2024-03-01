#include <cstddef>
#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <string>

using value_type = int; //alias = apelido

template <size_t len> std::string to_string(std::array<value_type, len> A){
    std::string result = "[";
    for (size_t i = 0; i < len; ++i) {
        result += std::to_string(A[i]);
        if (i != len - 1)
            result += ", ";
    }
    result += "]";
    return result;
}


template < typename T ,size_t len>
T lsearch(std::array<T , len>&arr , T target){
    for(size_t i{0}; i< arr.size(); ++i ){ 
        if(arr[i] == target){return i;}
    }
    //deu merda retorna o -1
    return -1;
}

int main(){

    constexpr size_t tamanho{9};

    std::array<value_type , tamanho> array1 {0,32,45,67,43,34,21,12,34};

    std::cout<<"Array1 : " << to_string(array1) << "\n";


    for(int target : array1){
        int idx = lsearch(array1, target);

        if(idx == tamanho){
            std::cout<< "Not found" <<std::endl;
        }else{
            std::cout<<"Achou em "<< target <<" em " << idx << std::endl;
        }
    }

//    size_t idx = lsearch(array1,  43);
//    std::cout<<idx << std::endl;

    return 0;
}