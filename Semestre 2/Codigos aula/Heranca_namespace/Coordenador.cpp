#include "Coordenador.h"

namespace poo {
    Coordenador:: Coordenador(string nome, int CPF, float salario, string curso) : Professor(nome, CPF, salario), curso(curso){

    }

    Coordenador::~Coordenador(){};

    float Coordenador::getSalario() const {
        return salario + 2000;
    }

    string Coordenador::getCurso() const {
        return curso;
    }

    void Coordenador:: imprime() const{
        Professor::imprime();
        cout << "Curso: " << curso << endl;
    }
}