// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprime(int v[], int n, int ini)
{
    int i;
    for (i = ini; i < n - 1; i++)
        printf("%d ", v[i]);
        
    printf("%d\n", v[i]);
}

int main(void){
    // Remover duplicatas de uma fila e manter apenas a primeira vez que o elemento ingressou nela
    
    int N;  // Quantidade de elementos que compõem a fila
    int maior;
    
    // Recebendo valores
    scanf("%d", &N);
    
    // Criando fila
    int *fila;
    fila = (int *) malloc (N * sizeof(int));
    
    // Recebendo o primeiro elemento
    scanf("%d", &fila[0]);
    maior = fila[0];
    
    
    for (int i = 1; i < N; i++){
        scanf("%d", &fila[i]);
        
        if (fila[i] > maior) {
            maior = fila[i];
        }
    }
    
    // Criando um vetor de posições e um contador para as duplicadas
    char posicao[maior];
    memset(posicao, '0', sizeof(posicao));
    int cont = 0;
    
    for (int i = N - 1; i >= 0; i--) {
        if (posicao[fila[i] - 1] != '1'){
            posicao[fila[i] - 1] = '1';
            fila[i + cont] = fila[i];
        }
        else {
            cont++;
        }
        
    }
    
    imprime(fila, N, cont);
    
    free(fila);
    return 0;
}
