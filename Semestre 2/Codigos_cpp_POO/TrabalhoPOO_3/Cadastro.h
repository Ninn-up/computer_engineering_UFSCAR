#ifndef CADASTRO_H
#define CADASTRO_H

#include "Instrumento.h"
#include "Piano.h"
#include "FlautaDoce.h"
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Cadastro {
    public:
    Cadastro(string fileName);  // Construtor
    virtual ~Cadastro();  // Destrutor
    // Métodos de adicionar, atualizar e remover
    bool adiciona(int grupo);
    bool atualiza(string modelo);
    bool remove(string modelo);

    // Métodos de impressão
    void imprime(string modelo);
    void imprimeGrupo(int grupo);
    void imprimeEstado(int estado);
    void imprime(bool sorted = false);

    static char opcao();

    private:
        // Métodos de leitura e gravação no arquivo binário
        void grava();
        void le();
        int indice(string modelo);

        // Atributos
        string fileName;
        vector<Instrumento *> instrumentos;
};

#endif