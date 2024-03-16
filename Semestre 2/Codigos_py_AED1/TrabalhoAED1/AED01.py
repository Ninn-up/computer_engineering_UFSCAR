# Classe Pessoa
class Pessoa:
    def __init__(self, lista_pref):
        self.lista_pref = lista_pref
        self.livre = True
        self.doacao = -1

    def setDoacao(self, pessoa_match):
        self.doacao = pessoa_match
        self.livre = False

    def eraseMatch(self):
        self.livre = True
        self.doacao = -1


# Código principal
if __name__ == '__main__':

    # Pacientes
    t1 = Pessoa([9, 14, 8, 18, 13, 7])
    t2 = Pessoa([14, 8, 9, 13, 18, 7])
    t3 = Pessoa([9, 8, 14, 18, 7, 13])
    t4 = Pessoa([13, 18, 7, 8, 14, 9])
    t5 = Pessoa([7, 18, 13, 9, 8, 14])
    t6 = Pessoa([18, 7, 13, 14, 9, 8])
    t7 = Pessoa([19, 20, 2, 16, 9, 14, 8, 18, 7, 13, 15, 1])
    t8 = Pessoa([19, 2, 20, 16, 9, 14, 8, 7, 18, 13, 1, 15])
    t9 = Pessoa([2, 19, 20, 9, 16, 14, 18, 8, 7, 13, 1, 15])
    t10 = Pessoa([2, 20, 19, 9, 14, 16, 8, 18, 7, 13, 15, 1])
    t11 = Pessoa([2, 19, 16, 20, 14, 9, 8, 18, 7, 13, 1, 15])
    t12 = Pessoa([12, 17, 9, 14, 8, 18, 13, 7, 10, 3, 4, 11])
    t13 = Pessoa([17, 12, 9, 14, 8, 18, 7, 13, 10, 4, 3, 11])
    t14 = Pessoa([9, 12, 17, 8, 14, 7, 18, 10, 13, 11, 3, 4])
    t15 = Pessoa([14, 9, 7, 12, 18, 17, 8, 13, 10, 4, 11, 3])
    t16 = Pessoa([12, 7, 11, 9, 17, 14, 3, 8, 4, 10, 13, 18])
    t17 = Pessoa([5, 6, 9, 20, 14, 8, 19, 18, 17, 13, 12, 2, 10, 11, 3, 7, 16, 15, 4, 1])
    t18 = Pessoa([5, 6, 20, 9, 8, 14, 18, 19, 12, 13, 17, 2, 3, 10, 11, 16, 7, 15, 1, 4])
    t19 = Pessoa([6, 5, 14, 8, 20, 9, 19, 18, 17, 13, 12, 11, 2, 10, 7, 3, 15, 16, 1, 4])
    t20 = Pessoa([6, 5, 8, 9, 20, 14, 18, 19, 12, 17, 13, 11, 2, 10, 3, 7, 15, 16, 4, 1])

    # Doadores
    k1 = Pessoa([11, 8, 10, 19, 18, 20, 9, 12])
    k2 = Pessoa([8, 10, 11, 9, 12, 19, 20, 18])
    k3 = Pessoa([16, 13, 14, 15, 16, 19, 20, 18])
    k4 = Pessoa([16, 15, 13, 14, 17, 18, 20, 19])
    k5 = Pessoa([18, 19, 20, 12, 15, 14, 17, 16])
    k6 = Pessoa([19, 18, 20, 5, 12, 13, 16, 17])
    k7 = Pessoa([4, 3, 5, 2, 7, 1, 11, 9, 10, 8, 14, 13, 16, 19, 20, 15, 17, 18, 6, 12])
    k8 = Pessoa([4, 2, 3, 5, 1, 7, 9, 11, 8, 10, 14, 13, 16, 20, 19, 15, 17, 18, 6, 12])
    k9 = Pessoa([3, 4, 5, 2, 7, 1, 11, 9, 10, 8, 14, 13, 16, 19, 20, 15, 17, 18, 6, 12])
    k10 = Pessoa([16, 13, 14, 15, 17, 20, 19, 18])
    k11 = Pessoa([13, 16, 15, 14, 17, 19, 20, 18])
    k12 = Pessoa([16, 13, 15, 14, 17, 20, 19, 18])
    k13 = Pessoa([4, 2, 5, 3, 7, 1, 9, 11, 8, 10, 14, 13, 16, 20, 19, 15, 17, 18, 6, 12])
    k14 = Pessoa([3, 4, 5, 7, 2, 11, 1, 9, 10, 8, 14, 13, 20, 19, 16, 17, 15, 18, 12, 6])
    k15 = Pessoa([8, 11, 10, 19, 18, 20, 9, 12])
    k16 = Pessoa([10, 8, 11, 18, 19, 20, 12, 9])
    k17 = Pessoa([14, 16, 13, 15, 19, 17, 20, 18])
    k18 = Pessoa([5, 4, 3, 2, 7, 10, 9, 11, 1, 14, 8, 13, 20, 16, 19, 15, 17, 18, 6, 12])
    k19 = Pessoa([10, 8, 11, 19, 18, 20, 9, 12])
    k20 = Pessoa([11, 8, 10, 18, 19, 20, 9, 12])

    # Listas que armazenam todos os pacientes e os doadores que devem ser pareados
    pacientes = [t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20]
    doadores = [k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20]

    # Algoritmo de Gale Shapley (com pacientes dominantes)
    # Contadores
    i = j = 0
    restantes = 20

    # Arrays
    nao_encontrado = []  # Armazena os doadores que não possuem par
    # Armazena em qual posição da lista de preferência cada paciente "parou"
    preferencias = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    # Indica quando não for encontrado doador para o paciente
    controle = 0

    while restantes > 0:
        if i == 20:
            # Após verificar o melhor parceiro de cada paciente,
            #  reinicia para conseguir unir os pacientes com os doadores com posição pior que a anterior
            i = 0

        if pacientes[i].livre:  # Verifica se o paciente da vez está sem par
            # Tenta pegar a melhor opção de doador para o paciente no momento
            try:
                vp = doadores[pacientes[i].lista_pref[preferencias[i]] - 1]
                rank = None

            except IndexError:  # Caso não haja doador...
                nao_encontrado.append(i)
                restantes -= 1
                controle = 1

            # Se houver doador...
            if controle != 1:
                # Tenta pegar a posição atual do paciente.
                try:
                    rank = vp.lista_pref.index(i + 1)

                # Caso não consiga encontrar o paciente na lista de preferência do doador, retorna -1
                except ValueError:
                    rank = -1
                    preferencias[i] += 1

                # Se encontrar o paciente na lista de preferência do doador...
                if rank >= 0:
                    # Verifica se o doador buscado está livre
                    if vp.livre:
                        # Se estiver, realiza a troca
                        vp.setDoacao(rank)
                        pacientes[i].setDoacao(preferencias[i])
                        restantes -= 1

                    # Se não estiver, então já há um paciente com esse doador
                    else:
                        partner = vp.doacao  # Pega a posição do par no doador

                        # Verifica se a posição do par do doador é pior que a do paciente em questão
                        if partner > rank:
                            # Se for, realiza a troca e libera o paciente que estava pareado
                            pacientes[vp.lista_pref[partner] - 1].eraseMatch()
                            restantes += 1

                            vp.setDoacao(rank)
                            pacientes[i].setDoacao(preferencias[i])

                    preferencias[i] += 1  # Incrementa a posição de preferência do paciente i
            controle = 0  # Reinicia a variável de controle
        i += 1  # Incrementa para verificar o próximo paciente

    # Conta quantos pares foram formados e quantos ficaram sem par
    sem_par = pareados = 0

    # Impressão dos pares formados
    print('==== PARES ====')
    for c in range(0, 20):
        if pacientes[c].doacao < 0:
            print(f'(t{c + 1},k-): sem doador')
            sem_par += 1
        else:
            print(f'(t{c + 1},k{pacientes[c].lista_pref[pacientes[c].doacao]})')
            pareados += 1

    print(f'Foram formados {pareados} pares, restando {sem_par} pacientes sem par')
