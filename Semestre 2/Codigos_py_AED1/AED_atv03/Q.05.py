class Stack:
    def __init__(self):  # Inicializa a pilha
        self.items = []

    def push(self, data):  # Adiciona um elemento no topo da pilha
        self.items.append(data)

    def pop(self):  # Retira o elemento do topo da pilha
        return self.items.pop()

    def size(self):  # Informa o tamanho da pilha
        return len(self.items)

    def is_empty(self):  # Verifica se a pilha está vazia
        return len(self.items) == 0

    def peek(self):  # Informa o elemento no topo da pilha
        return self.items[-1]


class Queue:
    def __init__(self):  # Inicializa a fila
        self.keys = []

    def is_empty_q(self):  # Verifica se a fila está vazia
        return self.keys == []

    def enqueue(self, item):  # Adiciona um elemento no fim da fila
        self.keys.insert(0, item)

    def dequeue(self):  # Retira um elemento do início da fila
        return self.keys.pop()

    def size_q(self):  # Informa o tamanho da fila
        return len(self.keys)

    def peek_q(self):  # Informa o primeiro elemento da fila
        return self.keys[-1]


if __name__ == '__main__':
    # Função
    def lanche_estudantes(sanduiches, estudantes):
        # Contador que verifica quando um estudante não quer comer o lanche do topo da pilha
        nao_come = 0

        # Enquanto a lista e a pilha não estiverem vazias
        # E enquanto os estudantes quiserem comer o lanche do topo
        while (not sanduiches.is_empty()) and nao_come < estudantes.size_q():
            # Se a preferência do primeiro estudante for o lanche do topo da pilha...
            if sanduiches.peek() == estudantes.peek_q():
                # O estudante e o lanche saem da fila/pilha
                sanduiches.pop()
                estudantes.dequeue()
                nao_come = 0  # Reinicia a contagem, pois quem não comeu ainda pode conseguir comer

            # Se a preferência do estudante não for o lanche do topo da pilha...
            else:
                # O estudante da vez vai para o fim da fila
                estudantes.enqueue(estudantes.dequeue())
                nao_come += 1  # Contabiliza esse estudante que não comeu

        # Ao final restará apenas os estudantes que mesmo após se deslocarem na fila não conseguiram comer
        return nao_come


    # Código Principal
    s = Stack()
    e = Queue()

    sand = [int(sand) for sand in input("Array de sanduíches: ").split()]
    est = [int(est) for est in input("Array de estudantes: ").split()]

    tam = len(sand)
    # Adiciona os valores em uma Stack e em uma Queue
    for c in range(0, tam):
        s.push(sand[tam - 1 - c])
        print(sand[tam - 1 - c])
        e.enqueue(est[c])

    print(f'Há {lanche_estudantes(s, e)} estudante(s) sem comer.')
