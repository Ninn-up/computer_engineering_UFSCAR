#include "Professor.h"
//Não é necessário incluir iostream e "namespace std"

Professor::Professor(string nome, int idade, float salario) : Pessoa(nome, idade), salario(salario){

};

Professor::~Professor(){};

float Professor::getSalario() const{
    return salario;
}

void Professor::setSalario(float salario){
    this->salario = salario;
}

void Professor::imprime() const{
    Pessoa::imprime();
    cout << "Salario: R$" << salario << endl;
}
