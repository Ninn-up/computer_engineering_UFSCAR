# Classe Stack
class Stack:
    def __init__(self):  # Inicializa a pilha
        self.items = []

    def push(self, data):  # Adiciona itens a pilha
        self.items.append(data)

    def pop(self):  # Retira o último elemento da pilha
        return self.items.pop()

    def size(self):  # Informa o tamanho da pilha
        return len(self.items)

    def is_empty(self):  # Verifica se a pilha está vazia
        return len(self.items) == 0

    def peek(self):  # Verifica qual o elemento no topo da pilha
        return self.items[-1]


if __name__ == '__main__':
    # Função
    def palindromo(word):
        s = Stack()
        word = word.upper()
        eh_palindromo = True

        for c in range(0, len(word)):
            s.push(word[c])  # Adiciona as letras da palavra na pilha

        # Verifica se, ao contrário, a palavra continua a mesma
        i = 0
        while i < len(word) and eh_palindromo:
            if s.pop() != word[i]:
                eh_palindromo = False
                
            i += 1

        return eh_palindromo


#  Código Principal
p = str(input('Digite uma palavra: '))

if palindromo(p):
    print('É palíndromo!')
else:
    print('Não é palíndromo!')
