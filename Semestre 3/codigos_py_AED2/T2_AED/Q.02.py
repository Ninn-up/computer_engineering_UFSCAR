# Radixsort

# Função para criar um vetor de tamanho n inicializado com zeros
def zeros(n):
    vetor_zero = []
    for c in range(0, n):
        vetor_zero.append(0)

    return vetor_zero


# Coutingsort_R
def countingsort_r(l, n, d):
    s = zeros(n)
    m = l[0] // d % 10

    # Busca o maior dígito com base no d em questão
    for i in range(1, n):
        if l[i] // d % 10 > m:
            m = l[i] // d % 10

    c = zeros(m + 1)

    # Histograma
    for i in range(0, n):
        c[l[i] // d % 10] += 1

    # Soma acumulada
    for i in range(1, m + 1):
        c[i] += c[i - 1]

    # Vetor ordenado a partir da soma acumulada
    for i in range(n - 1, -1, -1):
        ind = (l[i] // d) % 10
        c[ind] -= 1
        s[c[ind]] = l[i]

    # Atualiza os valores no vetor original
    for i in range(0, n):
        l[i] = s[i]


def radixsort(l, n):
    m = max(l)
    d = 1

    while m/d > 0:
        countingsort_r(l, n, d)
        d *= 10


# Código Principal
vetor = [29, 125, 391, 74, 213, 178, 43, 19, 424, 131, 120, 158, 105, 92, 169, 81, 1, 143, 210, 51]
radixsort(vetor, len(vetor))

print(f'Vetor ordenado: {vetor}')
