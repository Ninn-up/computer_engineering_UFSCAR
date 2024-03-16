#ifndef ALUNOS_H
#define ALUNOS_H
#include "Pessoa.h"
//Não é necessário incluir <string> ou "namespace std"

class Alunos : public Pessoa {
    public:
        Alunos(string nome, int idade, int RA);
        ~Alunos();
        int getRA() const;
        void setRA(int);
        void imprime() const;

    private:
        int RA;
};

#endif