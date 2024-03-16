#include "Conta.h"
#include <iostream>

using namespace std;

int main(){
    Conta c1(111111, 10000.50);
    Conta c2(400289, 15000.80);

    cout << endl;
    
    c1.imprime();
    cout << "========================" << endl;
    c2.imprime();

    cout << "=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;

    if (c1.deposito(7000.00)){
        cout << "Você depositou R$7000.00" << endl; 
    }

    if (c2.retirada(7000.00)){
        cout << "Você retirou R$7000.00" << endl;
    }
    else{
        cout << "Não foi possível sacar o dinheiro! Tente novamente" << endl;
    }

    c1.imprime();
    cout << "========================" << endl;
    c2.imprime();

    cout << "=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;

    if (c1.transferencia(c2, 2000.00)){
        cout << "A transferência foi realizada com sucesso!" << endl;

    }
    else{
        cout << "A transferência não pôde ser concluída, tente novamente" << endl;
    }

    c1.imprime();
    cout << "========================" << endl;
    c2.imprime();

    cout << "=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;

    if (c2.transferencia(c1, 12000)){
        cout << "A transferência foi realizada com sucesso!" << endl;

    }
    else{
        cout << "A transferência não pôde ser concluída, tente novamente" << endl;
    }

    c1.imprime();
    cout << "========================" << endl;
    c2.imprime();

    cout << "=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
    
}