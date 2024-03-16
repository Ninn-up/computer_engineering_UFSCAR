#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>
#include <string>

using namespace std;

enum GRUPO { CORDAS, MADEIRAS };

class Instrumento {
    public:

        Instrumento(string, string, string, double, int, int);  //Construtor
        virtual ~Instrumento();  // Destrutor

        // Getters e Setters
        string getTipo() const;
        string getMarca() const;
        string getModelo() const;
        double getTam() const;
        int getAno() const;
        int getEstado() const;
        void setTipo(string);
        void setMarca(string);
        void setModelo(string);
        void setTam(double);
        void setAno(int);
        void setEstado(int);

        // Outros Métodos
        virtual int getGrupo() const = 0; // Método abstrato

        virtual void imprime() const;
        static bool comparaAno(const Instrumento* i1, const Instrumento* i2);


    private:
        string tipo;
        string marca;
        string modelo;
        double tam;
        int ano_fab;
        int estado;

};

#endif