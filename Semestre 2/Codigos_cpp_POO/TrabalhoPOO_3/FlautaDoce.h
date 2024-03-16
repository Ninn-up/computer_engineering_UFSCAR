#ifndef FLAUTADOCE_H
#define FLAUTADOCE_H

#include "Instrumento.h"

class FlautaDoce : public Instrumento {
    public:
        FlautaDoce(string, string, string, double, int, int, string, string); // Construtor
        virtual ~FlautaDoce();  // Destrutor

        // Getters and Setters
        string getMaterial() const;
        string getEstilo() const;
        void setMaterial(string);
        void setEstilo(string);

        // Outros métodos
        virtual int getGrupo() const;  // Método abstrato a ser implementado 
        virtual void imprime() const;

    private:
        string material;
        string estilo;
};

#endif