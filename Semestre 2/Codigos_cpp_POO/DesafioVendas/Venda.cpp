#include "Venda.h"

Venda::Venda(){}

int Venda::getID() const {
    return this->id;
}

void Venda::setID(int id) {
    this->id = id;
}

int Venda::getQuantidade() const {
    return this->quantidade;
}

void Venda::setQuantidade(int quantidade) {
    this->quantidade = quantidade;
}

double Venda::getValor() const {
    return this->valor;
}

void Venda::setValor(double valor) {
    this->valor = valor;
}

void Venda::imprime() const {
    cout << "ID: " << id;
    cout << ", Qtde: " << quantidade;
    cout << ", Valor: " << valor << endl;
}