# Função Swap
# Realiza trocas entre os elementos de uma lista (mediante índices)
def swap(l, i_a, i_b):
    aux = l[i_a]
    l[i_a] = l[i_b]
    l[i_b] = aux


# Função Shellsort
# Algoritmo de ordenação semelhante ao Insertionsort baseado na sequência de Shell
def shellsort(l, n):
    # "Gap" inicial a partir do qual os elementos serão divididos e ordenados
    h = n // 2  # Parte da metade o vetor

    while h > 0:  # Enquanto não alcançar um valor muito próximo de n...
        for i in range(h, n):
            j = i

            # Verifica se os elementos de h a n estão em suas devidas posições segundo seus grupos
            # Os grupos serão sequências que consideram valores divididos por h elementos entre eles
            while j >= h and l[j-h] > l[j]:  # Os elementos de um grupo são comparados e...
                swap(l, j, j - h)  # Se não estão nas posições corretas entre si, são trocados.
                j -= h  # Indica o próximo valor que pertence ao grupo em questão
        h //= 2  # Passa para o próximo "gap" (menor que o anterior)


# Código Principal
print('=== SHELLSORT ===')
lista = [29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5]
print(f'Lista Inicial: {lista}')

# Aplicando o algoritmo de ordenação
shellsort(lista, len(lista))
print(f'Lista Ordenada: {lista}')
