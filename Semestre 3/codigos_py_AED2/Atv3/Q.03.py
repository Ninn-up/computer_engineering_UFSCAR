from math import floor
from random import randint


# Tabela Hash de Endereçamento Aberto
class HashTable:
    def __init__(self, m):
        self.size = m
        self.T = [None] * m  # Tabela (T) com as m posições estabelecidas
        self.acessos = 0

    # Função Hash auxiliar (Linear)
    def fn_aux(self, key):  # Utiliza-se o método da divisão para calcular o índice
        index = key % self.size
        return index

    # Função Hash para Linear Probing
    def fn_hash(self, key, i):
        index = (self.fn_aux(key) + 2 * i + pow(i, 2)) % self.size  # O index depende da fn. aux e do i
        return index

    # Função de inserção na Tabela Hash
    def hash_insert(self, key):
        i = 0  # Inicializa o contador

        while i != self.size:  # Enquando não chega ao final da tabela...
            q = self.fn_hash(key, i)
            # Se houver espaço para adicionar essa chave na posição q, ela é adicionada.
            if self.T[q] is None:
                self.T[q] = key
                return q

            # Se encontrar alguma chave repetida, não a adiciona e termina o processo
            if self.T[q] == key:
                return False

            print(f'A chave {key} colidiu com {self.T[q]} em i = {i}')
            i += 1  # Atualiza o contador (próxima tentativa da função hash)

        # Se a tabela estiver cheia ou h(key, i) sempre igual a posição de outras chaves...
        print(f'Não há posição livre para a chave {key}')
        return False

    # Funcão de busca na Tabela Hash
    def hash_search(self, key):
        i = 0  # Inicializa o contador
        acessos = 1  # Inicializa o contador de acessos
        q = self.fn_hash(key, i)  # Calcula a primeira posição para a key

        # Enquanto não achar uma posição calculada que esteja vazia, nem verificar todas as posições possíveis...
        while self.T[q] is not None and i != self.size:
            if self.T[q] == key:
                self.acessos += acessos
                print(f'A chave {key} foi encontrada após {acessos} acesso(s).')
                return q  # Encontrou a chave na posição q

            i += 1  # Atualiza o contador
            acessos += 1
            q = self.fn_hash(key, i)  # Calcula a próxima posição para a key

        # Ao sair do loop, sabemos que a chave não foi encontrada
        print(f'A chave {key} não foi encontrada na tabela hash após {acessos} acesso(s)')
        self.acessos += acessos
        return False

    def hash_remove(self, key):
        # Procura a chave que se deseja remover
        busca = self.hash_search(key)

        if busca is not False:
            self.T[busca] = None
            return True
        return False

    def print_hash(self):
        print('=' * 20)
        for d in range(0, self.size):  # Imprime os elementos presentes na tabela até o momento
            print(f'[{d}] = {self.T[d]}')
        print('=' * 20)


# Código Principal
if __name__ == '__main__':
    TH = HashTable(17)  # Cria uma tabela Hash com 17 slots

    # Inserindo as chaves
    TH.hash_insert(371)
    TH.hash_insert(121)
    TH.hash_insert(173)
    TH.hash_insert(203)
    TH.hash_insert(11)
    TH.hash_insert(24)
    TH.hash_insert(10)
    TH.hash_insert(22)
    TH.hash_insert(31)
    TH.hash_insert(4)
    TH.hash_insert(15)
    TH.hash_insert(28)
    TH.hash_insert(17)
    TH.hash_insert(88)
    TH.hash_insert(59)

    # Mostrando a tabela hash
    TH.print_hash()