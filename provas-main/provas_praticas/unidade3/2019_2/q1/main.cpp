//
//  main.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include <iostream>
#include <string>
#include <cassert>
#include "Dictionary.h"

using namespace std;

Dictionary<string, int>* buildMultiSet(string array[], int arraySize){
    Dictionary<string, int>* d = new Dictionary<string, int>();

    for(unsigned long i = 0; i < arraySize; i++){
        std::string elem = array[i];

        if(d->contains(elem)){
            int atual = d->get(elem);
            d->put(elem, atual + 1);
        } else {
            d->put(elem, 1);
        }
    }
    return d;
}

int main(int argc, const char * argv[]) {
    string array[] = {"A", "A", "B", "A", "B", "C"};
    int arraySize = 6;

    Dictionary<string, int>* d = buildMultiSet(array, arraySize); 

    assert(d->get("A") == 3);
    assert(d->get("B") == 2);   
    assert(d->get("C") == 1);   

    try {
        d->get("D"); // deve lançar uma exceção, pois D não está no dicionário
        assert(false); // não deveria executar esta linha
    } 
    catch(const std::out_of_range& e) { // Certifique-se de capturar por referência constante
        assert(true); // A exceção foi corretamente capturada
    }

    cout << "Teste OK!" << endl;

    delete d; // Não esqueça de liberar a memória alocada!
}
