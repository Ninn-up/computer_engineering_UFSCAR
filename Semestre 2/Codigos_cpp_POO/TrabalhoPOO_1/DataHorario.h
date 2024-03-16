#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

namespace poo {

    class DataHorario {
    public:
        DataHorario(int, int, int, int, int, int);
        virtual ~DataHorario();
        void imprime(bool);
    private:
        bool valida(int, int, int, int, int, int);
        bool checaQtdeDias();
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;
        int segundo;
    };
}
#endif /* DATAHORARIO_H */
