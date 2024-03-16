#include "Equilatero.h"
#include <cmath>
using namespace std;

Equilatero::Equilatero(double l) : Triangulo(l, l, l){
}

Equilatero::~Equilatero(){}

double Equilatero::getArea(){
    double area;
    area = (pow(l[0], 2) * sqrt(3))/4;
    return area;
}

