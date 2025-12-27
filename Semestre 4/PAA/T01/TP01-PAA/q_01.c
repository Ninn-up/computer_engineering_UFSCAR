// Aluna: Nicole Ramos
// Curso: Engenharia da Computação

#include <stdio.h>

double exponencial(double b, unsigned int n){
    // Base: b (double)
    // Expoente: n (unsigned int)
    
    double aux;
    
    // Se o expoente for 0, o resultado é 1
    if (n == 0){
        return 1;
    }
    
    // Se for diferente de 0, realiza a expoencial com metade do valor do expoente
    aux = exponencial(b, n / 2);
    aux = aux * aux;
    
    // Conversão de tipo para verificar a paridade da base
    unsigned int exp_int;
    exp_int = (unsigned int) n;
    
    // Verifica se o valor do expoente é ímpar
    if (exp_int % 2 == 1){
        aux = b * aux;
    }
        
    return aux;
}

void imprimeDigitoOrdem(double num) {
    int i = 0;
    while (num >= 10){
        num = num / 10;
        i++;
        
    }
    
    printf("%d %d\n", (int)num, i);
}

int main(void) {
    double b, resp;  // Base
    unsigned int n;  // Expoente
    
     Recebe as entradas
    scanf("%lf %u", &b, &n);
    
     Calcula a exponencial
    resp = exponencial(b, n);
    
     Imprime o valor mais significativo e a grandeza do resultado final
    imprimeDigitoOrdem(resp);
    
    return 0;
    
}
