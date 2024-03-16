# Classe Stack
class Stack:
    def __init__(self):  # Inicializa a pilha
        self.items = []

    def push(self, data):  # Adiciona elementos ao topo da pilha
        self.items.append(data)

    def pop(self):  # Retira elementos do topo da pilha
        return self.items.pop()

    def size(self):  # Informa o tamanho da pilha
        return len(self.items)

    def is_empty(self):  # Verifica se a pilha está vazia
        return self.size() == 0

    def peek(self):  # Verifica qual elemento está no topo da pilha
        return self.items[-1]


if __name__ == '__main__':
    # Função
    def pont_max(x, y, MAX_SUM):
        p = soma = 0
        tam = x.size() + y.size()

        while p < tam and soma < MAX_SUM:
            # Verifica se nenhuma das pilhas está vazia
            if not x.is_empty() and not y.is_empty():
                # Compara os elementos do topo das pilhas e remove o menor deles
                if x.peek() < y.peek():
                    soma += x.pop()
                else:
                    soma += y.pop()
            # Casos em que alguma pilha está vazia
            elif not y.is_empty:
                # Caso em que a pilha A (x) está vazia
                soma += y.pop()
            else:
                # Caso em que a pilha B (y) está vazia
                soma += x.pop()

            # Aumenta os pontos do jogador após a retirada de um elemento
            p += 1

        return p

    # Código Principal
    a = Stack()
    b = Stack()

    n = int(input('Informe o tamanho da pilha A: '))
    m = int(input('Informe o tamanho da pilha B: '))
    max = int(input('Informe a soma acumulada máxima: '))

    for c in range(0, n):
        elem1 = int(input(f'Informe o {c + 1}º elemento para A: '))
        a.push(elem1)

    for d in range(0, m):
        elem2 = int(input(f'Informe o {d + 1}º elemento para B: '))
        b.push(elem2)

    print(f'Com essas pilhas, a pontuação máxima possível é {pont_max(a, b, max)}')
