#include <string>
#include <iostream>
#include "Pessoa.h"

using namespace std;

int main(){

    Pessoa delano("Delano", 48);
    Pessoa ciclano("Ciclano", 18);


    delano.setNome("Nicole");
    delano.setIdade(19);

    ciclano.setNome("Carol");

    delano.imprime();
    ciclano.imprime();

    if (delano.maior(ciclano)){
        cout << delano.getNome();
    }
    else{
        cout << ciclano.getNome();

    }

    cout << " eh o mais velho" << endl;

    return 0;
}