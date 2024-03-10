#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>

using namespace std;

namespace poo{
    class Pessoa{
        public:
            Pessoa(string, int); 
            ~Pessoa();
            string getNome() const;
            int getCPF() const;
            virtual void imprime() const;
        
        private:
            string nome;
            int CPF;
    };
}

#endif