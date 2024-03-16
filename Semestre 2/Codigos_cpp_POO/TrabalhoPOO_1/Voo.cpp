#include "Voo.h"

namespace poo{
    
    //Construtor
    Voo::Voo(Companhia& cia, string origem, string destino, DataHorario &dh) : cia(cia), origem(origem), destino(destino), dh(dh){
        //Inicialização das poltronas
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 6; j++){
                poltronas[i][j] = NULL;
            }
        }

        //Declara a quantidade inicial de poltronas no avião
        poltVagas = 150;
    }

    //Destrutor
    Voo::~Voo(){}

    //Retorna o número da próxima poltrona livre
    string Voo::proximoLivre() const {
        bool desocupado = false;
        int linha;
        int coluna;

        //Verifica se o avião está cheio
        if (this->vagas() != 0){

            //Caso não esteja, analisa a disponibilidade das poltronas
            for (int i = 0; i < 25 && !(desocupado); i++){
                for (int j = 0; j < 6 && !(desocupado); j++){
                    //Verifica qual poltrona está vazia
                    if (poltronas[i][j] == NULL){
                        linha = i;
                        coluna = j;
                        desocupado = true;
                    }
                }
            }

            //Cálculo da numeração da poltrona livre
            string poltrona = to_string(linha + 1);
            poltrona.append(1, ((char) ('A' + coluna)));
            poltrona.insert(0, 3 - poltrona.size(), '0');
            
            //Retorna a numeração da poltrona
            return poltrona;
        }

        //Se estiver cheio...
        return "cheio";
    }

    //Verifica se a poltrona informada está ocupada
    bool Voo::verifica(string poltrona) const {
        int linha = stoi(poltrona.substr(0, 2)) - 1;
        int coluna = poltrona[2] - 'A';

        //Verifica se a poltrona está ocupada
            //Caso esteja, retorna "true" 
            //Caso não esteja, retorna "false"
        return poltronas[linha][coluna] != NULL; 
    }

    //Ocupa determinada poltrona do voo
    bool Voo::ocupa(string poltrona, Pessoa& passageiro){
        int linha = stoi(poltrona.substr(0, 2)) - 1;
        int coluna = poltrona[2] - 'A';

        //Verifica se o assento escolhido está vazio
        if (!(this->verifica(poltrona))){

            //Adiciona uma pessoa ao assento
            poltronas[linha][coluna] = &passageiro;
            poltVagas--; //Diminui o número de vagas no avião

            return true;
        }

        //Se não estiver vazio, não é possível realizar a ação
        return false;
    }

    //Desocupa determinada poltrona do voo
    bool Voo::desocupa(string poltrona){
        int linha = stoi(poltrona.substr(0, 2)) - 1;
        int coluna = poltrona[2] - 'A';

        //Verifica se a poltrona em questão está ocupada
        if (poltronas[linha][coluna] != NULL){
            
            //Desocupa a poltrona 
            poltronas[linha][coluna] = NULL;
            poltVagas++; //Aumenta o número de vagas do avião
            
            return true;
        }

        //Caso a poltrona esteja vazia, não é possível realizar a operação
        return false;
    }

    //Retorna o número de poltronas vagas disponíveis
    int Voo::vagas() const {
        return Voo::poltVagas;
    }

    //Imprime as informações de um voo
    void Voo::imprime() const {
        cout << "=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;

        cout << "Companhia Aerea: " << cia.getNome() << endl;
        cout << "Origem: " << origem << " -> ";
        cout << "Destino: " << destino << endl;
        cout << "Data e Horario do Voo: ";
        dh.imprime(false); //Imprime as informações do horário
        cout << endl;

        //Imprime as poltronas com seus respectivos passageiros
        int i;
        int j;
        string poltrona;

        for (i = 0; i < 25; i++){
            for (j = 0; j < 6; j++){
                poltrona = to_string(i + 1);
                poltrona.append(1, ((char) ('A' + j)));
                poltrona.insert(0, 3 - poltrona.size(), '0');
                cout << "Poltrona: " << poltrona << " -> ";

                //Caso haja passageiro na poltrona indicada, imprime suas informações
                if (poltronas[i][j] != NULL){
                    cout << "Passageiro: " << poltronas[i][j]->getNome() << endl;
                    cout << "                 CPF: " << poltronas[i][j]->getCPF();
                }
                //Senão, informa que a poltrona está disponível
                else{
                    cout << "[Poltrona Disponivel]";
                }
                cout << endl;
            } 
        }
        cout << "=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=x=" << endl;
    }
}