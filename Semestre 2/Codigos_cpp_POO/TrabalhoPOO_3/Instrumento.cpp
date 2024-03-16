#include "Instrumento.h"

// Implementação dos métodos
// Construtor
Instrumento::Instrumento(string tipo, string marca, string modelo, double tam, int ano_fab, int estado) : tipo(tipo), marca(marca), modelo(modelo), tam(tam), ano_fab(ano_fab), estado(estado) {

}

// Destrutor
Instrumento::~Instrumento(){}

//Getters
// Retorna o tipo do instrumento
string Instrumento::getTipo() const {
    return tipo;
}

// Retorna a marca do instrumento
string Instrumento::getMarca() const {
    return marca;
}

// Retorna o modelo do instrumento
string Instrumento::getModelo() const {
    return modelo;
}

// Retorna o tamaho do instrumento
double Instrumento::getTam() const {
    return tam;
}

// Retorna o ano de fabricação do instrumento
int Instrumento::getAno() const {
    return ano_fab;
}

// Retorna o estado de uso do instrumento
int Instrumento::getEstado() const {
    return estado;
}

//Setters
// Altera o tipo do instrumento
void Instrumento::setTipo(string novo_tipo) {
    tipo = novo_tipo;
}

// Altera a marca do instrumento
void Instrumento::setMarca(string nova_marca) {
    marca = nova_marca;
}

// Altera o modelo do instrumento
void Instrumento::setModelo(string novo_modelo) {
    modelo = novo_modelo;
}

// Altera o tamanho do instrumento
void Instrumento::setTam(double novo_tam) {
    tam = novo_tam;
}

// Altera o ano de fabricação do instrumento
void Instrumento::setAno(int novo_ano) {
    ano_fab = novo_ano;
}

// Altera o estado do instrumento
void Instrumento::setEstado(int novo_estado) {
    estado = novo_estado;
}

// Compara os instrumentos a partir do ano de fabricação
bool Instrumento::comparaAno(const Instrumento* i1, const Instrumento* i2) {
    return (i1->ano_fab < i2->ano_fab);
}

// Outros Métodos
void Instrumento::imprime() const {
    string grupo;
    string status;

    cout << "Tipo: " << tipo << endl;
    cout << "Marca e Modelo: " << marca << " -> " << modelo << endl;
    cout << "Tamanho (cm): " << tam << endl;
    cout << "Ano de Fabricacao: " << ano_fab << endl;

    switch (this->getEstado()) {
        case 0: {
            status = "novo";
            break;
        }
        case 1: {
            status = "usado";
            break;
        }
    }

    cout << "Esse instrumento eh " << status << endl;

    switch (this->getGrupo()) {
        case CORDAS: {
            cout << "=== GRUPO 1 - CORDAS ===" << endl;
            break;
        }
        case MADEIRAS: {
            cout << "=== GRUPO 2 - MADEIRAS ===" << endl;
            break;
        }
    }
    
}