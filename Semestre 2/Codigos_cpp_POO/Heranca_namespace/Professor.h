#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"

namespace poo{
    class Professor : public Pessoa {
        public:
            Professor(string, int, float);
            ~Professor();
            virtual float getSalario() const;
            virtual void imprime() const;

        private:
        float salario;
    };
}

#endif