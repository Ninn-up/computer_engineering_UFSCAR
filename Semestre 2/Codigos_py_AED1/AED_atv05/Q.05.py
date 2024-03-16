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

    def alloc_leaf(self, key):
        node = TreeNode(key)
        return node

    def tree_insert(self, key):
        y = None
        x = self.root
        node = self.alloc_leaf(key)

        # Busca a posição para a key informada
        while x is not None:
            y = x

            if node.key < x.key:
                x = x.left
            else:
                x = x.right

        node.p = y  # o nó anterior a posição encontrada torna-se "pai" do nó inserido

        if y is None:  # Se não houver raiz na árvore, torna-se a raiz
            self.root = node
        else:  # Senão, se posiciona na árvore segundo o critério de ordenação
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

    def node_depth(self, x, key):
        depth = 0
        if x is None:
            return 0
        if x.key == key:
            return self.root_way(x)
        if key < x.key:
            return self.node_depth(x.left, key)
        else:
            return self.node_depth(x.right, key)

    def root_way(self, x):
        if x.p is None:
            return 0
        return self.root_way(x.p) + 1


if __name__ == '__main__':
    # Código principal
    arvore = BinaryTree()

    # Pede para o usuário montar a árvore
    n = int(input('Informe quantos nós terá a árvore: '))

    for c in range(0, n):
        valor = int(input(f'Valor {c + 1}: '))
        arvore.tree_insert(valor)

    # Mostra como estão organizados os nós na árvore
    arvore.show_tree(arvore.root)

    no = int(input("Informe um valor para calcular sua profundidade na árvore: "))

    print(f'A profundidade desse nó na árvore é: {arvore.node_depth(arvore.root, no)}')
