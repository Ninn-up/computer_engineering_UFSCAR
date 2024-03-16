#include "Piano.h"

// Implementação dos métodos
// Construtor
Piano::Piano(string tipo, string marca, string modelo, double tam, int ano_fab, int estado, int qtde_teclas, string tipo_teclas) : Instrumento(tipo, marca, modelo, tam, ano_fab, estado), qtde_teclas(qtde_teclas), tipo_teclas(tipo_teclas) {

}

// Destrutor
Piano::~Piano(){}

// Getters
// Retorna a quantidade de teclas do piano
int Piano::getQtde() const {
    return qtde_teclas;
}

// Retorna o tipo de teclas do piano
string Piano::getTipoTeclas() const {
    return tipo_teclas;
}

// Informa qual grupo do instrumento na orquestra
int Piano::getGrupo() const {
    return CORDAS;
}

// Setters
// Altera o número de teclas do piano
void Piano::setQtde(int nova_qtde) {
    qtde_teclas = nova_qtde;
}

// Altera o tipo de teclas do piano
void Piano::setTipoTeclas(string novo_tipo) {
    tipo_teclas = novo_tipo;
}

// Imprime as informações do Piano
void Piano::imprime() const {
    cout << "PIANO ---- INFORMACOES" << endl;
    cout << "========================" << endl;

    Instrumento::imprime();
    
    cout << "Quantidade de Teclas: " << qtde_teclas << " (" << (qtde_teclas / 12) << " OITAVAS)" << endl;
    cout << "Tipo de Teclas: " << tipo_teclas << endl;
}

