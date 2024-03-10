#include "Pessoa.h"

//Construtor
Pessoa::Pessoa(string nome, int idade) : nome(nome), idade(idade){
    for (int i = 0; i < MAX; i++){
        pets[i] = NULL;
    }
    quantPets = 0;
}

//Destrutor
Pessoa::~Pessoa(){};

string Pessoa::getNome() const {
    return nome;
}

void Pessoa::setNome(string novo) {
    nome = novo;
}

int Pessoa::getIdade() const {
    return idade;
}

void Pessoa::setIdade(int nova) {
    idade = nova;
}   

void Pessoa::adicionaAnimal(AnimalDomestico* pet){
    if (quantPets < MAX){
        pets[quantPets] = pet; //Adiciona o pet a lista de Pessoa
        
    }
    pet->setDono(this); //Adiciona a Pessoa ao atributo de Pet
    quantPets++;

}

void Pessoa::removeAnimal(string nomeAnimal){
    bool achou = false;
    int i = 0;

    //Procura o animal com base no nome fornecido
    while (i < quantPets && !achou){
        if (pets[i]->getNome() == nomeAnimal){ //Quando encontrar...
            achou = true;   
        }
        else{
            i++; //Senão, continua procurando até terminar o array
        }
    }

    if (achou){ //Quando encontrar...
        pets[i]->setDono(NULL);

        while (i < quantPets - 1){
            pets[i] = pets[i++]; //Desloca os animais para a posição que será esvaziada
            i++;
        }

        pets[quantPets - 1] = NULL; //Esvazia a última posição
        quantPets--; //Diminui a quantidade de pets armazenada
    }
}

void Pessoa::imprime() const{ //adicionar imprime animal
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "===== Animais ===== " << endl;
    for (int i = 0; i < MAX; i++){
        pets[i]->imprime();
    }
    cout << endl;
}
