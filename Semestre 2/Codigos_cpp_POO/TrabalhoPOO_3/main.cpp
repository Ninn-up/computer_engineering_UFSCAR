#include "Instrumento.h"
#include "Piano.h"
#include "FlautaDoce.h"
#include "Cadastro.h"
#include <iostream>

int main() {
    char op;
    string modelo;
    int grupo, estado;

    Cadastro cadastro("info.dat");

    do {
    op = Cadastro::opcao();

    switch (op) {
        case 'T': {
            cadastro.imprime();
            break;
        }
        case 'M': {
            cout << "Modelo: ";
            cin.ignore();
            getline(cin, modelo);
            cadastro.imprime(modelo);
            break;
        }
        case 'O': {
            cadastro.imprime(true);
            break;
        }
        case 'G': {
            cout << "Grupo: [1 - CORDAS / 2 - MADEIRAS] ";
            cin >> grupo;
            cadastro.imprimeGrupo(grupo - 1);
            break;
        }
        case 'E': {
            cout << "Estado: [0 - NOVO / 1 - USADO] ";
            cin >> estado;
            cadastro.imprimeEstado(estado);
            break;
        }
        case 'P': {
            cadastro.adiciona(CORDAS);
            break;
        }
        case 'F': {
            cadastro.adiciona(MADEIRAS);
            break;
        }
        case 'A': {
            cout << "Modelo: ";
            cin.ignore();
            getline(cin, modelo);
            bool ok = cadastro.atualiza(modelo);
            cout << "Atualizacao " << (ok ? "ok" : "nao realizada") << endl;
            break;
        }
        case 'R': {
            cout << "Modelo: ";
            cin.ignore();
            getline(cin, modelo);
            bool ok = cadastro.remove(modelo);
            cout << "Remocao " << (ok ? "ok" : "nao realizada") << endl;
            break;
        }
    }
    cout << endl << endl;

    } while (op != 'S');
    
    cout << "BOM CONCERTO!" << endl;

    return 0;
}
