#include "Carro.h"

// Construtor
Carro::Carro(string placa, string marca, string cor, int ano, double volume) : Veiculo(placa, marca, cor, ano), volume(volume) {

}

//Destrutor
Carro::~Carro(){}

// Retorna o volume do porta-malas do carro
double Carro::getVolume() const {
    return volume;
}

// Altera o valor do volume do porta-malas do carro
void Carro::setVolume(double novo_volume) {
    volume = novo_volume;
}

// Implementação do método abstrato
    // Retorna a categoria do veículo (no caso, 1)
int Carro::getCategoria() const {
    return 1;
}

// Imprime a placa, a marca, a cor, o ano, a categoria e o volume do porta-malas do carro
void Carro::imprime() const {
    Veiculo::imprime();
    cout << "Volume do Porta-Malas: " << volume << endl;
}