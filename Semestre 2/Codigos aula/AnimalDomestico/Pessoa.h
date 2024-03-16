#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <iostream>
#include "AnimalDomestico.h"

#define MAX 3

using namespace std;

class Pessoa{
    public:
        Pessoa(string nome, int idade);
        ~Pessoa();
        string getNome() const;
        void setNome(string);
        int getIdade() const;
        void setIdade(int);
        void adicionaAnimal(AnimalDomestico*);
        void removeAnimal(string);
        void imprime() const;

    private:
        string nome;
        int idade;
        AnimalDomestico * pets[MAX];
        int quantPets;
};

#endif