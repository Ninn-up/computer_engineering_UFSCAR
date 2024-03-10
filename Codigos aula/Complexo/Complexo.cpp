#include "Complexo.h"

Complexo::Complexo (double real, double imaginaria){
    this->real = real;
    this->imaginaria = imaginaria;

}

Complexo::~Complexo(){};

Complexo Complexo::operator+(const Complexo& obj) const {
        double r = this-> real + obj.real;
        double i = this-> imaginaria + obj.imaginaria;
        return Complexo(r, i);
}

Complexo Complexo::operator-() const{
    return Complexo (-this->real, -this->imaginaria);

};

Complexo Complexo::operator-(const Complexo& obj) const{
    return *this + (-obj);

}

Complexo Complexo::operator*(const Complexo& obj) const{
    double a = this->real;
    double b = this->imaginaria;
    double c = obj.real;
    double d = obj.imaginaria;

    double r = (a * c + b * d) / (c * c + d * d);
    double i = (b * c - a * d) / (c * c + d * d);

    return Complexo(r, i);

}

Complexo Complexo::operator/(const Complexo& obj) const{
    double a = this->real;
    double b = this->imaginaria;
}



