#include "Data.h"
#include <iostream>
#include <string>

//Inclui o setfill (determina com que caractere será preenchido o espaço restante) e o setw(determina a quantidade de espaços disponíveis para escrever uma variável)
#include <iomanip>

using namespace std;

//Construção dos métodos
Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano){

}

Data::~Data(){};

void Data::imprime(){
    cout << setfill('0') << setw(2) << this->dia << "/" << setfill('0') << setw(2) << this->mes << "/" << this->ano << endl;

}

void Data::imprimePorExtenso(){
    string meses[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "setembro", "Outubro", "Novembro", "Dezembro"};

    cout << setfill('0') << setw(2) << this->dia << " de " << meses[this->mes - 1] << " de " << setfill('0') << setw(4) << this->ano << endl;

}

bool Data::anoBissexto(){
    if (ano % 4 == 0 && ano % 100 != 0 && ano % 400 == 0){
        return true;

    }
    else{
        return false;
    }
}

int Data::compara(const Data& outra){
    int d1, d2;
    d1 = this->ano * 10000 + this->mes * 100 + this->dia;
    d2 = outra.ano * 10000 + outra.mes * 100 + outra.dia;

    return d1 - d2;
}