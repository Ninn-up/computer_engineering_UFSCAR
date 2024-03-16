#include "Pessoa.h"

namespace poo{
    Pessoa::Pessoa(string nome, int CPF) : nome(nome), CPF(CPF){

    }

    Pessoa::~Pessoa(){}

    string Pessoa::getNome() const{
        return nome;
    }

    int Pessoa::getCPF() const{
        return CPF;
    }

    void Pessoa::imprime() const{
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
    }
}