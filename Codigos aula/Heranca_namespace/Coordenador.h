#ifndef COORDENADOR_H
#define COORDENADOR_H

#include "Professor.h"

namespace poo {
    class Coordenador : public Professor {
        public:
            Coordenador(string, int, float, string);
            ~Coordenador();
            float getSalario() const;
            string getCurso() const;
            void imprime() const;
        private:
            float salario;
            string curso;

    };
}

#endif
