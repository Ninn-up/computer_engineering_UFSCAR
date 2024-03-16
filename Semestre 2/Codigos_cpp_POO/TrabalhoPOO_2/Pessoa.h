#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Veiculo.h"

using namespace std;

class Pessoa {
    public:
        Pessoa(string nome, string CPF); // Construtor
        virtual ~Pessoa(); // Destrutor

        // Getters e Setters
        string getNome() const;
        string getCPF() const;
        void setNome(string);
        void setCPF(string);

        // Métodos sobre os veículos
        bool adicionaVeiculo(Veiculo& veiculo);
        bool removeVeiculo(string placa);
        Veiculo* obtemVeiculo(string placa) const;
        int qtdeVeiculos() const;
        int qtdeCarros() const;
        int qtdeCaminhoes() const;

        // Métodos de Comparação
        bool static comparaPlaca(Veiculo*, Veiculo*);
        bool static comparaAno(Veiculo*, Veiculo*);
        bool static comparaCategoria(Veiculo*, Veiculo*);

        void imprime(int criterio);

    private:
        string nome;
        string CPF;
        vector <Veiculo*> frota;
};

#endif