#include "Caminhao.h"

// Construtor
Caminhao::Caminhao(string placa, string marca, string cor, int ano, int eixos) : Veiculo(placa, marca, cor, ano), eixos(eixos) {

}

// Destrutor
Caminhao::~Caminhao(){};

// Retorna o número de eixos do caminhão
int Caminhao::getEixos() const {
    return eixos;
}

// Altera o número eixos do caminhão
void Caminhao::setEixos(int novo_eixo) {
    eixos = novo_eixo;
}

// Implementação do método abstrato
    // Retorna a categoria do caminhão (no caso, 2)
int Caminhao::getCategoria() const {
    return 2;
}

// Imprime a placa, a marca, a cor, o ano, a categoria e o número de eixos do caminhão
void Caminhao::imprime() const {
    Veiculo::imprime();
    cout << "Número de Eixos do Caminhão: " << eixos << endl;
}
