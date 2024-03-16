# Lista duplamente encadeada circular
class Node:
    def __init__(self, key):
        self.key = int(key)
        self.next = None
        self.prev = None


class CircularLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def add_head(self, key):
        temp = Node(key)

        if self.head is None:
            self.head = temp
            temp.next = temp
            temp.prev = temp
        else:
            temp.next = self.head
            self.head.prev.next = temp
            temp.prev = self.head.prev
            self.head.prev = temp
            self.head = temp

        self.size += 1

    def add_tail(self, key):
        temp = Node(key)

        if self.head is None:
            self.head = temp
            temp.next = temp
            temp.prev = temp
        else:
            temp.next = self.head
            temp.prev = self.head.prev
            self.head.prev.next = temp
            self.head.prev = temp

        self.size += 1

    def remove(self, key):
        temp = self.head

        while temp is not None and temp.key != key:
            temp = temp.prev

        if temp == self.head:
            self.head = temp.next

        else:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev

        temp.prev = None
        temp.next = None
        self.size -= 1

    def peek(self, i):
        temp = self.head
        for c in range(0, i):
            temp = temp.next

        if temp is not None:
            return temp.key

        return 1


if __name__ == '__main__':
    # Função
    def apaga_duplicado(dl):
        i = 0
        while i < (dl.size - 1):
            count = i + 1
            aux = dl.peek(i)
            print(f'aux {aux}')
            print(dl.peek(count))
            while count < dl.size:
                if aux == dl.peek(count):
                    print(f'removeu {dl.peek(count)}')
                    dl.remove(dl.peek(count))
                    count -= 1

                count += 1
                print(f'Contador {count}')

            i += 1
            print(dl.size)

    # Código Principal
    lista = CircularLinkedList()

    size = int(input('Tamanho da lista a ser criada: '))

    for d in range(0, size):
        lista.add_tail(int(input(f'{d + 1}º Valor: ')))

    apaga_duplicado(lista)

    # Imprime os valores da lista sem elementos duplicados
    h = lista.head
    print('Lista sem elementos duplicados: ', end=' ')
    for e in range(0, lista.size):
        print(h.key, end=' ')
        h = h.next

