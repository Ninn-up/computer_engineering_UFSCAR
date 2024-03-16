#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Pessoa.h"
//Não é necessário incluir "namespace std"

class Professor : public Pessoa{
    public:
        Professor(string nome, int idade, float salario);
        ~Professor();
        float getSalario() const;
        void setSalario(float valor);
        void imprime() const;

    private:
        float salario;
};

#endif