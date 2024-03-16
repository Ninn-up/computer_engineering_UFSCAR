# Resposta Questão 03
from random import randint


# Função recursiva
def maior(array, m=0):
    # Caso base
    if len(array) == 0:
        return m

    # Passo recursivo
    if m < array[0]:
        m = array[0]

    return maior(array[1:], m)


# Código Principal
# Criando um array de valores aleatórios
v = [randint(1, 50) for _ in range(randint(1, 10))]

# Resultado
maior_elem = maior(v)

print(f'O maior elemento do array {v} é {maior_elem}')
print(f"O algoritmo {'' if maior_elem == max(v) else 'não '}funcionou, pois max(v) = {max(v)} = {maior_elem}")
