#include "FlautaDoce.h"

// Implementação dos métodos
// Construtor
FlautaDoce::FlautaDoce(string tipo, string marca, string modelo, double tam, int ano_fab, int estado, string material, string estilo) : Instrumento(tipo, marca, modelo, tam, ano_fab, estado), material(material), estilo(estilo) {

}

// Destrutor
FlautaDoce::~FlautaDoce(){}

// Getters
// Retorna o material de que é feita a Flauta
string FlautaDoce::getMaterial() const {
    return material;
}

// Retorna o estilo do som da flauta
string FlautaDoce::getEstilo() const {
    return estilo;
}

// Retorna o grupo ao qual a Flauta pertence na orquestra
int FlautaDoce::getGrupo() const {
    return MADEIRAS;
}

// Setters
// Altera o material do qual é feita a Flauta
void FlautaDoce::setMaterial(string novo_material) {
    material = novo_material;
}

// Altera o estilo de som que a Flauta produz
void FlautaDoce::setEstilo(string novo_estilo) {
    estilo = novo_estilo;
}

// Imprime as informações de uma flauta
void FlautaDoce::imprime() const {
    cout << "FLAUTA DOCE ---- INFORMACOES" << endl;
    cout << "============================" << endl;
    
    Instrumento::imprime();

    cout << "Material: " << material << endl;
    cout << "Estilo: " << estilo << endl;
    
}