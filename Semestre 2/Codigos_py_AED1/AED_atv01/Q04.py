# Resposta Questão 04
from random import randint
from math import trunc, sqrt


# Função recursiva
def is_prime(n, i):
    # Caso base
    if i == 1:
        return True
    if n % i == 0:
        return False

    # Passo recursivo
    return is_prime(n, i-1)


# Código Principal
# Gerando um número aleatório
numero = randint(1, 50)

# Verificando se o número é ou não primo
if is_prime(numero, trunc(sqrt(numero))):
    print(f'O número {numero} é primo')
else:
    print(f'O número {numero} não é primo')
