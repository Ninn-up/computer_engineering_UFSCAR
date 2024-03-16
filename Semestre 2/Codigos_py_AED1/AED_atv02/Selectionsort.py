# Funções
def swap(lista, a, b):
    aux = lista[a]
    lista[a] = lista[b]
    lista[b] = aux
    # print(lista[a], lista[b])


def selectionsort(l, n):
    for c in range(0, n):
        menor = c
        for k in range(c+1, n):
            if l[k] < l[menor]:
                menor = k
                # print(f'O menor é {l[menor]}')

        swap(l, menor, c)
        print(f'{c+1}ª iteração: ', l)


# Código Principal
vetor = [77, 1, 6, 29, 91, 86, 92, 93, 89, 10, 36, 46, 60, 50, 53]

selectionsort(vetor, len(vetor))
print(vetor)
