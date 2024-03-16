#include "Conta.h"
#include <iostream>

using namespace std;

//Construção dos Métodos
Conta::Conta(int numero, double saldo){
    cout << "Construindo Conta " << numero << endl;
    this->numero = numero;
    this->saldo = saldo;

}

Conta::~Conta(){
    cout << "Destruindo Conta " << numero << endl;
};


bool Conta::retirada(double saque){
    if (saque > saldo){
        return false;

    }
    else{
        saldo -= saque;
        return true;
    }

}

bool Conta::transferencia(Conta &destino, double valor){

    //Verificação da operação de retirada
    bool ok = this->retirada(valor);

    if (ok){
        //Depositar o valor retirado na conta destino
        destino.deposito(valor);

    }

    return ok;
    
}
bool Conta::deposito(double valor){
    if (valor <= 0){
        return false;
    }
    else{
        saldo += valor;
        return true;
    }
    

}

void Conta::imprime(){
    cout << "Nro: " << this->numero << endl;
    cout << "Saldo: R$" << this->saldo << endl;
    cout << endl;

}
