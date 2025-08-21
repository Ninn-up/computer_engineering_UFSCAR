#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "TabelaHash.h"

int main() {
    FILE * alunosFile = fopen("alunos.txt", "r");

    if (alunosFile == NULL) {
        perror("Erro ao abrir o arquivo alunos.txt\n");
        exit(1);
    }

    int matricula, n1, n2, n3;
    char nome[30];
    struct aluno al;

    int tabelaSize = 2287;
    Hash* ha = criaHash(tabelaSize);

    while (fscanf(alunosFile, "%d %s %d %d %d", &matricula, nome, &n1, &n2, &n3) != EOF) {
        al.matricula = matricula;
        al.n1 = n1;
        al.n2 = n2;
        al.n3 = n3;
        strcpy(al.nome, nome);

        int ok = insereHash_EncadeamentoSeparado(ha, al);
        if (!ok)
            printf("Erro ao inserir aluno: %s\n", al.nome);
        
    }

    for (int i = 0; i < tabelaSize; i++) {
        printf("Posição %d: \n", i);
        imprime_lista(get_lista(ha, i));
    }
    
    fclose(alunosFile);
    return 0;
}