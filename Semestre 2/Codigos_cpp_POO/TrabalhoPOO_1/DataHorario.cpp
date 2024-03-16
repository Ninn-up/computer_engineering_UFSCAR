#include "DataHorario.h"

namespace poo {

    DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) {

        bool ok = valida(dia, mes, ano, hora, minuto, segundo);
        
        if (!ok) {
            dia = mes = ano = 1;
            hora = minuto = segundo = 0;
        }
        
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
        this->hora = hora;
        this->minuto = minuto;
        this->segundo = segundo;
    }

    DataHorario::~DataHorario() {
        cout << "Destrutor DataHorario" << endl;
        this->imprime(false);
        cout << "---------------------------------------------------------" << endl;
    }

    bool DataHorario::valida(int dia, int mes, int ano, int hora, int minuto, int segundo) {
        bool ok;

        // checa faixa de valores [ano]

        ok = ano >= 0;

        // checa faixa de valores [mes]

        ok = ok && ((mes >= 1) && (mes <= 12));

        // checa faixa de valores [dia]

        ok = ok && ((dia >= 1) && (dia <= 31));

        // checa faixa de valores [hora]

        ok = ok && ((hora >= 0) && (hora <= 23));

        // checa faixa de valores [minuto]

        ok = ok && ((minuto >= 0) && (minuto <= 59));

        // checa faixa de valores [segundo]

        ok = ok && ((segundo >= 0) && (segundo <= 59));

        // checa a quantidade de dias do mês

        ok = ok && checaQtdeDias();
        
        return ok;
    }

    bool DataHorario::checaQtdeDias() {
        switch (mes) {
            case 2: {
                bool bissexto = (ano % 4 == 0 && ano % 100 != 0);
                bissexto = bissexto || ano % 400 == 0;
                return bissexto ? (dia <= 29) : (dia <= 28);
            }
            case 4:
            case 6:
            case 9:
            case 11: {
                return dia <= 30;
            }
            default: {
                return true;
            }
        }
    }

    void DataHorario::imprime(bool flag) {
        cout << setfill('0') << setw(2) << dia << "/";
        cout << setfill('0') << setw(2) << mes << "/";
        cout << setfill('0') << setw(4) << ano << " ";
        cout << setfill('0') << setw(2) << (flag ? hora % 12 : hora) << ":";
        cout << setfill('0') << setw(2) << minuto << ":";
        cout << setfill('0') << setw(2) << segundo;
        if (flag) {
            cout << ((hora >= 12) ? " PM" : " AM");
        }
        cout << endl;
    }
}
