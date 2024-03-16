#ifndef CAMINHAO_H
#define CAMINHAO_H

#include "Veiculo.h"

class Caminhao : public Veiculo {
    public:
        Caminhao(string placa, string marca, string cor, int ano, int eixos); // Construtor
        virtual ~Caminhao(); // Destrutor

        // Getters e Setters
        int getEixos() const;
        void setEixos(int);

        virtual int getCategoria() const; // Método abstrato a ser implementado
        
        virtual void imprime() const;

    private:
        int eixos;

};

#endif