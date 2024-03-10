#ifndef VENDA_H
#define VENDA_H

#include <iostream>
using namespace std;

class Venda {
private:
    int id; // id do produto
    int quantidade;
    double valor;
public:
    Venda();
    int getID() const;
    void setID(int produto);
    int getQuantidade() const;
    void setQuantidade(int quantidade);
    double getValor() const;
    void setValor(double valor);
    virtual void imprime() const;
};

#endif /* VENDA_H */