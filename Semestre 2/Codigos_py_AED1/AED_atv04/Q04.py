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
            temp = temp.next

        if temp == self.head:
            self.head = temp.next

        else:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev

        temp.prev = None
        temp.next = None
        self.size -= 1

    def change_head(self):
        temp = self.head.prev.key
        self.remove(temp)
        self.add_head(temp)


if __name__ == '__main__':
    # Função
    def rotate(dl, k):
        for c in range(0, k):
            dl.change_head()


    # Código Principal
    lista = CircularLinkedList()

    tam = int(input('Tamanho da lista a ser criada: '))

    for i in range(0, tam):
        lista.add_tail(int(input(f'{i + 1}º Valor: ')))

    pos = int(input('Posições para rotacionar: '))

    rotate(lista, pos)

    # Imprime os valores da lista rotacionada
    aux = lista.head
    print(f'Lista rotacionada em {pos} posições: ', end=' ')
    for e in range(0, lista.size):
        print(aux.key, end=' ')
        aux = aux.next

