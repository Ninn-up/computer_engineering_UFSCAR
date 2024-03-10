#include "Pessoa.h"
#include <iostream>
#include <cstring>

Pessoa::Pessoa(string nome, string CPF) : nome(nome), CPF(CPF) {
    int qtde = 0;

    //Cria um array de carros
    memset(carros, 0, 3 * sizeof(Carro *));
    for (int i = 0; i < 3; i++){
        carros[i] = NULL;
    }
}

Pessoa::~Pessoa(){};

string Pessoa::getNome() const{
    return nome;
}

void Pessoa::setNome(string novo){
    nome = novo;
}

string Pessoa::getCPF() const{
    return CPF;
}

void Pessoa::setCPF(string novo){
    CPF = novo;
}

bool Pessoa::adicionaCarro(Carro* carro){
    bool ok = (qtde < 3);
    if (ok) {
        carros[qtde++] = carro;
        carro->setDono
    }

}

