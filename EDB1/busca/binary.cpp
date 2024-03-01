#include <array>
#include <iostream>
#include <string>
#include <cstddef>
#include <iterator>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <vector>

using value_type = int;
template <size_t len> std::string to_string(std::array< value_type , len>A){
    std::string results = "]";
    for(size_t i{0} ; i<A.size() ; ++i){
        results += std::to_string(A[i]);
        if(i != len - 1){
            results += ", ";
        }
        results += "]";
        return results;
    }
}

template <typename T , size_t size>
size_t bsearch(std::array<T, size> &arr , size_t l , size_t r , value_type target){


    while(l<=r){
        size_t meio = r + (l+r)/2;

        if(arr[meio] == target){return meio;}

        else if (meio < target) {
            l = meio + 1; // l recebe meio
        }
        else{
            r = meio - 1; //r recebe meio -1 
        }
    }
    return r;

}


int main(){
    constexpr size_t tamanho = 10;

    std::array<int , tamanho>figas {23,34,56,32,12,56,78,97,90,765};

    std::sort(figas.begin() , figas.end());
    size_t l{0};
    size_t r{tamanho - 1};

    int target {78};

    int idx = bsearch(figas,  l,  r,  target);
    if(idx == r+1){  std::cout<<"Não foi achado" << target << std::endl; }
    else{ std::cout << "Valor " << target << " "<< idx << std::endl;}   

    return 0;
}