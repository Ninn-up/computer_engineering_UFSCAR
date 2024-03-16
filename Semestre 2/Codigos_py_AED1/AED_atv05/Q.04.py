# TADs
# TreeNode
class TreeNode:
    def __init__(self, key):
        self.key = int(key)
        self.p = None
        self.left = None
        self.right = None


# Binary Tree
class BinaryTree:
    def __init__(self):
        self.root = None
        self.size = 0

    def alloc_leaf(self, key):  # Cria uma folha (nó) na árvore
        node = TreeNode(key)
        node.left = None
        node.right = None
        return node

    def tree_insert(self, key):  # Insere um novo nó na árvore com o valor desejado
        y = None
        x = self.root
        node = self.alloc_leaf(key)

        while x is not None:
            y = x

            if node.key < x.key:
                x = x.left
            else:
                x = x.right

        node.p = y

        if y is None:
            self.root = node
        else:
            if node.key < y.key:
                y.left = node
            else:
                y.right = node

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
                self.show_tree(x.left)
                self.show_tree(x.right)

    # Busca o nó que se quer saber a altura e retorna a sua altura na árvore
    def tree_height(self, x, key):
        if x is None:
            return 0
        if x.key == key:
            return self.biggest_way(x)
        if key < x.key:
            return self.tree_height(x.left, key)
        else:
            return self.tree_height(x.right, key)

    # Encontra o maior caminho de um nó até uma folha
    def biggest_way(self, x):
        h1 = h2 = 0
        if x.right is None and x.left is None:
            return 0
        if x.right is None:
            return self.biggest_way(x.left) + 1
        if x.left is None:
            return self.biggest_way(x.right) + 1
        if x.right is not None and x.left is not None:
            h1 = self.biggest_way(x.left) + 1
            h2 = self.biggest_way(x.right) + 1

            if h1 > h2:
                return h1
            return h2


if __name__ == "__main__":
    # Código principal
    arvore = BinaryTree()

    # Pede para o usuário montar a árvore
    n = int(input('Informe quantos nós terá a árvore: '))

    for c in range(0, n):
        valor = int(input(f'Valor {c + 1}: '))
        arvore.tree_insert(valor)

    # Mostra como estão organizados os nós na árvore
    arvore.show_tree(arvore.root)

    no = int(input("Informe um valor para calcular sua altura na árvore: "))

    print(f"A altura desse nó na árvore é: {arvore.tree_height(arvore.root, no)}")
