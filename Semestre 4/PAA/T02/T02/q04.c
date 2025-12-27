//// Aluna: Nicole Ramos
//// RA: 823127
//// Curso: Engenharia da Computação
//
//#include <stdio.h>
//#include <stdlib.h>
//
//// Função de comparação
//int compare(const void *a, const void *b) {
//    return (*(int *)a - *(int *)b);
//}
//
//int main(void){
//    // Entradas
//    int N;
//    
//    scanf("%d", &N);
//    
//    long long int precos[N];
//    
//    for (int i = 0; i < N; i++){
//        scanf("%lld", &precos[i]);
//    
//    }
//    
//    // Ordenando o vetor
//    qsort(precos, N, sizeof(long long int), compare);
//    
//    // Acumulador para o desconto final
//    long long int desconto = 0;
//    
//    // Indices
//    int i = 0;
//    int j = N - 1;
//    
//    // Definindo os trios de itens
//    while (j-1 > i) {
//        desconto += precos[j-1];
//        i++;
//        j -= 2;
//    }
//    
//    printf("%lld\n", desconto);
//    
//    return 0;
//}
