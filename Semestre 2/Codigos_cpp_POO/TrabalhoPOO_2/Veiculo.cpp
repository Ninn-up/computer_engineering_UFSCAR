#include "Veiculo.h"
// Construtor
Veiculo::Veiculo(string placa, string marca, string cor, int ano) : placa(placa), marca(marca), cor(cor), ano(ano) {

}

// Destrutor
Veiculo::~Veiculo(){}

// Retorna a placa do veículo
string Veiculo::getPlaca() const {
    return placa;
}

// Retorna a marca do veículo
string Veiculo::getMarca() const {
    return marca;
}

// Retorna a cor do veículo
string Veiculo::getCor() const {
    return cor;
}

// Retorna o ano do veículo
int Veiculo::getAno() const {
    return ano;
}

// Retorna o dono do veículo
Pessoa * Veiculo::getDono() const {
    return dono;
}

// Altera a placa do veículo
void Veiculo::setPlaca(string nova_placa) {
    placa = nova_placa;
}

// Altera a marca do veículo
void Veiculo::setMarca(string nova_marca) {
    marca = nova_marca;
}

// Altera a cor do veículo
void Veiculo::setCor(string nova_cor) {
    cor = nova_cor;
}

// Altera o ano do veículo
void Veiculo::setAno(int novo_ano) {
    ano = novo_ano;
}

void Veiculo::setDono(Pessoa* novo_dono) {
    dono = novo_dono;

}

// Imprime a placa, a marca, a cor, o ano e a categoria do veículo
void Veiculo::imprime() const {
    cout << "Placa do Veículo: " << placa << endl;
    cout << "Marca: " << marca << endl;
    cout << "Cor: " << cor << endl;
    cout << "Ano: " << ano << endl;
    cout << "Categoria: " << this->getCategoria() << endl;

}