#include "Cachorro.h"

Cachorro::Cachorro(string nome, double peso, string raca) : AnimalDomestico(nome, peso), raca(raca) {

}

Cachorro::~Cachorro(){}

string Cachorro::getRaca() const{
    return raca;
}

void Cachorro::setRaca(string novo) {
    raca = novo;
}

void Cachorro::imprime() const {
    AnimalDomestico::imprime();
    cout << "Espécie: Cachorro" << endl;
    cout << "Raça: " << raca << endl;
}