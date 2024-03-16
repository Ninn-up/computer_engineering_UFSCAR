#include <iostream>
#include "Data.h"

using namespace std;

int main(){
    Data d1(20, 8, 2019);
    Data d2(20, 8, 2018);
    d1.imprime();
    d1.imprimePorExtenso();
    
}