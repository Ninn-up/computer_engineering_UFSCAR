# Função Swap
# Realiza trocas entre os elementos de uma lista (mediante índices)
def swap(l, i_a, i_b):
    aux = l[i_a]
    l[i_a] = l[i_b]
    l[i_b] = aux


# Função Partition
# Particiona uma lista separando os elementos maiores e menores que o pivô
def partition(l, low, high):
    x = l[high]  # Pivô
    i = low - 1  # Indicador dos valores menores que o pivô

    for j in range(low, high):  # Passa pelos elementos do vetor e verifica se é maior ou menor que o pivô
        if l[j] <= x:  # Se for menor...
            i += 1  # "Aumenta" a parte do vetor que abriga os valores menores que o pivô
            swap(l, i, j)  # Leva o elemento analisado para a nova posição entre os valores menores

    # Ao fim das iterações, basta posicionar o pivô na divisão entre os menores e os maiores elementos (em i+1)
    swap(l, high, i+1)
    return 1 + i


# Função quicksort
# Algoritmo de ordenação com base em partições recursivas
def quicksort(l, low, high):
    if low < high:  # Repete o processo até o vetor ter apenas 1 elemento
        q = partition(l, low, high)  # Aplica a partição no comprimento total do vetor fornecido
        quicksort(l, low, q-1)  # Repete o processo na metade inferior do vetor fornecido
        quicksort(l, q + 1, high)  # Repete o processo na metade superior do vetor fornecido


# Código principal
print('=== QUICKSORT ===')

lista = [29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5]
print(f'Lista Inicial: {lista}')

# Aplicando o quicksort
quicksort(lista, 0, len(lista) - 1)
print(f'Lista Ordenada: {lista}')
