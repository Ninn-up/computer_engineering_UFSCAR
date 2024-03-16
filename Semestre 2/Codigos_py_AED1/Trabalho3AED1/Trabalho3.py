from random import randint
import timeit
from heapq import heappush, heappop
import matplotlib.pyplot as plt

# Funções
def swap(lista, a, b):
    aux = lista[a]
    lista[a] = lista[b]
    lista[b] = aux

def bubblesort(L, n):  # Implementação do bubblesort
    for c in range(n-1, -1, -1):
        for i in range(0, c):
            if L[i] > L[i+1]:
                swap(L, i, i+1)

def selectionsort(l, n):  # Implementação do selectionsort
    for c in range(0, n):
        menor = c
        for k in range(c+1, n):
            if l[k] < l[menor]:
                menor = k

        swap(l, menor, c)

def insertionsort(l, n):  # Implementação do insertionsort
    for c in range(1, n):
        k = c
        while k > 0 and l[k] < l[k - 1]:
            swap(l, k, k - 1)
            k -= 1

def heapsort(array):  # Implementação do heapsort
    heap = []
    for value in array:
        heappush(heap, value)
    return [heappop(heap) for i in range(len(heap))]

def gera_vetor(v, n):  # Gera um vetor com n valores aleatórios
    v.clear()
    for c in range(0, n):  # Usando n números aleatórios
        v.append(randint(1, n + 1))

def plota_grafico(x, y1, y2, y3, y4):  # Responsável por esboçar o gráfico
    plt.plot(x, y1, c='red', label='Bubblesort')
    plt.plot(x, y2, c='blue', label='Selectionsort')
    plt.plot(x, y3, c='green', label='Insertionsort')
    plt.plot(x, y4, c='orange', label='Heapsort')
    plt.legend()
    plt.title('Análise do Tempo de Execução dos Algoritmos de Ordenação', fontsize=11)
    plt.xlabel('Qtde. Valores')
    plt.ylabel('Tempo de Execução (s)')
    plt.ylim(0)
    plt.show()

# Código principal
vetor = []
tempo_bubble = []
tempo_selection = []
tempo_insertion = []
tempo_heap = []
qtde_valores = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000]
tam = len(qtde_valores)

for i in range(0, tam):
    print(f'===== MEDIÇÃO DO TEMPO PARA {qtde_valores[i]} VALORES ALEATÓRIOS =====\n')

    # Gera o vetor que será utilizado para medir o tempo na quantidade de valores da vez
    gera_vetor(vetor, qtde_valores[i])

    # Tempo de execução do Bubblesort
    copia = vetor[:]
    tempo_bubble.append(timeit.timeit(lambda: bubblesort(copia, qtde_valores[i]), number=2))
    print('Tempo de execução do Bubblesort: ', tempo_bubble[i])

    # Tempo de execução do Selectionsort
    copia = vetor[:]
    tempo_selection.append(timeit.timeit(lambda: selectionsort(copia, qtde_valores[i]), number=2))
    print('Tempo de Execução do Selectionsort: ', tempo_selection[i])

    # Tempo de execução do Insertionsort
    copia = vetor[:]
    tempo_insertion.append(timeit.timeit(lambda: insertionsort(copia, qtde_valores[i]), number=2))
    print('Tempo de Execução do Insertionsort: ', tempo_insertion[i])

    # Tempo de execução do Heapsort
    copia = vetor[:]
    tempo_heap.append(timeit.timeit(lambda: heapsort(copia), number=2))
    print('Tempo de Execução do Heapsort: ', tempo_heap[i])

    print()

print('===== ANÁLISE DOS ALGORITMOS =====\n')
plota_grafico(qtde_valores, tempo_bubble, tempo_selection, tempo_insertion, tempo_heap)
print('Tempos Bubblesort: ', tempo_bubble)
print('Tempos Selectionsort: ', tempo_selection)
print('Tempos Insertionsort: ', tempo_insertion)
print('Tempos Heapsort: ', tempo_heap)
