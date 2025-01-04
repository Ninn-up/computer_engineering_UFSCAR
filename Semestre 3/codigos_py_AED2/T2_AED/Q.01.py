# Coutingsort

# Função para criar vetor inicializado com zeros
def zeros(n):
    vetor_zero = []
    for c in range(0, n):
        vetor_zero.append(0)

    return vetor_zero


# Coutingsort
def countingsort(l, n):
    m = max(l)  # Busca o maior elemento do vetor a ser ordenado
    c = zeros(m + 1)  # Cria um array com m + 1 zeros
    s = zeros(n) # Cria o array que irá armazenar o vetor final ordenado

    # Histograma
    for i in range(0, n):  # o número de ocorrências de cada elemento de l será armazenado
        c[l[i]] += 1  # e cada elemento de l servirá como índice

    # Realiza a soma acumulada dos elementos do vetor
    for i in range(1, m + 1):
        c[i] += c[i-1]

    # Ordenação final
    for i in range (0, n):  # Os valores são atualizados e colocados em suas devidas posições
        c[l[i]] -= 1
        s[c[l[i]]] = l[i]

    return s


# Código Principal

vetor = [29, 12, 3, 7, 2, 17, 4, 19, 42, 31, 20, 15, 10, 9, 16, 8, 1, 13, 21, 5]
print(countingsort(vetor, len(vetor)))
