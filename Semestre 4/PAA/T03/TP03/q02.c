// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N, D;
    long long int *dp;  // Vetor para armazenar as contagens de somas divisíveis por D
    
    // Recebendo a entrada
    scanf("%d %d", &N, &D);
    
    // Inicializando o vetor dp. O tamanho é D, pois estamos calculando as somas módulo D
    dp = (long long int*) calloc(D, sizeof(long long int));  // Armazenar contagens de cada resto possível (0 até D-1)
    dp[0] = 1;  // Inicializa com 1 para o caso do subconjunto vazio
    
    while (1) {
        // Processar os subconjuntos
        for (int i = 1; i <= N; i++) {  // Para cada elemento do conjunto {1, 2, ..., N}
            int valor = i;  // Elemento do conjunto
            
            // Atualiza os restos para os novos subconjuntos que incluem o valor atual
            long long int *temp_dp = (long long int*) calloc(D, sizeof(long long int));
            
            for (int r = 0; r < D; r++) {
                temp_dp[(r + valor) % D] += dp[r];  // Atualiza o contador de restos
            }
            
            // Atualiza dp com os novos valores
            for (int r = 0; r < D; r++) {
                dp[r] += temp_dp[r];
            }

            free(temp_dp);  // Liberando memória
        }
        
        // Exibindo o resultado
        printf("%lld\n", dp[0]);
        
        // Lendo o próximo valor de N
        int tam = N;
        scanf("%d", &N);
        
        if (N == 0) {
            break;
        }
        
        // Lendo o novo valor de D
        scanf("%d", &D);

        // Recalcular o DP para o novo tamanho N
        dp = (long long int*) calloc(D, sizeof(long long int));  // Re-alocação de memória
        dp[0] = 1;  // Inicializa novamente o dp para o novo conjunto
    }
    
    // Liberando a memória
    free(dp);
    
    return 0;
}
