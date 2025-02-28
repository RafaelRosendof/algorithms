#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

std::vector<int> map(std::vector<int> vec1 , int X){

    #pragma omp parallel for
    for( int i = 0 ; i < vec1.size() ; i++){
        vec1[i] += X;
    }

    return vec1;
}

std::vector<int> map_serial(std::vector<int> vec1, int X) {
    for (int i = 0; i < vec1.size(); i++) {
        vec1[i] += X;
    }
    return vec1;
}
//g++ -fopenmp -o mp mpEx.cpp
int main(){

    std::vector<int> figas(100000000);


        srand(static_cast<unsigned int>(time(0)));
        for (int i = 0; i < 10000; i++) {
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
    return 0;
}
