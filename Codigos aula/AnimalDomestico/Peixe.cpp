#include "Peixe.h"

//Construtor
Peixe::Peixe(string nome, double peso, string tipoHabitat) : AnimalDomestico(nome, peso), tipoHabitat(tipoHabitat){

}
//Destrutor
Peixe::~Peixe(){}

string Peixe::getHabitat() const {
    return tipoHabitat;
}

void Peixe::setHabitat(string novo) {
    tipoHabitat = novo;
}

void Peixe::imprime() const{
    AnimalDomestico::imprime();
    cout << "Espécie: Peixe" << endl;
    cout << "Tipo de Habitat: " << tipoHabitat << endl;
}