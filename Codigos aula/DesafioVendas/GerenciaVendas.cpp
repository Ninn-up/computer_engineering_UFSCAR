#include "GerenciaVendas.h"

GerenciaVendas::GerenciaVendas(string fileName) : fileName(fileName) {

}

double GerenciaVendas::totalVendas(int id) {
    ifstream ifs(fileName, ios::binary);
    double total = 0;
 
 Venda v; // Para armazenar temporariamente os valores lidos
    if (ifs.is_open()) {
       
        
        ifs.read(reinterpret_cast<char *> (&v), sizeof (Venda));

        while(ifs.good()) {
            // Verifica se o produto lido tem o ID buscado
            cout << v.getID() << endl;
            if (v.getID() == id) { // Se tiver, soma o valor vendido do produto (quant * valor)
                total += (v.getValor() * v.getQuantidade());
                cout << total << endl;
            }

            ifs.read(reinterpret_cast<char *> (&v), sizeof (Venda));

        }
    }
    else{
        cout << "oi" << endl;
    }
    ifs.close();
    return total;
}

double GerenciaVendas::mediaVendas(int id) {
    return 0;
}

Venda GerenciaVendas::maiorVenda(){
    Venda maior;
    return maior;
}