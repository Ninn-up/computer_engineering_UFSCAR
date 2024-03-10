#ifndef ANIMALDOMESTICO_H
#define ANIMALDOMESTICO_H

//Como "Animal" não é destruído quando "Pessoa" é destruído, parece melhor adicionar as bibliotecas necessárias
#include <string>
#include <iostream>
using namespace std;

class Pessoa;

class AnimalDomestico {
    public:
        AnimalDomestico(string, double);
        ~AnimalDomestico();
        string getNome() const;
        double getPeso() const;
        Pessoa* getDono() const;
        void setNome(string);
        void setPeso(double);
        void setDono(Pessoa* dono);
        virtual void imprime() const;

    private:
        string nome;
        double peso;
        Pessoa *dono;

};

#endif