class Node:
    def __init__(self, value):
        self.value = int(value)
        self.left = None
        self.right = None
        self.p = None


class Binary_tree:
    def __init__(self):
        self.root = None

    def alloc_leaf(self, key):
        node = Node(key)
        return node

    def tree_insert(self, key):
        y = None
        x = self.root
        node = self.alloc_leaf(key)

        # Busca a posição para a key informada
        while x is not None:
            y = x

            if node.value < x.value:
                x = x.left
            else:
                x = x.right

        node.p = y  # o nó anterior a posição encontrada torna-se "pai" do nó inserido

        if y is None:  # Se não houver raiz na árvore, torna-se a raiz
            self.root = node
        else:  # Senão, se posiciona na árvore segundo o critério de ordenação
            if node.value < y.value:
                y.left = node
            else:
                y.right = node

    # Mostra como se organizam os nós da árvore
    def show_tree(self, x):
        if x is not None:
            if x.left is not None and x.right is None:
                print(f'{x.left.value} <- {x.value}')
                self.show_tree(x.left)

            elif x.left is None and x.right is not None:
                print(f'{x.value:>8} -> {x.right.value}')
                self.show_tree(x.right)

            elif x.left is not None and x.right is not None:
                print(f'{x.left.value} <- {x.value} -> {x.right.value}')
                self.show_tree(x.left)
                self.show_tree(x.right)

    def preorder(self, root):
        if root:
            print(root.value, end=" ")
            self.preorder(root.left)
            self.preorder(root.right)

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.value, end=" ")
            self.inorder(root.right)

    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.value, end=" ")

    def menor_chave(self, node):
        while node.left is not None:
            node = node.left
        return node

    def maior_chave(self, node):
        while node.right is not None:
            node = node.right
        return node

    # def sucessor(self, key)
    def sucessor(self, x):
        node = self.buscar_chave(self.root, x)

        if node.right is not None:
            return self.menor_chave(node.right)
        else:
            y = node.p
            while y is not None and node == y.right:
                node = y
                y = y.p
            return y

    def buscar_chave(self, node, target):
        if node is None or node.value == target:
            return node
        elif target < node.value:
            return self.buscar_chave(node.left, target)
        else:
            return self.buscar_chave(node.right, target)

    # def remover_chave(self, node, key)
    def transplant(self, no1, no2):
        if no1.p is None:  # Se o nó a ser removido for a raiz da árvore
            self.root = no2
        else:  # Senão...
            if no1 == no1.p.left:  # Se for filho a esquerda...
                no1.p.left = no2
            else:  # Se for filho a direita...
                no1.p.right = no2
        if no2 is not None:  # Quando se quer remover uma folha
            no2.p = no1.p

    def remover_chave(self, key):
        z = self.buscar_chave(self.root, key)

        if z.left is None:
            self.transplant(z, z.right)
        else:
            if z.right is None:
                self.transplant(z, z.left)

            else:
                y = self.menor_chave(z.right)
                if y != z.right:
                    self.transplant(y, y.right)
                    y.right = z.right
                    z.right = None
                    y.right.p = y

                self.transplant(z, y)
                y.left = z.left
                z.left = None
                y.left.p = y


if __name__ == '__main__':

    tree = Binary_tree()

    print(f'=== Inserindo as chaves ===')
    n = int(input('Informe o número de chaves: '))
    for c in range(0, n):
        valor = int(input(f'Valor {c}: '))
        tree.tree_insert(valor)

    print(f'Inserção concluida!')
    print()
    print('===== ESTRUTURA DA ÁRVORE =====')
    tree.show_tree(tree.root)
    print()

    print(f'=== Mostrando o percurso preoder, inorder e postorder ===')
    print("- Preorder: ", end="")
    tree.preorder(tree.root)
    print("\n- Inorder: ", end="")
    tree.inorder(tree.root)
    print("\n- Postorder: ", end="")
    tree.postorder(tree.root)
    print()
    print()

    print(f'=== Encontrando o minimo e o maximo ===')
    print(f'Minimo: {tree.menor_chave(tree.root).value}')
    print(f'Maximo: {tree.maior_chave(tree.root).value}')

    print(f'=== Encontrando os sucessores das seguintes chaves ===')

    print('Sucessor da chave 3:', tree.sucessor(3).value)
    print('Sucessor da chave 52:', tree.sucessor(52).value)
    print('Sucessor da chave 16:', tree.sucessor(16).value)

    print(f'=== Removendo as seguintes chaves ===')
    print(f'Removendo a chave 12:')
    tree.remover_chave(12)
    tree.show_tree(tree.root)
    # precisa disso? tree.preorder(tree.root)

    print(f'Removendo a chave 30:')
    tree.remover_chave(30)
    tree.show_tree(tree.root)

    # precisa disso? tree.preorder(tree.root)
    print(f'Removendo a chave 43:')
    tree.remover_chave(43)
    tree.show_tree(tree.root)
    # precisa disso? tree.preorder(tree.root)

    print()
    print(f'=== Mostrando o percurso preoder, inorder e postorder ===')
    print("- Preorder: ", end="")
    tree.preorder(tree.root)
    print("\n- Inorder: ", end="")
    tree.inorder(tree.root)
    print("\n- Postorder: ", end="")
    tree.postorder(tree.root)
    print()
    print()
