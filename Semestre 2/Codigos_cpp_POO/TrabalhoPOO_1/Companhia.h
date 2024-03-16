#ifndef COMPANHIA_H
#define COMPANHIA_H
#include <string>
#include <iostream>

using namespace std;

namespace poo{
    class Companhia {
    public:
        Companhia(string nome, string CNPJ);  //Construtor
        ~Companhia();  //Destrutor
        string getCNPJ() const;
        string getNome() const;
        void imprime() const;

    private:
        string nome;
        string CNPJ;
    };
}

#endif