#include "Triangulo.h"
#include <cmath>
#include <iostream>

using namespace std;

int Triangulo::contador = 0;

Triangulo::Triangulo(double l1, double l2, double l3)
{
    // Não precisa do "this->" pois possuem nomes diferentes
    l[0] = l1;
    l[1] = l2;
    l[2] = l3;
}

Triangulo::Triangulo(double lado):Triangulo(lado, lado, lado){

}

Triangulo::~Triangulo(){};

int Triangulo::compare(Triangulo t){
    if (this->getArea() < t.getArea()) {
        return -1;
    }
    else if (this->getArea() > t.getArea()) {
        return 1;
    }
    else{
        return 0;
    }
    
}

double Triangulo::getPerimeter()
{
    double soma = 0;
    for (int i = 0; i < 3; i++)
    {
        soma += l[i];
    }

    return soma;
}

double Triangulo::getArea()
{
    // Utiliza-se o "this->" para informar que
    double area = 1;
    double semi = this->getPerimeter() / 2;

    for (int i = 0; i < 3; i++)
    {
        area *= semi - l[i];
    }

    return sqrt(semi*area);
}

void Triangulo::imprime(){
    cout << "Area: " << this->getArea() << endl;

}

int Triangulo::getContador(){
    return Triangulo::contador;

}

void Triangulo::incrementa(){
    Triangulo::contador++;
}

void Triangulo::decrementa(){
    Triangulo::contador--;
}
