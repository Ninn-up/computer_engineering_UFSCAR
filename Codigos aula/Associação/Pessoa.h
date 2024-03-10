#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include "Carro.h"
using namespace std;

class Pessoa{
    public:
        Pessoa(string nome, string CPF);
        ~Pessoa();
        string getNome() const;
        void setNome(string nome);
        string getCPF() const;
        void setCPF(string nome);
        bool adicionaCarro(Carro* carro);
        Carro* removeCarro(string placa);
        void imprime() const;

    private:
        string nome;
        string CPF;
        //Atributos relacionados a Carro
        Carro* carros[3];
        int qtde;

};

#endif