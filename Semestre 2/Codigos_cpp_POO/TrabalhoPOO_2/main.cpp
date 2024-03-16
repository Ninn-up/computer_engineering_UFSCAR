#include "Carro.h"
#include "Caminhao.h"
#include "Constantes.h"
#include "Pessoa.h"
#include "Veiculo.h"
#include <iostream>

using namespace std;

int main() {
    
    Pessoa* pessoa = new Pessoa("Joao", "012345678-90");
    
    Carro fusca("FUS-1357", "Fusca", "Preto", 1970, 70);
    Caminhao volvo("VOL-3456", "Volvo", "Prata", 2020, 3);
    Carro* gol = new Carro("GOL-2456", "Gol", "Branco", 2020, 100);
    Caminhao* scania = new Caminhao("CDE-1000", "Scania", "Cinza", 2015, 6);
    
    pessoa->adicionaVeiculo(fusca);
    pessoa->adicionaVeiculo(volvo);
    pessoa->adicionaVeiculo(*gol);
    pessoa->adicionaVeiculo(*scania);

    cout << "Qtde (Veiculos): " << pessoa->qtdeVeiculos() << endl;
    cout << "Qtde (Carros): " << pessoa->qtdeCarros() << endl;
    cout << "Qtde (Caminhões): " << pessoa->qtdeCaminhoes() << endl << endl;

    cout << "================== IMPRIME ORDENADO (NOSORTED) ==================" << endl << endl;
    
    pessoa->imprime(NOSORTED);
    
    cout << endl;
    
    cout << "================== IMPRIME ORDENADO (PLACA) ==================" << endl << endl;
    
    pessoa->imprime(PLACA);
    
    cout << endl;

    cout << "================== IMPRIME ORDENADO (ANO) ==================" << endl << endl;
    
    pessoa->imprime(ANO);
    
    cout << endl;

    cout << "================== IMPRIME ORDENADO (CATEGORIA) ==================" << endl << endl;
    
    pessoa->imprime(CATEGORIA);
    
    cout << endl;

    pessoa->removeVeiculo("GOL-2456");
    
    cout << "Qtde (Veiculos): " << pessoa->qtdeVeiculos() << endl;
    cout << "Qtde (Carros): " << pessoa->qtdeCarros() << endl;
    cout << "Qtde (Caminhões): " << pessoa->qtdeCaminhoes() << endl << endl;

    cout << "================== IMPRIME ORDENADO (NOSORTED) ==================" << endl << endl;
    
    pessoa->imprime(NOSORTED);
    
    cout << endl;

    cout << "================== BUSCA E IMPRIME ==================" << endl << endl;
    
    pessoa->obtemVeiculo("FUS-1357")->imprime();
    
    cout << endl;
    
    delete gol;

    delete scania;

    return 0;
}

