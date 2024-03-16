#include <fstream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include "Venda.h"
#include "GerenciaVendas.h"

using namespace std;

void geraArquivo() {
    ofstream saida("vendas.dat", ios::binary);
    Venda v;

    srand((unsigned)time(NULL));

    for (int i = 0; i < 10000; i++) {
        v.setID(rand() % 50 + 1);
        v.setQuantidade(rand() % 10 + 1);
        v.setValor((rand() % 10000 + 1) / 100.0);
        saida.write(reinterpret_cast<char *>(&v), sizeof(Venda));
    }

    saida.close();
}

int main() {

    /* geraArquivo(); */

    GerenciaVendas g("vendas.dat");

    for (int i = 1; i <= 50; i++) {
        double total = g.totalVendas(i);
        double media = g.mediaVendas(i);

        cout << "(" << setprecision(2) << fixed << setfill('0') << setw(2);
        cout << i << ") Total: " << total;
        cout << ", Media: " << media << endl;
    }

    g.maiorVenda().imprime();

    cout << sizeof(Venda) << endl;

    return 0;
}