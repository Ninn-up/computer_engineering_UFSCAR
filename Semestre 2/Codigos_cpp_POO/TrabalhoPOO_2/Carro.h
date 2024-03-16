#ifndef CARRO_H
#define CARRO_H

#include "Veiculo.h"

class Carro : public Veiculo {
    public:
        Carro(string placa, string marca, string cor, int ano, double volume); // Construtor
        virtual ~Carro(); // Destrutor

        // Getters e Setters
        double getVolume() const;
        void setVolume(double);

        virtual int getCategoria() const; // Método abstrato a ser implementado

        virtual void imprime() const;
    
    private:
        double volume;
        
};

#endif