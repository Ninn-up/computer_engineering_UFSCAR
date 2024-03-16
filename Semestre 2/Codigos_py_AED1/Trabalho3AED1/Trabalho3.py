from random import randint
import timeit
import matplotlib.pyplot as plt


# Funções
def swap(lista, a, b):
    aux = lista[a]
    lista[a] = lista[b]
    lista[b] = aux
    # print(lista[a], lista[b])


def bubblesort(L, n):
    for c in range(n-1, -1, -1):
        for i in range(0, c):
            if L[i] > L[i+1]:
                swap(L, i, i+1)


def selectionsort(l, n):
    for c in range(0, n):
        menor = c
        for k in range(c+1, n):
            if l[k] < l[menor]:
                menor = k

        swap(l, menor, c)


def insertionsort(l, n):
    for c in range(1, n):
        k = c
        while k > 0 and l[k] < l[k - 1]:
            swap(l, k, k - 1)
            k -= 1


def gera_vetor(v, n):
    v.clear()
    for c in range(0, n):  # Usando n números aleatórios
        v.append(randint(1, n + 1))


def plota_grafico(x, y1, y2, y3):
    plt.plot(x, y1, c='red', label='Bubblesort')
    plt.plot(x, y2, c='blue', label='Selectionsort')
    plt.plot(x, y3, c='green', label='Insertionsort')
    plt.legend()
    plt.title('Análise do Tempo de Execução dos Algoritmos de Ordenação', fontsize=11)
    plt.xlabel('Qtde. Valores')
    plt.ylabel('Tempo de Execução (s)')
    plt.ylim(0, 250)
    plt.show()


# Código principal
vetor = []
tempo_bubble = []
tempo_selection = []
tempo_insertion = []
qtde_valores = [400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 3600, 4000, 4400, 4800, 5200, 5600, 6000]
tam = len(qtde_valores)

for i in range(0, tam):
    print(f'===== MEDIÇÃO DO TEMPO PARA {qtde_valores[i]} VALORES ALEATÓRIOS =====\n')

    gera_vetor(vetor, qtde_valores[i])

    # Tempo de execução do Bubblesort
    copia = vetor[:]
    tempo_bubble.append(timeit.timeit(lambda: bubblesort(copia, qtde_valores[i]), number=50))
    print('Tempo de execução do Bubblesort: ', tempo_bubble[i])

    # Tempo de execução do Selectionsort
    copia = vetor[:]
    tempo_selection.append(timeit.timeit(lambda: selectionsort(copia, qtde_valores[i]), number=50))
    print('Tempo de Execução do Selectionsort: ', tempo_selection[i])

    # Tempo de execução do Insertionsort
    copia = vetor[:]
    tempo_insertion.append(timeit.timeit(lambda: insertionsort(copia, qtde_valores[i]), number=50))
    print('Tempo de Execução do Insertionsort: ', tempo_insertion[i])

    print()

print('===== ANÁLISE DOS ALGORITMOS =====\n')
plota_grafico(qtde_valores, tempo_bubble, tempo_selection, tempo_insertion)
print('Tempos Bubblesort: ', tempo_bubble)
print('Tempos Selectionsort: ', tempo_selection)
print('Tempos Insertionsort: ', tempo_insertion)
