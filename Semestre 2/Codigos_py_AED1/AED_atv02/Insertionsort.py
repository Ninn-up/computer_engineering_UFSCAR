# Funções
def swap(lista, a, b):
    aux = lista[a]
    lista[a] = lista[b]
    lista[b] = aux
    # print(lista[a], lista[b])


def insertionsort(l, n):
    for c in range(1, n):
        k = c
        while k > 0 and l[k] < l[k - 1]:
            swap(l, k, k - 1)
            k -= 1
        print(f'{c}ª iteração: ', l)


# Código principal
vetor = [77, 1, 6, 29, 91, 86, 92, 93, 89, 10, 36, 46, 60, 50, 53]

insertionsort(vetor, len(vetor))
print(vetor)
