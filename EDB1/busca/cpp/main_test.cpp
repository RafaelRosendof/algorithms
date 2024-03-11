#include "head.h"
#include "main_class.cpp"


class test_maneger{
    public:

    void test_linear(){
        std::array<int,10> figas = {23,24,56,43,12,3,67,89,76,54};
        int target1 = 76;
        int *res = sa::busca().lsearch(figas.begin(), figas.end(), target1);

        assert(*res == figas[8]);

        int target2 = 999;
        int *res2 = sa::busca().lsearch(figas.begin(),figas.end(), target2);
        assert(res2 == figas.end());

        std::cout<<"\nPASSOU NA BUSCA LINEAR: "<<std::endl;

    }

    void test_binary(){
        std::array<int , 10> figas = {14,25,78,96,36,24,57,89,54,75};
        std::sort(figas.begin(), figas.end());
        int target1 = 36;
        int target2 = 999;

        int *res1 = sa::busca().bsearch(figas.begin() , figas.end(), target1);
        int *res2 = sa::busca().bsearch(figas.begin() , figas.end(), target2);

        assert(*res1 == figas[3]);
        assert(res2 == figas.end());
        std::cout << "\n PASSOU NA BUSCA BINÁRIA" << std::endl;
    }

    void test_binary_recursive(){
        std::array<int , 10> figas = {14,25,78,96,36,24,57,89,54,75};
        std::sort(figas.begin(), figas.end());

        int target1 = 36;
        int target2 = 999;

        int *res1 = sa::busca().bsearch_rec(figas.begin() , figas.end(), target1);
        int *res2 = sa::busca().bsearch_rec(figas.begin() , figas.end(), target2);

        assert(*res1 == figas[3]);
        assert(res2 == figas.end());
        std::cout << "\n PASSOU NA BUSCA BINÁRIA RECURSIVA" << std::endl;
    }

    void test_ternario(){
        std::array<int , 10> figas = {14,25,78,96,36,24,57,89,54,75};
        std::sort(figas.begin(), figas.end());

        int target1 = 36;
        int target2 = 999;

        int *res1 = sa::busca().ternario(figas.begin() , figas.end(), target1);
        int *res2 = sa::busca().ternario(figas.begin() , figas.end(), target2);

        assert(*res1 == figas[3]);
        assert(res2 == figas.end());
        std::cout << " \n PASSOU NA BUSCA BINÁRIA TERNÁRIA" << std::endl;
    }
};


int main() {
    test_maneger tester;

    // Run tests
    tester.test_linear();
    tester.test_binary();
    tester.test_binary_recursive();
    tester.test_ternario();

    std::cout << "\nAll tests passed successfully!" << std::endl;

    return 0;
}