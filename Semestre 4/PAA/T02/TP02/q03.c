// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>

// Função de comparação
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(void){
    // Entradas
    long long int N;
    
    scanf("%lld", &N);
    
    long long int precos[N];
    
    for (long long int i = 0; i < N; i++){
        scanf("%lld", &precos[i]);
    
    }
    
    // Ordenando o vetor
    qsort(precos, N, sizeof(long long int), compare);
    
    // Acumulador para o desconto final
    long long int desconto = 0;
    
    // Definindo os trios de itens
    for (long long int i = N - 3; i >= 0; i -= 3) {
        desconto += precos[i];
    }
    
    printf("%lld\n", desconto);
    
    return 0;
}
