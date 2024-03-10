#include <iostream>
#include "Equilatero.h"
#include "Triangulo.h"

using namespace std;

int main(){
    Triangulo t1(3, 4, 5);
    Triangulo t2(10, 35, 40);
    Equilatero e1(3);

    t1.imprime();
    t2.imprime();
    e1.imprime();

}