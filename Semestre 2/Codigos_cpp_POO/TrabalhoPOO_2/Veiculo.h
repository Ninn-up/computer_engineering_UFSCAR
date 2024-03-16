#ifndef VEICULO_H
#define VEICULO_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa;

class Veiculo {
    public:
        Veiculo(string placa, string marca, string cor, int ano); // Construtor
        virtual ~Veiculo(); // Destrutor
        
        // Getters e Setters
        string getPlaca() const;
        string getMarca() const;
        string getCor() const;
        int getAno() const;
        Pessoa* getDono() const;
        void setPlaca(string);
        void setMarca(string);
        void setCor(string);
        void setAno(int);
        void setDono(Pessoa* dono);

        virtual int getCategoria() const = 0;  // Método Abstrato

        virtual void imprime() const;

    private:
        string placa;
        string marca;
        string cor;
        int ano;
        Pessoa* dono;

};

#endif
