#ifndef CACHORRO_H
#define CACHORRO_H

#include "AnimalDomestico.h"

class Cachorro : public AnimalDomestico {
    public:
        Cachorro(string, double, string);
        ~Cachorro();
        string getRaca() const;
        void setRaca(string);
        void imprime() const;

    private:
        string raca;
};

#endif