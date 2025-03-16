#include <iostream>
#include <future>
#include <thread>

int soma(int a , int b){
    return a + b;
}

void imp(){
    std::cout << "  imprimindo asyncrono " << std::endl;
}




int main(){

    std::future<int> res = std::async(std::launch::async, soma , 50 , 50);

    std::cout << res.get() << std::endl;

    std::future<void> f = std::async(imp);

    std::future<void> f2 = std::async(std::launch::deferred , imp);

    f2.get();
    std::cout << "Rodando só quando chama o get () "  << std::endl;

    return 0;
}
