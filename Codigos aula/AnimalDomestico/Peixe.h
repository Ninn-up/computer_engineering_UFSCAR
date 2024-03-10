#ifndef PEIXE_H
#define PEIXE_H

#include "AnimalDomestico.h"

class Peixe : public AnimalDomestico {
    public:
        Peixe(string, double, string);
        ~Peixe();
        string getHabitat() const;
        void setHabitat(string);
        void imprime() const;
        
    private:
        string tipoHabitat;
    
};

#endif