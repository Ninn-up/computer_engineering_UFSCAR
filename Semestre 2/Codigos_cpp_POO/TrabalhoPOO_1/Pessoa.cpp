#include "Pessoa.h"

namespace poo{
    //Construtor
    Pessoa::Pessoa(string CPF, string nome) : CPF(CPF), nome(nome){

    }

    //Destrutor
    Pessoa::~Pessoa(){};

    //Retorna o CPF
    string Pessoa::getCPF() const{
        return CPF;
    }

    //Retorna o nome
    string Pessoa::getNome() const{
        return nome;
    }

    //Imprime as informações de uma pessoa
    void Pessoa::imprime() const{
        cout << "Nome: " << nome << endl;
        cout << "CPF: " << CPF << endl;
    }
}