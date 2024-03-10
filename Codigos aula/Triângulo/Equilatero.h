#ifndef EQUILATERO_H
#define EQUILATERO_H

#include "Triangulo.h"

using namespace std;

class Equilatero : public Triangulo{
    public:
        Equilatero(double l);
        ~Equilatero();
        double getArea();

    //private: não é necessário definir os atributos dele
    //    double l;
        
};

#endif