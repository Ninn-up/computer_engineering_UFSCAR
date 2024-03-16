#ifndef DATA_H
#define DATA_H

class Data{
    //Métodos
    public:
        Data(int, int, int);
        ~Data();
        void imprime();
        void imprimePorExtenso();
        bool anoBissexto();
        int compara(const Data& outra);

    //Atributos
    private:
        int dia, mes, ano;


};

#endif