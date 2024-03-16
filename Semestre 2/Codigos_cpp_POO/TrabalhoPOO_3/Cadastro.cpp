#include "Cadastro.h"

// Construtor
Cadastro::Cadastro(string fileName) : fileName(fileName) {
    le();  // Lê os dados armazenados no arquivo binário fornecido
}

// Destrutor
Cadastro::~Cadastro(){}

// Escreve as classes no arquivo binário
void Cadastro::grava() {
    string tipo, marca, modelo, tipo_teclas, material, estilo;
    int ano_fab, estado, qtde_teclas, tam, grupo;
    double tamanho;
    Piano *p1;
    FlautaDoce *f1;

    ofstream outFile(fileName, ios::binary);

    for (long unsigned int i = 0; i < instrumentos.size(); i++){
        // Escrevendo os métodos de cada objeto

        // Escrevendo o tipo do instrumento
        tipo = instrumentos[i]->getTipo();
        tam = tipo.size();
        
        // Escreve o tamanho da string tipo
        outFile.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        // Escreve os caracteres do tipo
        outFile.write(reinterpret_cast<char *>(&tipo[0]), tam);

        // Escrevendo a marca do instrumentos
        marca = instrumentos[i]->getMarca();
        tam = marca.size();

        // Escreve o tamanho da string marca
        outFile.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        // Escreve os caracteres da marca
        outFile.write(reinterpret_cast<char *>(&marca[0]), tam);

        // Escrevendo o modelo do instrumento
        modelo = instrumentos[i]->getModelo();
        tam = modelo.size();

        // Escreve o tamanho da string modelo
        outFile.write(reinterpret_cast<char *>(&tam), sizeof(tam));
        // Escreve os caracteres da string modelo
        outFile.write(reinterpret_cast<char *>(&modelo[0]), tam);

        // Escrevendo o tamanho do instrumento
        tamanho = instrumentos[i]->getTam();
        outFile.write(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));

        // Escrevendo o ano de fabricação do instrumento
        ano_fab = instrumentos[i]->getAno();
        outFile.write(reinterpret_cast<char *>(&ano_fab), sizeof(ano_fab));

        // Escrevendo o estado do instrumento
        estado = instrumentos[i]->getEstado();
        outFile.write(reinterpret_cast<char *>(&estado), sizeof(estado));

        // Escrevendo o grupo do instrumento
        grupo = instrumentos[i]->getGrupo();
        outFile.write(reinterpret_cast<char *>(&grupo), sizeof(grupo));

        // Verifica qual o grupo do instrumento e escreve seus atributos específicos
        switch(grupo) {
            case CORDAS: {
                p1 = dynamic_cast<Piano *>(instrumentos[i]);

                // Escrevendo a quantidade de teclas
                qtde_teclas = p1->getQtde();
                outFile.write(reinterpret_cast<char *>(&qtde_teclas), sizeof(qtde_teclas));

                // Escrevendo o tipo de tecla
                tipo_teclas = p1->getTipoTeclas();
                tam = tipo_teclas.size();

                // Escrevendo o tamanho da string tipo_teclas
                outFile.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                // Escrevendo os caracteres da string tipo_teclas
                outFile.write(reinterpret_cast<char *>(&tipo_teclas[0]), tam);

                break;
            }
            case MADEIRAS: {
                f1 = dynamic_cast<FlautaDoce *>(instrumentos[i]);

                // Escrevendo o material da flauta
                material = f1->getMaterial();
                tam = material.size();

                // Escrevendo o tamanho da string material
                outFile.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                // Escrevendo os caracteres da string material
                outFile.write(reinterpret_cast<char *>(&material[0]), tam);

                // Escrevendo o estilo da flauta
                estilo = f1->getEstilo();
                tam = estilo.size();

                // Escrevendo o tamanho da string estilo
                outFile.write(reinterpret_cast<char *>(&tam), sizeof(tam));
                // Escrevendo os caracteres da string estilo
                outFile.write(reinterpret_cast<char *>(&estilo[0]), tam);

                break;

            }
        }
    }

    // Fecha o arquivo de saída
    outFile.close();
}

// Lê os dados no arquivo binário
void Cadastro::le() {
    string tipo, marca, modelo, tipo_teclas, material, estilo;
    int ano_fab, estado, qtde_teclas, tam, grupo;
    double tamanho;

    ifstream inFile(fileName, ios::binary);

    if (inFile.is_open()) {
        instrumentos.clear();

        // Lendo os atributos

        // Lendo o tipo
        // Lendo o tamanho da string tipo
        inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
        tipo.resize(tam);
        // Lendo os caracteres da string tipo
        inFile.read(reinterpret_cast<char *>(&tipo[0]), tam);

        while (inFile.good()) {
            // Lendo a marca
            // Lendo o tamanho da string marca
            inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            marca.resize(tam);
            // Lendo os caracteres da string marca
            inFile.read(reinterpret_cast<char *>(&marca[0]), tam);

            // Lendo o modelo
            // Lendo o tamanho da string modelo
            inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            modelo.resize(tam);
            // Lendo os caracteres da string marca
            inFile.read(reinterpret_cast<char *>(&modelo[0]), tam);

            // Lendo o tamanho 
            inFile.read(reinterpret_cast<char *>(&tamanho), sizeof(tamanho));

            // Lendo o ano de fabricação
            inFile.read(reinterpret_cast<char *>(&ano_fab), sizeof(ano_fab));

            // Lendo o estado
            inFile.read(reinterpret_cast<char *>(&estado), sizeof(estado));

            // Lendo o gruppo
            inFile.read(reinterpret_cast<char *>(&grupo), sizeof(grupo));

            // Lendo as características específicas de cada grupo
            switch (grupo) {
                case CORDAS: {
                    // Lendo a quantidade de teclas
                    inFile.read(reinterpret_cast<char *>(&qtde_teclas), sizeof(qtde_teclas));

                    // Lendo o tipo de tecla
                    // Lendo o tamanho da string tipo_teclas
                    inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    tipo_teclas.resize(tam);
                    // Lendo os caracteres da string tipo_teclas
                    inFile.read(reinterpret_cast<char *>(&tipo_teclas[0]), tam);

                    instrumentos.push_back(new Piano(tipo, marca, modelo, tamanho, ano_fab, estado, qtde_teclas, tipo_teclas));
                    break;
                }
                case MADEIRAS: {
                    // Lendo o material
                    // Lendo o tamanho da string material
                    inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    material.resize(tam);
                    // Lendo os caracteres da string material
                    inFile.read(reinterpret_cast<char *>(&material[0]), tam);

                    // Lendo o estilo
                    // Lendo o tamanho da string estilo
                    inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
                    estilo.resize(tam);
                    // Lendo os caracteres da string estilo
                    inFile.read(reinterpret_cast<char *>(&estilo[0]), tam);

                    instrumentos.push_back(new FlautaDoce(tipo, marca, modelo, tamanho, ano_fab, estado, material, estilo));
                    break;
                }
            }

            // Lendo o tipo
            // Lendo o tamanho da string tipo
            inFile.read(reinterpret_cast<char *>(&tam), sizeof(tam));
            tipo.resize(tam);
            // Lendo os caracteres da string tipo
            inFile.read(reinterpret_cast<char *>(&tipo[0]), tam);
        }
    }

    // Fechando o arquivo
    inFile.close();
}

// Busca a posição do instrumento no arquivo
int Cadastro::indice(string modelo) {
    long unsigned int tam = instrumentos.size();
    long unsigned int pos = 0;

    while (pos < tam && instrumentos[pos]->getModelo() != modelo) {
        pos++;
    }

    if (pos < tam) {
        return pos;
    }
    else {
        return -1;
    }
}

// Adiciona um instrumento ao arquivo
bool Cadastro::adiciona(int grupo) {
    string tipo, marca, modelo, tipo_teclas, material, estilo;
    int ano_fab, estado, qtde_teclas;
    double tamanho;

    Instrumento *i;

    cin.ignore();
    cout << "Tipo: ";
    getline(cin, tipo);
    cout << "Marca: ";
    getline(cin, marca);
    cout << "Modelo: ";
    getline(cin, modelo);
    cout << "Tamanho: (cm) ";
    cin >> tamanho;
    cout << "Ano de fabricacao: ";
    cin >> ano_fab;
    cout << "Estado: [0 -> Novo / 1 -> Usado] ";
    cin >> estado;

    switch(grupo) {
        case CORDAS: {
            cout << "Quantidade de Teclas: ";
            cin >> qtde_teclas;

            cout << "Tipo de Teclas: ";
            cin.ignore();
            getline(cin, tipo_teclas);

            i = new Piano(tipo, marca, modelo, tamanho, ano_fab, estado, qtde_teclas, tipo_teclas);
            break;
        }
        case MADEIRAS: {
            cout << "Material: ";
            cin.ignore();
            getline(cin, material);

            cout << "Estilo: ";
            getline(cin, estilo);
            i = new FlautaDoce(tipo, marca, modelo, tamanho, ano_fab, estado, material, estilo);
            break;

        }
    }

    instrumentos.push_back(i);
    grava();
    return true;
}

// Encontra um instrumento e atualiza seu estado
bool Cadastro::atualiza(string modelo) {
    int estado;
    bool ok = false;
    int pos = indice(modelo);

    if (pos != -1) {
        cout << "Qual o estado do instrumento? [0 -> Novo / 1 -> Usado] ";
        cin >> estado;

        instrumentos[pos]->setEstado(estado);
        grava();
        ok = true;
    }

    return ok;
}

// Remove um instrumento da lista
bool Cadastro::remove(string modelo) {
    bool ok = false;
    int pos = indice(modelo);

    if (pos != -1) {
        instrumentos.erase(instrumentos.begin() + pos);
        grava();
        ok = true;
    }

    return ok;
}

// Imprime as informações do instrumento desejado
void Cadastro::imprime(string modelo) {
    int pos = indice(modelo);

    if (pos != -1) {
        instrumentos[pos]->imprime();
    }
    else {
        cout << "Modelo não encontrado no acervo" << endl;
    }

    cout << "==========================================" << endl;
}

// Imprime os instrumentos no acervo ordenados por ano de fabricação
void Cadastro::imprime(bool sorted) {
    vector<Instrumento*> copia = instrumentos;

    // Ordena o vetor cópia se for true
    if (sorted) {
        sort(copia.begin(), copia.end(), Instrumento::comparaAno);
    }

    cout << "==========================================" << endl;

    for (long unsigned int i = 0; i < copia.size(); i++) {
        copia[i]->imprime();
        cout << endl;
    }

    cout << "==========================================" << endl;
}

// Imprime os instrumentos do grupo especificado no acervo 
void Cadastro::imprimeGrupo(int grupo) {
    long unsigned int tam = instrumentos.size();

    for (long unsigned int i = 0; i < tam; i++) {
        if (instrumentos[i]->getGrupo() == grupo) {
            instrumentos[i]->imprime();
            cout << endl;
        }
    }

    cout << "==========================================" << endl;
}

// Imprime os instrumentos do estado especificado no acervo 
void Cadastro::imprimeEstado(int estado) {
    long unsigned int tam = instrumentos.size();

    for (long unsigned int i = 0; i < tam; i++) {
        if (instrumentos[i]->getEstado() == estado) {
            instrumentos[i]->imprime();
            cout << endl;
        }
    }

    cout << "==========================================" << endl;
}

char Cadastro::opcao() {
    char c;
    cout << "[T] Imprime TODOS os Instrumentos" << endl;
    cout << "[M] Imprime por MODELO" << endl;
    cout << "[G] Imprime por GRUPO" << endl;
    cout << "[E] Imprime por ESTADO" << endl;
    cout << "[O] Imprime ORDENADO" << endl;
    cout << "[P] Adiciona PIANO" << endl;
    cout << "[F] Adiciona FLAUTA" << endl;
    cout << "[A] ATUALIZA Estado (por modelo)" << endl;
    cout << "[R] REMOVE (por modelo)" << endl;
    cout << "[S] SAIR" << endl;
    cout << "Sua opcao: ";
    cin >> c;
    return (toupper(c));
}