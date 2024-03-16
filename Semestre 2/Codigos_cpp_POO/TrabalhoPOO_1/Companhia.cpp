#include "Companhia.h"

namespace poo{
    //Construtor
    Companhia::Companhia(string nome, string CNPJ) : nome(nome), CNPJ(CNPJ){
    } 

    //Destrutor
    Companhia::~Companhia(){}

    //Retorna o CNPJ da companhia aérea
    string Companhia::getCNPJ() const {
        return CNPJ;
    }

    //Retorna o nome da companhia aérea
    string Companhia::getNome() const {
        return nome;
    }

    //Imprime o CNPJ e o nome da companhia aérea
    void Companhia::imprime() const {
        cout << "Nome da Companhia: " << nome << endl;
        cout << "CNPJ: " << CNPJ << endl;
    }
}