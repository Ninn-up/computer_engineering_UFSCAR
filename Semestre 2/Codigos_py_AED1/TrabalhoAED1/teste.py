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


if __name__ == '__main__':
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

    pacientes = [t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20]
    doadores = [k1, k2, k3, k4, k5, k6, k7, k8, k9, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20]

    # Gale Shapley (pacientes dominantes)
    i = j = 0
    restantes = 20
    nao_encontrado = []

    controle = 0

    while restantes > 0:
        # Após verificar o melhor parceiro de cada paciente,
        #  reinicia para conseguir unir os pacientes com os doadores com pior posição
        if i == 20:
            i = 0
            j += 1
            print('Ainda faltam ', restantes)
            print(f'{j + 1}ª rodada de tentativa')

        if pacientes[i].livre:  # Verifica se o paciente da vez está sem par
            print('Início, verifica paciente: ' + str(i+1))

            try:
                vp = doadores[pacientes[i].lista_pref[j] - 1]  # Pega a melhor opção de doador do paciente no momento
                print('Doador: ' + str(pacientes[i].lista_pref[j]))
                rank = None

            except IndexError:
                print('Não encontrado doador para o paciente ' + str(i+1))
                nao_encontrado.append(i)
                restantes -= 1
                i += 1
                controle = 1

            if controle != 1:
                # Tenta pegar a posição atual do paciente. Caso não consiga, retorna -1
                try:
                    rank = vp.lista_pref.index(i + 1)

                except ValueError:
                    rank = -1
                    print(f'Paciente {i + 1} não está na lista de preferêcia do doador {pacientes[i].lista_pref[j]}')

                print('Posição do paciente na lista do doador: ', rank)
                if rank >= 0:
                    if vp.livre:
                        vp.setDoacao(rank)
                        print(vp.doacao)
                        pacientes[i].setDoacao(j)
                        print(pacientes[i].doacao)
                        restantes -= 1
                        print('Doou')
                        print('Ainda faltam ', restantes)

                    else:
                        partner = vp.doacao
                        print(f'O doador {pacientes[i].lista_pref[j]} está junto de {vp.lista_pref[partner]}')

                        if partner > rank:
                            pacientes[vp.lista_pref[partner] - 1].eraseMatch()
                            print(pacientes[vp.lista_pref[partner] - 1].livre)
                            print(pacientes[vp.lista_pref[partner] - 1].doacao)
                            vp.setDoacao(rank)
                            pacientes[i].setDoacao(j)
                            print(pacientes[i].doacao)
                            print('Trocou e doou')

            i += 1
            controle = 0

        else:
            print("caiu no else " + str(i))
            i += 1

    print('==== PARES ====')
    for c in range(0, 19):
        if pacientes[c].doacao < 0:
            print(f'(t{c + 1},k-): sem doador', end=' ')
        else:
            print(f'(t{c+1},k{pacientes[c].lista_pref[pacientes[c].doacao]})', end=' ')
