# Lista Encadeada (Linked List)
class Node:
    def __init__(self, key):  # Inicializa o nó com encadeamento
        self.key = int(key)
        self.next = None


class LinkedList:
    def __init__(self):  # Inicializa a lista encadeada
        self.head = None
        self.size = 0

    def add_head(self, key):  # Adiciona elementos no início da lista
        temp = Node(key)  # Cria o nó com a key informada para ser adicionado a lista
        temp.next = self.head  # Liga o novo nó a antiga "head"
        self.head = temp  # O novo nó torna-se a nova "head"
        self.size += 1  # Incrementa o contador que informa o tamanho da lista

    def add_tail(self, key):  # Adiciona elementos no fim da lista
        tail = Node(key)

        # Se a lista estiver vazia...
        if self.head is None:
            self.head = tail  # Adiciona como "head" da lista

        # Senão...
        else:
            # Será necessário verificar qual o último elemento atual e adicionar o novo nó após ele
            temp = self.head

            # Enquanto não encontrar o fim da lista...
            while temp.next is not None:
                temp = temp.next  # Muda para o próximo nó

            temp.next = tail  # O novo nó é adicionado ao fim da lista

        self.size += 1

    def remove(self, key):
        # Inicia a busca pelo elemento a ser removido na "head"
        temp = self.head
        previous = None

        # Enquanto não chegar ao fim da lista ou encontrar a key...
        while temp is not None and temp.key != key:
            # Se "desloca" pela lista
            previous = temp
            temp = temp.next

        # Se a key procurada estiver na "head"...
        if previous is None:  # Se a key procurada estiver no início da lista
            self.head = temp.next  # A nova "head" torna-se o próximo nó

        else:  # Senão, o nó anterior, ligado ao nó procurado, é ligado ao que vem depois
            previous.next = temp.next
            temp.next = None  # Apaga a conexão entre temp.next e temp

        # Retorna o valor apagado
        return temp


if __name__ == '__main__':

    # Função
    def inverte(l1, l2):
        # Remove os elementos de uma lista encadeada e a inverte inserindo em outra lista
        for d in range(0, l1.size):
            removed = l1.remove(l1.head.key)
            l2.add_head(removed.key)

    # Código principal
    old = LinkedList()
    new = LinkedList()

    # Pede os valores da lista encadeada que será invertida
    for c in range(0, 10):
        old.add_tail(int(input(f'Valor {c + 1}: ')))

    inverte(old, new)
    
    # Imprime os valores da lista invertida
    aux = new.head
    for e in range(0, new.size):
        print(aux.key, end=' ')
        aux = aux.next
