//Pot�ncias de dois devem ser evitadas
//deve ser um n�mero primo distante de pequenas pot�ncias de dois
#include "ListaSequencial.h"

typedef struct hash Hash;

Hash* criaHash(int TABLE_SIZE);
void liberaHash(Hash* ha);
int valorString(char *str);
int insereHash_SemColisao(Hash* ha, struct aluno al);
int buscaHash_SemColisao(Hash* ha, int mat, struct aluno* al);
int insereHash_EnderAberto(Hash* ha, struct aluno al);
int buscaHash_EnderAberto(Hash* ha, int mat, struct aluno* al);
int insereHash_EncadeamentoSeparado(Hash* ha, struct aluno al);
int buscaHash_EncadeamentoSeparado(Hash* ha, int mat, struct aluno* al);
Lista* get_lista(Hash* ha, int pos);
/*
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHashing(int pos, int chave, int i, int TABLE_SIZE);
*/
