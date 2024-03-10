#include "Pessoa.h"
#include <string>
#include <iostream>

using namespace std;

//"Classe(str, int)"
Pessoa::Pessoa(string nome, int idade){
    //O método atribui a um objeto, da classe específica, determinados atributos fornecidos
    this->nome = nome;
    this->idade = idade;

}

//Lê o "nome" no objeto
string Pessoa::getNome(){
    //Devolve o atributo "nome" do objeto
    return this->nome;

}

//Lê a "idade" no objeto
int Pessoa::getIdade(){
    //Devolde o atributo "idade" do objeto
    return this->idade;
}

//Altera o "nome" do objeto 
void Pessoa::setNome(string nome){
    this->nome = nome;

}

//Altera a "idade" do objeto
void Pessoa::setIdade(int idade){
    this->idade = idade;
}

//Impride os dados do objetonome
void Pessoa::imprime(){
    cout << "Nome: " << this->nome << endl;
    cout << "Idade: " << this->idade << endl;
    cout << endl;

}

//Compara qual das idades é maior
bool Pessoa::maior(Pessoa outra){
    //Verifica qual das pessoas tem a maior idade e retorna "True"/"False"
    return this->idade > outra.idade;
}