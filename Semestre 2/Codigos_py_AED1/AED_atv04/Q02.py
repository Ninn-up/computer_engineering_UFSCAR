# Lista Encadeada
class Node:
    def __init__(self, key):
        self.key = int(key)
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def add_head(self, key):  # Adiciona elementos no início da lista
        temp = Node(key)
        temp.next = self.head
        self.head = temp
        self.size += 1

    def add_tail(self, key):
        tail = Node(key)

        if self.head is None:
            self.head = tail

        else:
            temp = self.head

            while temp.next is not None:
                temp = temp.next

            temp.next = tail

        self.size += 1
        tail.next = None

    def remove(self, key):
        temp = self.head
        previous = None

        while temp is not None and temp.key != key:
            previous = temp
            temp = temp.next

        if previous is None:
            self.head = temp.next

        else:
            previous.next = temp.next

        temp.next = None


if __name__ == '__main__':
    # Função
    def merge(l1, l2):
        l3 = LinkedList()
        tam = l1.size + l2.size
        for i in range(0, tam):
            r1 = l1.head
            r2 = l2.head
            if r1 is not None and r2 is not None:
                if l1.head.key < l2.head.key:
                    l3.add_tail(r1.key)
                    l1.remove(r1.key)

                else:
                    l3.add_tail(r2.key)
                    l2.remove(r2.key)

            elif r1 is None:
                l3.add_tail(r2.key)
                l2.remove(r2.key)

            else:
                l3.add_tail(r1.key)
                l1.remove(r1.key)

        return l3

    lista1 = LinkedList()
    lista2 = LinkedList()

    print('Valores para a lista 1')
    for c in range(0, 6):
        lista1.add_tail(int(input(f'{c + 1}º Valor: ')))

    print('Valores para a lista 2')
    for d in range(0, 8):
        lista2.add_tail(int(input(f'{d + 1}º Valor: ')))

    combinada = merge(lista1, lista2)

    # Imprime os valores da lista combinada
    aux = combinada.head
    print('Lista combinada: ', end=' ')
    for e in range(0, combinada.size):
        print(aux.key, end=' ')
        aux = aux.next
