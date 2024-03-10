#include "Professor.h"

namespace poo {
    Professor::Professor(string nome, int CPF, float salario) : Pessoa(nome, CPF), salario(salario){}

    Professor::~Professor(){}

    float Professor::getSalario() const{
        return salario;
    }

    void Professor::imprime() const{
        Pessoa::imprime();
        cout << "Salario: R$" << salario << endl;
    }
}