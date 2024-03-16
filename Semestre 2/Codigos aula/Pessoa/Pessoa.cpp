#include "Pessoa.h"
//Não é necessário incluir iostream ou namespace std (já incluso no "Pessoa.h")

Pessoa::Pessoa(string nome, int idade) : nome(nome), idade(idade){

}

Pessoa::~Pessoa(){};

string Pessoa::getNome() const{
    return nome;
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

int Pessoa::getIdade() const{
    return idade;
}

void Pessoa::setIdade(int idade){
    this->idade = idade;
}

void Pessoa::imprime() const{
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << " anos" << endl;
}

int Pessoa::compare(const Pessoa &p2) const{ //sempre passar objetos por referência!
    return idade - p2.idade;
}
