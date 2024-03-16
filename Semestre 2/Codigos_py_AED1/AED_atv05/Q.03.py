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


if __name__ == '__main__':
    # Função
    def poda_folhas(x):
        if x is not None:
            if x.left is not None:  # Procura por folhas na árvore esquerda
                poda_folhas(x.left)
                poda_folhas(x.right)
            elif x.right is not None:  # Procura por folhas na árvore direita
                poda_folhas(x.left)
                poda_folhas(x.right)
            else:
                if x.p.left == x:  # Se encontrar a folha, verifica se ela é filha à direita ou à esquerda
                    x.p.left = None  # Poda a folha à esquerda
                    x.p = None
                else:
                    x.p.right = None  # Poda a folha à direita
                    x.p = None

    # Código Principal
    arvore = BinaryTree()

    # Pede para o usuário montar uma árvore
    n = int(input('Informe quantos nós terá a árvore: '))

    for c in range(0, n):
        valor = int(input(f'Valor {c + 1}: '))
        arvore.tree_insert(valor)

    print('========== ÁRVORE COMPLETA ===========')
    arvore.show_tree(arvore.root)

    # Após podar as folhas, reescreve a árvore
    poda_folhas(arvore.root)

    print('========== ÁRVORE PODADA ===========')
    arvore.show_tree(arvore.root)
