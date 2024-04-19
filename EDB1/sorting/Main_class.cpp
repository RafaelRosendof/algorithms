//Aqui é onde vou rodar os testes e acho que os tempos 
//melhor chamar só as assinaturas das funções e passar os arryas como entrada de diferentes tamanhos e por ref(&)  

#include "header.h"
#include <array>

int main(){

    std::array<int, 10> figas = {7,6,8,9,5,4,3,2,1,0};

    //sa::insertion(figas.begin(), figas.end(), sa::Compare);

    sa::mergesort(figas.begin() , figas.end() , sa::Compare);
    //sa::shell(figas.begin(), figas.end(), sa::Compare);
    //sa::bubble(figas.begin(), figas.end(), sa::Compare);
    
  //  for(size_t i = 0; i < figas.size(); ++i){
  //      std::cout << " " << figas[i] << " ";
  //  }

    std::cout << "\n\n\nArray elements:";
    for (const auto& element : figas) {
        std::cout << " " << element;
    }
    std::cout << std::endl;

    return 0;
}
