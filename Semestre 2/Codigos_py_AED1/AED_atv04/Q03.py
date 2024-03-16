# Lista duplamente encadeada circular
class Node:
    def __init__(self, key):
        self.key = int(key)
        self.next = None
        self.prev = None


class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def add_head(self, key):
        temp = Node(key)

        if self.head is None:
            self.head = temp
            temp.next = None
        else:
            temp.next = self.head
            self.head.prev = temp
            self.head = temp

        self.size += 1

    def add_tail(self, key):
        tail = Node(key)

        if self.head is None:
            self.head = tail
            tail.prev = None
        else:
            temp = self.head

            while temp.next is not None:
                temp = temp.next
            temp.next = tail
            tail.prev = temp

        tail.next = None
        self.size += 1

    def remove(self, key):
        temp = self.head

        while temp is not None and temp.key != key:
            temp = temp.next

        if temp == self.head:
            self.head = temp.next

        else:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev

        temp.prev = None
        temp.next = None
        self.size -= 1

    def selection_sort(self):
        aux = self.head
        # Enquanto diferente de None
        while aux:
            menor = aux
            temp = aux.next
            while temp:
                if temp.key < menor.key:
                    menor = temp
                temp = temp.next
            # Troca entre os nós
            temp = aux.key
            aux.key = menor.key
            menor.key = temp
            aux = aux.next


if __name__ == '__main__':

    # Código Principal
    lista = DoubleLinkedList()

    tam = int(input('Tamanho da lista a ser criada: '))

    for i in range(0, tam):
        lista.add_tail(int(input(f'{i + 1}º Valor: ')))

    lista.selection_sort()

    # Imprime os valores da lista ordenada
    h = lista.head
    print(f'Lista ordenada: ', end=' ')
    for e in range(0, lista.size):
        print(h.key, end=' ')
        h = h.next

