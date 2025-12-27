// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>

int * intercala (int * v1_pos, int *ve, int tam_e, int *vd, int tam_d, long long int *cont){
    // Contadores
    int i = 0;
    int j = 0;
    int k = 0;

    // Vetor ordenado
    int * v;
    v = (int *) malloc ((tam_e + tam_d) * sizeof(int));

    // Unindo os vetores ordenados
    while (i < tam_e && j < tam_d){
        // Comparando os valores dos índices de cada gene
        if (v1_pos[ve[i]] <= v1_pos[vd[j]]){
            v[k] = ve[i];
            //printf("v1_pos[%d] > v1_pos[%d]! Trocou!\n", ve[i], vd[j]);
            i++;
            //printf("Cont = %d\n", *cont);
        }
        else { // v1_pos[ve[i]] > v1_pos[vd[j]]
            v[k] = vd[j];
            j++;
            *cont += tam_e - i;
        }
        
        k++;
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

void conta_inversoes(int v1_pos[], int v2[], int tam, long long int *cont){
    // Caso Base (um vetor com apenas 1 elemento já está ordenado)
    if (tam <= 1) {
        return;
    }
    
    // Dividindo o vetor 2 pela metade (divisão)
    int meio;
    meio = tam / 2;
    
    int * ve = (int *) malloc (meio * sizeof(int));
    int * vd = (int *) malloc ((tam - meio) * sizeof(int));
    
    // Adicionando os valores
    for (int i = 0; i < tam; i++){
        if (i < meio){
            ve[i] = v2[i];
            //printf("meio = %d\nve[%d] = %d\n", meio, i, ve[i]);

        }
        else {
            vd[i - meio] = v2[i];
        }
    }
    
    
    // Aplicando função de divisão e conquista nas duas partes do vetor
    conta_inversoes(v1_pos, ve, meio, cont);
    //printf("Fim da recursão esquerda. Cont = %d\n", *cont);
    conta_inversoes(v1_pos, vd, tam - meio, cont);
    //printf("Fim da recursão direita. Cont = %d\n", *cont);
    
    // Vetor ordenado
    int * v_orden;
    v_orden = intercala(v1_pos, ve, meio, vd, tam - meio, cont);
    
    for (int i = 0; i < tam; i++) {
        v2[i] = v_orden[i];
        //printf("v2[%d] = %d\n", i, v2[i]);
    }
    
    // Liberando memória alocada dinâmicamente
    free(ve);
    free(vd);
    free(v_orden);
}

// Se forem iguais o contador não é atualizado

int main(void) {
    // Entrada:
    int N; // Número de genes dos indivíduos
    
    scanf("%d", &N);
    
    int p1[N];
    int p2[N];
    
    // Recebendo os genes
    for (int i = 0; i < N; i++){
        scanf("%d", &p1[i]);
    }
    
    for (int i = 0; i < N; i++){
        scanf("%d", &p2[i]);
    }
    
    // Inicializando o contador
    long long int cont = 0;
    
    // Guardando as posições do vetor referência
    int v1_pos[N];
    
    for (int i = 0; i < N; i++){
        // Guarda a posição de cada elemento no índice correspondente ao seu valor
        v1_pos[p1[i]] = i;
    }
    
    conta_inversoes(v1_pos, p2, N, &cont);
    printf("%lld\n", cont);
    
    return 0;
}
