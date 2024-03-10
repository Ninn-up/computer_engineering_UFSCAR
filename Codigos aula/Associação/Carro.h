#ifndef CARRO_H
#define CARRO_H
#include <string>

using namespace std;

class Carro{
    public:
        Carro(string marca, string cor, int ano, string placa);
        ~Carro();
        string getMarca() const;
        void setMarca(string marca);
        string getCor() const;
        void setCor(string cor);
        int getAno() const;
        void setAno(int ano);
        string getPlaca() const;
        void setPlaca(string placa);
        void imprime() const;
        void setDono(Pessoa dono);
        
    private:
        string marca;
        string cor;
        int ano;
        string placa;

};

#endif