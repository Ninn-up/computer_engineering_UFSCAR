// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>

float * intercala (float *ve, int tam_e, float *vd, int tam_d){
    // Contadores
    int i = 0;
    int j = 0;
    int k = 0;
    
    // Vetor ordenado
    float * v;
    v = (float *) malloc ((tam_e + tam_d) * sizeof(float));
    
    // Unindo os vetores ordenados
    while (i < tam_e && j < tam_d){
        if (ve[i] <= vd[j]){
            v[k] = ve[i];
            i++;
            k++;
        }
        else {
            v[k] = vd[j];
            j++;
            k++;
        }
    }
    
    while (i < tam_e) {
        v[k] = ve[i];
        i++;
        k++;
    }
    while (j < tam_d) {
        v[k] = vd[j];
        j++;
        k++;
    }
    
    return v;
}

void msort(float vetor[], int tam) {
    
    int meio;
    
    // Caso Base (um vetor com apenas 1 elemento já está ordenado)
    if (tam <= 1) {
        return;
    }
    
    // Dividindo o vetor pela metade (divisão)
    meio = tam / 2;
    
    float * ve = (float *) malloc (meio * sizeof(float));
    float * vd = (float *) malloc ((tam - meio) * sizeof(float));
    
    // Adicionando os valores
    for (int i = 0; i < tam; i++){
        if (i < meio){
            ve[i] = vetor[i];
            //printf("meio = %d\nve[%d] = %f\n", meio, i, ve[i]);

        }
        else {
            vd[i - meio] = vetor[i];
        }
    }
    
    
    // Aplicando msort nas duas partes do vetor
    msort(ve, meio);
    //printf("Fim da recursão esquerda\n");
    msort(vd, tam - meio);
    //printf("Fim da recursão direita\n");
    
    // Vetor ordenado
    float * v_orden;
    v_orden = intercala(ve, meio, vd, tam - meio);
    
    for (int i = 0; i < tam; i++) {
        vetor[i] = v_orden[i];
    }
    
    // Liberando memória alocada dinâmicamente
    free(ve);
    free(vd);
}



int main(void) {
    //Outlier: distância ao k-ésimo vizinho é maior que l (limite)
    
    // Entrada: (int) N, S, k; (float) L
    int N; // Número de elementos em cada linha
    int S; // Número de linhas com elementos
    int k; // Vizinho
    float L; // Limite para ser outlier
    
    int outl = 0; // Contador para o número de outliers
    
    //Saída: número de outliers no conjunto
    
    // Código Principal
    
    scanf("%d %d %d %f", &N, &S, &k, &L);
    
    float vizinhos[S][N];
    
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < N; j++) {
                scanf("%f", &vizinhos[i][j]);
        }
    }
    
    // Ordenando o vetor para encontrar o k-ésimo vizinho mais próximo
    msort(vizinhos[0], N);
    for (int i = 0; i < S; i++){
        msort(vizinhos[i], N);
        
        // Verificando se é um outlier (ignorando o elemento 0 -> o próprio elemento)
        if (vizinhos[i][k+1] > L){
            outl++;
        }
        
    }
    
    // Retornando o número de outliers
    printf("%d\n", outl);
    
    
    return 0;
    
}
