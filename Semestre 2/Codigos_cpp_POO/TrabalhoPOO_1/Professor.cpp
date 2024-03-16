#include "Professor.h"

namespace poo {
    //Construtor
    Professor::Professor(string CPF, string nome, string universidade) : Pessoa(CPF, nome), universidade(universidade){

    }

    //Destrutor
    Professor::~Professor(){};

    //Retorna o nome da universidade onde o processor trabalha
    string Professor::getUniversidade() const{
        return universidade;
    }

    //Imprime o nome, o CPF e a universidade de um professor
    void Professor::imprime() const{
        Pessoa::imprime();  //Imprime o nome e o CPF
        cout << "Universidade: " << universidade << endl;
    }

}