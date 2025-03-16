#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

std::vector<int> map(std::vector<int> vec1 , int X){

    #pragma omp parallel for
    for( long i = 0 ; i < vec1.size() ; i++){
        vec1[i] += X;
    }

    return vec1;
}

std::vector<int> mapThreads(std::vector<int> vec1 , int X){

    auto f = [X] (int x)
    {
        return x + X;
    };

    int num_th = 4;
    std::vector<std::thread>ths;
    std::vector<int>res(vec1.size());

    int chunk = vec1.size() / num_th;

    for( int i = 0 ; i < num_th ; i++){
        int begin = i * chunk;
        int end = (i == num_th - 1) ? vec1.size() : (i + 1) * chunk;

        ths.emplace_back([&,begin , end](){
            for(int i = begin ; i < end ; i++){
            res[i] = f(vec1[i]);
            }
        });
        }

        for (auto &th : ths){
            th.join();
        }

        return res;
}

std::vector<int> map_serial(std::vector<int> vec1, int X) {
    for (int i = 0; i < vec1.size(); i++) {
        vec1[i] += X;
    }
    return vec1;
}
//g++ -fopenmp -o mp mpEx.cpp



int main(){

    std::vector<int> figas(1000000000);


        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < 1000000000; i++) {
            figas[i] = rand() % 101;
        }


        auto begin_omp = std::chrono::high_resolution_clock::now();
        auto f1 = map(figas, 10);
        auto end_omp = std::chrono::high_resolution_clock::now();
        auto duration_omp = std::chrono::duration_cast<std::chrono::microseconds>(end_omp - begin_omp);


        auto begin_serial = std::chrono::high_resolution_clock::now();
        auto f2 = map_serial(figas, 10);
        auto end_serial = std::chrono::high_resolution_clock::now();
        auto duration_serial = std::chrono::duration_cast<std::chrono::microseconds>(end_serial - begin_serial);


        std::cout << "Tempo com OpenMP: " << duration_omp.count() << " microssegundos" << std::endl;
        std::cout << "Tempo sem OpenMP: " << duration_serial.count() << " microssegundos" << std::endl;

        std::cout<<" Rodando umas threads separadas em lambda functions \n\n" <<std::endl;

        auto f = [](int x)
        {
            int res = x * x;
            std::cout << "Resultado da thread  0  "<< res << std::endl;
            return res;
        };

        std::thread thO(f ,  10);

        thO.join();

        std::cout << " thread 0 finalizada " << std::endl;


        auto beginThMp = std::chrono::high_resolution_clock::now();

        std::vector<int>res = mapThreads(figas, 10);

        auto endTH = std::chrono::high_resolution_clock::now();

        auto duTH = std::chrono::duration_cast<std::chrono::microseconds>(endTH - beginThMp);

        std::cout<< " Tempo com threads em paralelo    "<< duTH.count() << std::endl;

    return 0;
}
