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
        T meio = l + (r-l)/2;

        if(arr[meio] == target){return meio;}

        else if (arr[meio] < target) {
            l = meio + 1; // l recebe meio
        }
        else{
            r = meio - 1; //r recebe meio -1 
        }
    }
    return r;

}

//template <typename T>
int * bsearch_point(int *first , int *last , int target){

    while(first <= last){

        int *meio = first + (last - first)/2;

        if(*meio == target) {return meio;}

        else if (*meio < target) {
            first = meio + 1;
        
        }else{
            last = meio - 1;
        }
    }
    return nullptr;
}

int *bsearch_rec(int *l , int *r , int target){
    while(l <= r){
        int *meio = l + (r-l)/2;

        if(*meio == target) {return meio;}

        else if(*meio < target){
            return bsearch_rec(meio + 1, r,  target);
        }else{
            return bsearch_rec( l, meio - 1,  target);
        }
    }
    return nullptr;
}


int main(){
    constexpr size_t tamanho = 10;

    std::array<int , tamanho>figas {23,34,56,32,12,56,78,97,90,765};

    std::sort(figas.begin() , figas.end());
    size_t l{0};
    size_t r{tamanho - 1};

    //int target {23};

    for(value_type target : figas){
        int idx = bsearch(figas,  l,  r,  target);
        if(idx == r+1){  std::cout<<"Não foi achado" << target << std::endl; }
        else{ std::cout << "Valor " << target << " "<< idx << std::endl;}   

    }

    std::cout<<"\n\n";

    //for(value_type target : figas){
   //     size_t idx = bsearch_point(figas, figas.size() ,  target);
   //     if(idx == r+1){std::cout<<"Failed to find " << target <<std::endl;}
    //    else{std::cout<< "Valor " << target << " " << idx << std::endl;}
  //  }

    constexpr int target{97};

    int *res  = bsearch_point(figas.begin(), figas.end() - 1 ,  target);

    if (res != nullptr) 
        std::cout << "Value found at index " << target <<"  " << res - figas.begin() << std::endl; 
    else 
        std::cout << "Value not found" << std::endl; 

    std::cout<<"\n\n";

    int *res_rec = bsearch_rec(figas.begin(), figas.end() - 1, target);

    if(res != nullptr){std::cout << "Value found at index " << target <<"  " << res_rec - figas.begin() << std::endl; }

    else{std::cout<<"Value not found! "<<std::endl;}
 
    return 0;
}