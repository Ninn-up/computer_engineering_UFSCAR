from random import randint


# TADs
# TreeNode
class TreeNode:
    def __init__(self, key):
        self.key = int(key)
        self.p = None
        self.left = None
        self.right = None


# BinaryTree
class BinaryTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def alloc_leaf(self, key):  # Cria uma folha (nó) para a árvore
        node = TreeNode(key)
        node.left = None
        node.right = None
        return node

    def tree_insert(self, x, key):  # Insere um novo nó na árvore com o valor desejado
        if x is None:  # Se não houver nenhum nó na árvore...
            node = self.alloc_leaf(key)
            node.p = None
            self.root = node  # O nó torna-se a raiz
            self.size += 1

        else:
            if x.left is None:  # Se não houver filho a esquerda...
                node = self.alloc_leaf(key)
                node.p = x
                x.left = node  # O nó torna-se filho a esquerda
                self.size += 1

            elif x.right is None:  # Se não houver filho a direita...
                node = self.alloc_leaf(key)
                node.p = x
                x.right = node  # Torna-se um filho a direita
                self.size += 1

            else:  # Se houver os dois filhos no nó analisado...
                luck = randint(0, 2)  # Escolhe aleatoriamente em que nó buscará uma posição disponível
                if luck == 0:
                    self.tree_insert(x.left, key)
                else:
                    self.tree_insert(x.right, key)

    # Mostra como se organizam os nós da árvore
    def show_tree(self, x):
        if x is not None:
            if x.left is not None and x.right is None:
                print(f'{x.left.key} <- {x.key}')
                self.show_tree(x.left)

            elif x.left is None and x.right is not None:
                print(f'{x.key:>8} -> {x.right.key}')
                self.show_tree(x.right)

            elif x.left is not None and x.right is not None:
                print(f'{x.left.key} <- {x.key} -> {x.right.key}')
                self.show_tree(x.right)
                self.show_tree(x.left)


if __name__ == '__main__':
    # Função
    def soma_interno(x):
        if x is None:
            return 0
        else:
            if x.left is not None or x.right is not None:
                return x.key + soma_interno(x.left) + soma_interno(x.right)

            return 0

    # Código Principal
    arvore = BinaryTree()

    # Pede para o usuário montar uma árvore
    n = int(input('Informe quantos nós terá a árvore: '))

    for c in range(0, n):
        valor = int(input(f'Valor {c + 1}: '))
        arvore.tree_insert(arvore.root, valor)

    arvore.show_tree(arvore.root)

    print(soma_interno(arvore.root))
