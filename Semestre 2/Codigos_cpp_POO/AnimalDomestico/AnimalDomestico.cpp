#include "AnimalDomestico.h"

//Construtor
AnimalDomestico::AnimalDomestico(string nome, double peso) : nome(nome), peso(peso), dono(NULL) {
    cout << "Construindo Animal: " << nome << endl;

}

//Destrutor
AnimalDomestico::~AnimalDomestico(){};

string AnimalDomestico::getNome() const {
    return nome;
}

double AnimalDomestico::getPeso() const {
    return peso;
}

Pessoa* AnimalDomestico::getDono() const {
    return dono;
}

void AnimalDomestico::setNome(string novoNome) {
    nome = novoNome;
}

void AnimalDomestico::setPeso(double novoPeso) {
    peso = novoPeso;
}

void AnimalDomestico::setDono(Pessoa* novoDono) {
    dono = novoDono;
}

void AnimalDomestico::imprime() const {
    cout << "Nome do Animal: " << nome << endl;
    cout << "Peso do Animal: " << peso << endl;
    
}