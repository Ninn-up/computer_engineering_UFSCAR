#include "Alunos.h"

//Não é necessário incluir <iostream> ou "namespace std"

Alunos::Alunos(string nome, int idade, int RA) : Pessoa(nome, idade), RA(RA){

}

Alunos::~Alunos(){};

int Alunos::getRA() const{
    return RA;
}

void Alunos::setRA(int RA){
    this->RA = RA;
}

void Alunos::imprime() const{
    Pessoa::imprime(); 
    cout << "RA: " << RA << endl;
}

