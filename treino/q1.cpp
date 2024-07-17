#include <iostream>
#include <cassert>

using namespace std;

int maiorDigito(int);

int main(void)
{
    cout << "\t---\tQuestão 01: Início\t---" << endl;

    assert(maiorDigito(123) == 3);
    assert(maiorDigito(9876) == 9);
    assert(maiorDigito(345987) == 9);
    assert(maiorDigito(0) == 0);
    assert(maiorDigito(10) == 1);

    cout << "\t---\tQuestão 01: Passou em todos os testes\t---" << endl;

    return 0;
}

// Pode assumir que essa função só receberá números maiores ou iguais do que zero
int maiorDigito(int N)
{
  //caso base
  if(N < 10){return N;}

  else{
    int max = N%10;
    int dev = maiorDigito(N/10);

    return(max > dev) ? max : dev;
  }
  
}

