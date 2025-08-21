#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *f = fopen("..\\compras.bin", "rb");

    if (f == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }


    char caractere;
    char str[100];

    double preco_total = 0;

    while (fread(&caractere, sizeof(char), 1, f) == 1) {
        fread(str, sizeof(char), caractere, f);
        str[caractere] = '\0'; // Adiciona o terminador nulo ao final da string

        // Divide a string em partes
        char *nome = strtok(str, "|");
        char *qtd_str = strtok(NULL, "|");  // Continua lendo na string inicial
        char *valor_str = strtok(NULL, "|");

        int qtd = atoi(qtd_str);
        double valor = atof(valor_str);
        
        printf("Nome: %s -> ", nome);
        printf("Qtde: %d -> ", qtd);
        printf("Valor: %.2f\n", valor);

        // Calcula o preço total da compra
        preco_total += qtd * valor;
    }

    printf("Preco total: %.2f\n", preco_total);
    fclose(f);

    return 0;
    
}