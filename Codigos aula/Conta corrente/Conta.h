#ifndef CONTA_H
#define CONTA_H

class Conta{
    //Métodos da Classe
    public:
        Conta(int numero, double saldo = 0); //Construção
        ~Conta(); //Destrutor
        bool retirada(double saque);
        //Necessário passar o a outra Conta por referência para que seja possível alterar seus valores
            //Do contrário seus valores seriam utilizados como uma cópia e não seriam alterados
        bool transferencia(Conta &destino, double valor);
        bool deposito(double valor);
        void imprime();

    //Atributos da classe
    private:
        int numero;
        double saldo;
};
#endif