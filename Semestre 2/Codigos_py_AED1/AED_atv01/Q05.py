# Resposta Questão 05

# Função recursiva
def Josephus(array, k, indice=0):
    # Caso base
    if len(array) == 1:
        return array[0]

    # Passo recursivo
    indice += k

    if indice >= len(array):
        indice = indice % len(array)

    array.pop(indice)
    return Josephus(array, k, indice)


# Código principal
soldados = []
num = int(input('Informe o número de soldados: '))
for c in range(0, num):
    soldados.append(c)

passo = int(input('Informe o passo com o qual os soldados se matarão: '))

sobrevivente = Josephus(soldados, passo)

print(f'O soldado sobrevivente estava na posição {sobrevivente + 1}.')
