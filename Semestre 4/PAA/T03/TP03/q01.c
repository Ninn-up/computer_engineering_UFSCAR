// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
    
int main(void) {
    int N, difer, limite;
    int soma;
    int i = 0;
    
    int *w;  // Ponteiro para o vetor dinâmico com os pesos
    int *somas;  // Ponteiro para vetor dinâmico com as somas possíveis
    
    scanf("%d", &N);
    w = (int*) malloc (N * sizeof(int));
    somas = (int*) calloc(N / 2 + 1, sizeof(int));
    
    while (N != 0) {
        // Reiniciando o acumulador e as variáveis de controle
        soma = 0;
        
        for (i = 0; i < N; i++) {
            scanf("%d", &w[i]);
            soma += w[i];
            
        }
        //printf("Soma: %d\n", soma);
        
        limite = soma / 2;
        
        //printf("Limite: %d\n", limite);
        
        // Ordenando os valores em ordem crescente
        qsort(w, N, sizeof(int), compare);
        
        // Criando um vetor para armazenas as somas possíveis inicializado com 0
        somas = (int*) calloc(limite + 1, sizeof(int));
        
        int teste = 0;
        
        // Preenchendo o vetor somas
        somas[0] = 1;  // Soma zero sempre é possível (conjunto vazio)
        
        for (i = 0; i < N; i++) {
            for (int j = limite; j >= w[i]; j--) {
                if (somas[j - w[i]] > 0) {
                    somas[j] = 1;
                }
            }
        }
        
        // Encontrando a maior soma possível menor que o limite
        int maior_soma = 0;
        for (i = limite; i >= 0; i--) {
            if (somas[i] == 1) {
                maior_soma = i;
                break;
            }
        }
        
//        for (int i = 0; i < limite + 1; i++) {
//            printf("%d ", somas[i]);
//        }
//        printf("\n");
        
        //printf("Maior soma possível menor que soma/2: %d\n", somas[limite]);
        
        difer = abs(2 * maior_soma - soma);
        
        // Imprimindo a diferença
        printf("%d\n", difer);

        // Lendo o próximo valor de N
        int aux = N;
        
        scanf("%d", &N);
        
        if (aux < N){  // Verificando se é necessário realocar memória
            w = (int*) realloc (w, N * sizeof(int));
        }
        
        free(somas);
        
    }
    
    // Liberando memória
    free(w);
    
    return 0;
}
