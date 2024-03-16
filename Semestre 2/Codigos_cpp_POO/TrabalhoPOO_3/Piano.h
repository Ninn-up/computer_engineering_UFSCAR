#ifndef PIANO_H
#define PIANO_H

#include "Instrumento.h"

class Piano : public Instrumento {
    public:
        Piano(string, string, string, double, int, int, int, string);  // Construtor
        virtual ~Piano();  // Destrutor

        // Getters and Setters
        int getQtde() const;
        string getTipoTeclas() const;
        void setQtde(int);
        void setTipoTeclas(string);

        // Outros métodos
        virtual void imprime() const;
        virtual int getGrupo() const;  // Método abstrato a ser implementado

    private:
        int qtde_teclas;
        string tipo_teclas;
};
#endif