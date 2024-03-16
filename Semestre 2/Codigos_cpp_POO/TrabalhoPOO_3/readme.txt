Trabalho 3 POO
Aluna: Nicole Ramos

Contexto: 
A Orquestra Sinfônica Carlos Gomes recebeu uma doação de instrumentos para compor o seu acervo, assim, é necessário cadastrar os novos instrumenos em seu banco de dados considerando o ano de fabricação, a marca, seu estado (novo ou usado), o grupo a que pertencem na orquestra, o tamanho, o modelo e outras informações específicas de cada um; a fim de facilitar que os músicos organizem seus ensaios e apresentações.

As classes implementadas serão Instrumento, Piano e Violino. Além da classe Cadastro, para cadastrar os instrumentos.

Classe Instrumento:
- Atributos:
string tipo;
string marca;
string modelo;
double tam;
int ano_fab;
int estado;

- Métodos:
Instrumento(string, string, string, double, int, int)
getters and setters
int getGrupo() (método abstrato)
bool comparaAno()
void imprime()


Classe Piano:
- Atributos:
int qtde_teclas
string tipo_teclas

- Métodos:
Piano(string, string, string, double, int, int, int, string)
getters and setters
int getGrupo()
void imprime()


Classe FlautaDoce:
- Atributos:
string material
string estilo

- Métodos:
FlautaDoce(string, string, string, double, int, int, string, string)
getters and setters
int getGrupo()
void imprime()


Classe Cadastro:
- Atributos:
string nomeArquivo

- Métodos:
Cadastro(string)
bool remove(string)
bool atualiza(string)
bool adiciona(int grupo)

void imprime(string modelo)
void imprimeGrupo(int)
void imprimeEstado(int estado)
void imprimeOrdenado()

void grava() -> (privado)
int indice(string) -> (privado)
void le() -> (privado)

char opcao()


===================================================================
Exemplos de Objetos:
Pianos
1)
Tipo: Medium Grand
Marca: Steinway & Sons
Modelo: Model M
Tamanho: 170
Ano de Fabricacao: 1927
Estado: 1
Quantidade de Teclas: 88
Tipo de Teclas: Pesadas

2)
Tipo: Studio
Marca: M. Shwartzmann
Modelo: Acustico
Tamanho: 110
Ano de Fabricacao: 1980
Estado: 1
Quantidade de Teclas: 88
Tipo de teclas: Pesadas

3)
Tipo: Teclado Eletronico
Marca: Yamaha
Modelo: PSR-F52
Tamanho: 92
Ano de Fabricacao: 2024
Estado: 0
Quantidade de Teclas: 61
Tipo de Teclas: Leves

Flautas
1)
Tipo: Germanica
Marca: Dailylive
Modelo: DP-123
Tamanho: 35.2
Ano de Fabricacao: 2023
Estado: 0
Material: Madeira
Estilo: Soprano

2)
Tipo: Barroca
Marca: Yamaha
Modelo: YRS-24B
Tamanho: 35.5
Ano de Fabricacao: 2024
Estado: 0
Material: Plastico
Estilo: Soprano

3)
Tipo: Barroca
Marca: Yamaha
Modelo: YRT-304BII
Tamanho: 35.4
Ano de Fabricacao: 2018
Estado: 1
Material: Resina ABS
Estilo: Tenor

