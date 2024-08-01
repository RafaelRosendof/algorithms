#include "../include/Expressao.h"
#include <iostream>
#include <vector>
#include <stack>

bool adicao(std::string s)
{
    return s == "+";
}

bool subtracao(std::string s)
{
    return s == "-";
}

bool multiplicacao(std::string s)
{
    return s == "*";
}

bool divisao(std::string s)
{
    return s == "/";
}

bool operando(std::string s)
{
    return !adicao(s) && !subtracao(s) && !multiplicacao(s) && !divisao(s);
}

int resolverExpressao(std::vector<std::string> partesDaExpressao)
{
    std::stack<int> pile;

    for(std::string p : partesDaExpressao){
        if(operando(p)){
            pile.push(std::stoi(p));
        }else{
            int op2 = pile.top();
            pile.pop();
            int op1 = pile.top();
            pile.pop();

            int res = 0;

            if(adicao(p)){
                res = op1 + op2;
            }
            else if(subtracao(p)){
                res = op1 - op2;
            }
            else if(multiplicacao(p)){
                res = op1 * op2;
            }
            else if(divisao(p)){
                res = op1 / op2;
            }

            pile.push(res);

        }
    }
    return pile.top();
}


/*
    std::stack<int> pilha;

    for(std::string parte : partesDaExpressao){

      if(operando(parte)){
        pilha.push(std::stoi(parte));
      }
      else{
        int operando2 = pilha.top();
        pilha.pop();

        int operando1 = pilha.top();
        pilha.pop();
        
        int res = 0;
        if(adicao(parte)){
          res = operando1 + operando2;
        }
        else if (subtracao(parte)) {
         res = operando1 - operando2; 
        }
        else if(multiplicacao(parte)) {
         res = operando1 * operando2; 
        }
        else if (divisao(parte)) {
         res = operando1 / operando2; 
        }

        pilha.push(res);
      }
    }
    return pilha.top();
}
*/
