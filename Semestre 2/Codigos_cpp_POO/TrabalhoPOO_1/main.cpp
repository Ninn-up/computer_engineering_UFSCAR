#include "Aluno.h"
#include "Companhia.h"
#include "DataHorario.h"
#include "Pessoa.h"
#include "Professor.h"
#include "Voo.h"

using namespace poo;
using namespace std;

int main() {

    cout << "========================== Ex 1 ==========================" << endl;

    Pessoa p1("920.160.912-40", "Bianca Débora Sara da Rocha");

    p1.imprime();
    
    cout << "========================== Ex 2 ==========================" << endl;
    
    Aluno* alunos[3];
    alunos[0] = new Aluno("700.879.680-37", "Manuela Giovanna da Rosa", 13579, 7, 7, 7, 7, 7);
    alunos[1] = new Aluno("767.692.493-67", "Renato Enrico Melo", 24680, 7, 5, 0, 6, 4);
    alunos[2] = new Aluno("287.624.030-01", "Raquel Milena da Luz", 12345, 3, 4, 5, 10, 6);

    for (int i = 0; i < 3; i++) {
        cout << "---------------------------------------------------------" << endl;
        alunos[i]->imprime();
        cout << "[Final] ";
        if (alunos[i]->aprovado()) {
            cout << "Aluno aprovado" << endl;
        } else if (alunos[i]->sac()) {
            cout << "(SAC) Nota mínima: " << alunos[i]->notaSAC() << endl;
        } else {
            cout << "Aluno reprovado" << endl;
        }
    }
    
    cout << "---------------------------------------------------------" << endl;

    cout << "========================== Ex 3 ==========================" << endl;

    Professor prof1("357.902.468-13", "Joao Santos Martins", "UFSCar");
    prof1.imprime();

    cout << "========================== Ex 4 ==========================" << endl;

    DataHorario dh(31, 8, 2019, 15, 57, 10);
    Companhia cia("Verde", "85.601.994/0001-54");
    Voo voo(cia, "São Paulo", "Londres", dh);

    voo.imprime();

    cout << endl;

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, p1);
    }

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, *alunos[0]);
    }

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, *alunos[1]);
    }

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, *alunos[0]);
    }

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, *alunos[1]);
    }

    if (voo.proximoLivre() == "cheio") {
        cout << "Voo Cheio" << endl;
    }
    
    voo.imprime();

    cout << endl;

    for (int i = 1; i <= 5; i++) {
        string s;
        for (int j = 0; j < 6; j++) {
            s = to_string(i);
            s.append(1, ((char) ('A' + j)));
            s.insert(0, 3 - s.size(), '0');
            voo.desocupa(s);
        }
    }

    for (int i = 11; i <= 15; i++) {
        string s;
        for (int j = 0; j < 6; j++) {
            s = to_string(i);
            s.append(1, ((char) ('A' + j)));
            s.insert(0, 3 - s.size(), '0');
            voo.desocupa(s);
        }
    }

    for (int i = 21; i <= 25; i++) {
        string s;
        for (int j = 0; j < 6; j++) {
            s = to_string(i);
            s.append(1, ((char) ('A' + j)));
            s.insert(0, 3 - s.size(), '0');
            voo.desocupa(s);
        }
    }

    if (voo.proximoLivre() == "cheio") {
        cout << "Voo Cheio" << endl;
    }

    voo.imprime();

    cout << endl;

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, prof1);
    }

    for (int i = 0; i < 30; i++) {
        string s = voo.proximoLivre();
        voo.ocupa(s, *alunos[2]);
    }

    if (voo.proximoLivre() == "cheio") {
        cout << "Voo Cheio" << endl;
    }

    voo.imprime();
    
    cout << "========================== Ex 5 ==========================" << endl;
    cia.imprime();
    cout << "==========================================================" << endl;
    cout << "---------------------------------------------------------" << endl;
       
    for (int i = 0; i < 3; i++) {
        delete alunos[i];
    }
}
