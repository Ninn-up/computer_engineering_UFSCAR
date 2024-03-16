// Classe pessoa
//Evita que, caso ocorra repetição de declaração da classe, o código não funcione
/*
#ifndef PESSOA_H
#define PESSOA_H
*/

#include <string>

using namespace std;

class Pessoa
{
public:
    // Métodos da classe
    Pessoa(string, int);
    string getNome();
    void setNome(string);
    int getIdade();
    void setIdade(int);
    void imprime(); // imprime os valores dos atributos
    bool maior(Pessoa outra);

private:
    // Atributos da classe
    string nome;
    int idade;
};

//#endif /*PESSOA.H*/