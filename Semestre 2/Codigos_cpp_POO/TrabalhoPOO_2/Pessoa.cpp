#include "Pessoa.h"

// Construtor
Pessoa::Pessoa(string nome, string CPF) : nome(nome), CPF(CPF) {
}

// Destrutor 
Pessoa::~Pessoa(){}

// Retorna o nome da pessoa
string Pessoa::getNome() const {
    return nome;
}

// Retorna o CPF da pessoa
string Pessoa::getCPF() const {
    return CPF;
}

// Altera o nome da pessoa
void Pessoa::setNome(string novo_nome) {
    nome = novo_nome;
}

// Altera o CPF da pessoa
void Pessoa::setCPF(string novo_cpf) {
    CPF = novo_cpf;
}


// Adiciona um veículo a frota de veículos
bool Pessoa::adicionaVeiculo(Veiculo& veiculo) {
    // Indica o dono do veículo e o adiciona a frota
    veiculo.setDono(this);
    frota.push_back(&veiculo);

    return true;
}

// Remove um veículo da frota de veículos
bool Pessoa::removeVeiculo(string placa) {
    Veiculo * v;
    bool ok = false;

    // Variável que irá guardar a posição do veículo na frota
    vector<Veiculo *>::iterator pos; 

    // Busca o veículo a ser removido
    v = this->obtemVeiculo(placa);

    // Retira o veículo da frota e remove o dono 
    if (v != NULL) {
        v->setDono(NULL);
        pos = find(frota.begin(), frota.end(), v);
        frota.erase(pos);
        ok = true;
    }

    return ok;
}

// Retorna o veículo da frota de veículos
Veiculo * Pessoa::obtemVeiculo(string placa) const {
    Veiculo * v = NULL;
    int tam = frota.size();

    // Busca do veículo que se quer obter
    for (int i = 0; i < tam; i++) {
        if (placa == frota[i]->getPlaca()) {
            v = frota[i];
        }
    }

    // Se o encontrar, retorna o veículo; senão, retorna NULL
    return v;
}

// Retorna a quantidade de veículos da frota
int Pessoa::qtdeVeiculos() const {
    return frota.size();
}

// Retorna a quantidade de carros na frota de veículos
int Pessoa::qtdeCarros() const {
    int cont = 0; // Contador
    int qtde = frota.size();

    for (int i = 0; i < qtde; i++) {
        if (frota[i]->getCategoria() == 1) {
            cont++;
        }
    }

    return cont;
}

// Retorna a quantidade de caminhões na frota de veículos
int Pessoa::qtdeCaminhoes() const {
    int cont = 0; // Contador
    int qtde = frota.size();

    for (int i = 0; i < qtde; i++) {
        if (frota[i]->getCategoria() == 2) {
            cont++;
        }
    }

    return cont;
}

// Compara os veículos para que possam ser ordenados segundo a placa
bool Pessoa::comparaPlaca(Veiculo* v1, Veiculo* v2) {
    // Ordena em ordem alfabética (e em ordem crescente)
    return v1->getPlaca() < v2->getPlaca();

}

// Compara os veículos para que sejam ordenados segundo o ano
bool Pessoa::comparaAno(Veiculo* v1, Veiculo* v2) {
    // Ordena em ordem crescente
    bool ordena = true;

    if (v1->getAno() > v2->getAno()) {
        ordena = false;
    }
    // Se forem iguais em ano, compara-se pela placa
    else if (v1->getAno() == v2->getAno()) {
        ordena = comparaPlaca(v1, v2);  

    }

    return ordena;
}

// Compara os veículos para que sejam ordenados segundo a categoria
bool Pessoa::comparaCategoria(Veiculo* v1, Veiculo* v2) {
    // Ordem crescente
    bool ordena = true;

    if (v1->getCategoria() > v2->getCategoria()) {
        ordena = false;
    }
    // Se forem iguais em categoria, compara-se pela placa
    else if (v1->getCategoria() == v2->getCategoria()) {
        ordena = comparaPlaca(v1, v2);
    }

    return ordena;
}

// Imprime as informações da pessoa e de seus veículos (segundo um critério)
void Pessoa::imprime(int criterio) {
    // Imprime nome e cpf da pessoa
    cout << "Nome: " << nome << " -> ";
    cout << "CPF: " << CPF << endl;

    // Imprime as informações dos veículos segundo o critério escolhido
    int tam = this->qtdeVeiculos();
    vector<Veiculo*> copia_frota;

    cout << "Veiculos: " << endl;

    // Verifica o critério escolhido
    if (criterio == 1) {  // NOSORTED
        for (int i = 0; i < tam; i++){
            frota[i]->imprime();
            cout << "--------------------------------" << endl;
        }
    }
    else {
        // Faz uma cópia para imprimir ordenado sem alterar a ordem original
        copia_frota = frota;

        if (criterio == 2) { // PLACA
            sort(copia_frota.begin(), copia_frota.end(), comparaPlaca);
        }
        
        else if (criterio == 3) { // ANO
            sort(copia_frota.begin(), copia_frota.end(), comparaAno);
        }
        
        else if (criterio == 4) { // CATEGORIA
            sort(copia_frota.begin(), copia_frota.end(), comparaCategoria);
        }

        // Imprime os veículos segundo o critério escolhido
        for (int i = 0; i < tam; i++){
                copia_frota[i]->imprime();
                cout << "--------------------------------" << endl;
        }
    }
}