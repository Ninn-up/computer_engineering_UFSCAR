#include "Peixe.h"
#include "Pessoa.h"
#include "Cachorro.h"
using namespace std;
int main(int argc, char** argv) {
    Pessoa* pessoa = new Pessoa("Joao", 12);
    Peixe* nemo = new Peixe("Nemo", 0.2, "Água salgada");
    Peixe* dory = new Peixe("Dory", 0.15, "Água doce");
    Cachorro* teo = new Cachorro("Teo", 6.2, "pug");
    pessoa->adicionaAnimal(nemo);
    pessoa->adicionaAnimal(dory);
    pessoa->adicionaAnimal(teo);
    pessoa->imprime();
    pessoa->removeAnimal("Dory");
    cout << endl;
    pessoa->imprime();

    // delete os objetos nemo, dory, teo e joao
    return 0;
}