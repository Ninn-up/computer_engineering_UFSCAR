#ifndef VOO_H
#define VOO_H

#include "Companhia.h"
#include "DataHorario.h" 
#include "Pessoa.h"
#include <iostream>
#include <string>

namespace poo {
    class Voo {
        public:
            Voo(Companhia &cia, string origem, string destino, DataHorario& dh);  //Construtor
            ~Voo();  //Destrutor
            string proximoLivre() const;
            bool verifica(string) const;
            bool ocupa(string, Pessoa&); 
            bool desocupa(string); 
            int vagas() const;
            void imprime() const;

        private:
            Companhia& cia;
            string origem;
            string destino;
            DataHorario& dh;
            Pessoa* poltronas[25][6];  //As poltronas do avião
            int poltVagas;  //O número de poltronas vagas no avião
    };
}

#endif