#include "Aluno.h"

namespace poo{
    //Construtor
    Aluno::Aluno(string CPF, string nome, int RA, double p1, double p2, double t1, double t2, double t3) : Pessoa(CPF, nome), RA(RA), p1(p1), p2(p2), t1(t1), t2(t2), t3(t3){
    }

    //Destrutor
    Aluno::~Aluno(){};

    //Retorna o RA do aluno
    int Aluno::getRA() const{
        return RA;
    }

    //Calcula a média final
    double Aluno::media() const{
        double mf;
        double mp;
        double mt;

        mp = (p1 + p2) / 2; //Cálculo da média das provas
        mt = (t1 + 2*t2 + 3*t3) / 6; //Cálculo da média dos trabalho
        mf = (mp*8 + mt*2) / 10; //Cálculo da média final

        return mf;
    }

    //Imprime o nome, o CPF e a média final do aluno
    void Aluno::imprime() const{
        Pessoa::imprime();  //Imprime CPF e Nome
        cout << "Media Final: " << this->media() << endl;
    }

    //Verifica se o aluno foi aprovado 
    bool Aluno::aprovado() const{
        return this->media() >= 6.0;
    }

    //Verificar se o aluno ficou em SAC 
    bool Aluno::sac() const{
        // O Aluno fica em SAC quando 5 <= mf < 6
        bool ok = (5.0 <= this->media()) && (this->media() < 6.0);
        return ok;
    }

    //Verificar qual a nota mínima na SAC para a aprovação
    double Aluno::notaSAC() const{
        if (this->sac()){
            return 12 - this->media();
        }
        // Se o aluno não ficou em sac...
        return 0;
    }
}