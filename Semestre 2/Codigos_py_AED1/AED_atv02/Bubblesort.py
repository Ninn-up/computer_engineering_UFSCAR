# Funções
def swap(lista, a, b):
    aux = lista[a]
    lista[a] = lista[b]
    lista[b] = aux
    # print(lista[a], lista[b])

def bubblesort (L, n):
    for c in range(n-1, -1, -1):
        for i in range(0, c):
            if L[i] > L[i+1]:
                swap(L, i, i+1)
        print(f'{n - c}ª iteração: ', L)


# Código principal
vetor = [77, 1, 6, 29, 91, 86, 92, 93, 89, 10, 36, 46, 60, 50, 53]

bubblesort(vetor, len(vetor))

print(vetor)

