#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Pessoa.h"

namespace poo {
    class Professor : public Pessoa {
        public:
            Professor(string CPF, string nome, string universidade);  //Construtor
            ~Professor();  //Destrutor
            string getUniversidade() const;
            void imprime() const;
            
        private:
            string universidade;

    };
}

#endif