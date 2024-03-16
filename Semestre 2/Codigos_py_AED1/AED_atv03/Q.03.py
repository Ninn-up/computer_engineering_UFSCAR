class Stack:
    def __init__(self):  # Inicialização da pilha
        self.items = []

    def push(self, data):  # Adiciona um elementoa no topo da pilha
        self.items.append(data)

    def pop(self):  # Retira o último elemento da pilha
        return self.items.pop()

    def size(self):  # Retorna o tamanho da pilha
        return len(self.items)

    def is_empty(self):  # Verifica se a pilha está vazia
        return len(self.items) == 0

    def peek(self):  # Verifica que elemento está no topo da pilha
        return self.items[-1]


if __name__ == '__main__':

    # Função
    def fatoracaoPrima(n, s):
        d = 2    # Menor inteiro maior que 1
        quociente = n  # Valor de n que será atualizado

        # Refere-se a: enquanto quociente / d > 1
        while d <= quociente:
            #  Verifica se o quociente é divisível por d
            if quociente % d == 0:
                quociente = quociente / d
                s.push(d)  # Adiciona d (fator primo) a pilha

            # Se não for divisível, passa para o próximo número
            else:
                d += 1

    # Código principal
    fatores = Stack()

    num = int(input("Informe um valor para verificar sua fatoração prima: "))

    fatoracaoPrima(num, fatores)
    tam = fatores.size()

    # Imprime a fatoração prima em ordem decrescente
    for c in range(0, tam):
        if c != (tam - 1):
            print(fatores.pop(), end=" * ")
        else:
            print(fatores.pop())
