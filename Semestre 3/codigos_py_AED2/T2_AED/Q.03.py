# Bucketsort
from math import floor, ceil


# Criação de um vetor preenchido com outros vetores (bucket)
def buckets(n):  # Criação dos n buckets vazios (vetor com vetores vazios)
    bucket = []
    for c in range(0, n):
        bucket.append([])

    return bucket


def bucketsort(l, n):
    b = buckets(n)
    s = []  # Onde será armazenado o resultado final

    # Dividindo cada valor por 100 para se enquadrar no intervalo I = [0, 1)
    for c in range(0, n):
        l[c] = l[c] / 100

    # Verificando em que range dos buckets cada valor do vetor se enquadra
    for i in range(0, n):
        if l[i] == 1:
            index = n - 1
        else:
            index = floor(n * l[i])

        b[index].append(l[i])  # Adicionando o valor no seu bucket correspondente

    # Ordenando cada bucket e o concatenando no vetor que será retornado
    for bucket in b:
        bucket.sort()
        s += bucket

    for c in range(0, n):
        s[c] = int(s[c] * 100)

    return s


# Código Principal
vetor = [29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5]
print(f'Vetor antes da ordenação: {vetor}')

print(f'Vetor depois da ordenação: {bucketsort(vetor, len(vetor))}')
