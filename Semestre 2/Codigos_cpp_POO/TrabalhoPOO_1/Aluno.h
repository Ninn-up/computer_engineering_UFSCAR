#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"

namespace poo{
    class Aluno : public Pessoa {
        public:
            Aluno(string CPF, string nome, int RA, double p1, double p2, double t1, double t2, double t3); //Construtor
            ~Aluno(); //Destrutor
            int getRA() const;
            void imprime() const;
            double media() const;
            bool aprovado() const;
            bool sac() const;
            double notaSAC() const;
        
        private:
            int RA;
            double p1;
            double p2;
            double t1;
            double t2;
            double t3;

    };
}

#endif