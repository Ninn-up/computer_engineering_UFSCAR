# Classe Stack
class Stack:
    def __init__(self):  # Inicializa a pilha
        self.items = []

    def push(self, data):  # Adiciona um elemento ao topo da pilha
        self.items.append(data)

    def pop(self):  # Retira o elemento do topo da pilha
        return self.items.pop()

    def size(self):
        return len(self.items)

    def is_empty(self):
        return len(self.items) == 0

    def peek(self):
        return self.items[-1]

class FilaPilha:
    def __init__(self):  # Inicializa a fila como duas pilhas
        self.keys1 = Stack()
        self.keys2 = Stack()

    def sizeF(self):  # Indica o tamanho da pilha
        return self.keys1.size() + self.keys2.size()

    def is_emptyF(self):  # Verifica se a fila está vazia (faz o mesmo que na pilha)
        return self.sizeF == 0

    def enqueue(self, item):
        self.keys2.push(item)

    def dequeue(self):
        if self.keys1.is_empty():
            for i in range(0, self.keys2.size()):
                self.keys1.push(self.keys2.pop())

        return self.keys1.pop()

if __name__ == '__main__':
    # Testes da classe filaPilha

    fila = FilaPilha()

    for c in range(0, 5):
        fila.enqueue(c + 1)
        print(f'Entrando na lista: {c + 1}')

    print(f'Saindo da fila: {fila.dequeue()}')
    print(f'Saindo da fila: {fila.dequeue()}')

    for c in range(5, 11):
        fila.enqueue(c + 1)
        print(f'Entrando na lista: {c + 1}')

    print(f'Saindo da fila: {fila.dequeue()}')
    print(f'Saindo da fila: {fila.dequeue()}')
    print(f'Saindo da fila: {fila.dequeue()}')

    for c in range(12, 16):
        fila.enqueue(c + 1)
        print(f'Entrando na lista: {c + 1}')

    for c in range(0, 4):
        print(f'Saindo da fila: {fila.dequeue()}')
