#ifndef PESSOA_H
#define PESSOA_H

using namespace std;
#include <string>
#include <iostream>

namespace poo{
    class Pessoa{
        public:
            Pessoa(string CPF, string nome); //Construtor
            ~Pessoa(); //Destrutor
            string getCPF() const;
            string getNome() const;
            virtual void imprime() const;

        private:
            string CPF;
            string nome;
    };
}

#endif