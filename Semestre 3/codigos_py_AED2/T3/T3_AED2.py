import heapq as hp
import networkx as nx
import matplotlib.pyplot as plt


# Função para desenhar grafo
def draw_graph(g):
    subax1 = plt.subplot(121)
    nx.draw(g, with_labels=True, font_weight='bold')
    plt.show()


# Class Node: define como serão os nós do grafo
class Node:
    def __init__(self, num):
        self.num = num
        self.predecessor = None
        self.prior = 9999

    def __lt__(self, other):
        return self.num < other.num

# Função que busca a distância entre 2 vértices no grafo
def size_way(g, u, v):
    return g[u][v]['weight']


# Função que atualiza o valor da prioridade do vértice vizinho analisado
def decrease_key(q, v, p):
    # Remove o vértice v
    q.remove([v.prior, v])
    hp.heapify(q)

    # Atualiza a sua prioridade e o adiciona novamente ao heap ("fila de prioridade")
    v.prior = p
    hp.heappush(q, [v.prior, v])


# Algoritmo de Dijkstra
def dijkstra(g, s):
    # Lista dos vértices
    nodes = []
    # Adiciona os vértices do grafo
    for v in list(g.nodes):
        nodes.append(v)

    size = len(nodes)

    # Definindo a raiz
    for c in range(size):
        if nodes[c] == s:  # Buscando o vértice que será a raiz...
            nodes[c].prior = 0  # Ao encontrar, define sua prioridade como 0

    # Fila de Prioridades (no caso, um heap)
    Q = []

    # Preenchendo a fila...
    for c in range(0, size):
        elem = [nodes[c].prior, nodes[c]]  # Adiciona a estrutura "[prioridade, vértice]" na fila de prioridades
        hp.heappush(Q, elem)

    # Verificando o caminho mínimo
    while Q:
        # Retira da fila o vértice de menor prioridade (custo do menor caminho)
        popped_v = hp.heappop(Q) 

        # Verifica os vizinhos do vértice removido
        for nbr in list(g.adj[popped_v[1]]):
            if [nbr.prior, nbr] in Q:
                # Verifica qual é o menor caminho para os vizinhos
                min_way = min(nbr.prior, popped_v[0] + size_way(g, popped_v[1], nbr))

                # Se houver ocorrido mudança no valor do caminho mínimo...
                if min_way != nbr.prior:
                    # O predecessor passa a ser o vértice recém removido (em análise)
                    nbr.predecessor = popped_v[1]

                    # Atualiza-se o valor da prioridade na lista (e na classe)
                    decrease_key(Q, nbr, min_way)


# Código Principal
if __name__ == '__main__':
    # Vértices do grafo
    V0 = Node(0)
    V1 = Node(1)
    V2 = Node(2)
    V3 = Node(3)
    V4 = Node(4)
    V5 = Node(5)
    V6 = Node(6)
    V7 = Node(7)
    V8 = Node(8)

    # Grafo
    # Lista de Vértices do Grafo
    V_graph = [V0, V1, V2, V3, V4, V5, V6, V7, V8]
    size = len(V_graph)

    # Gerando a estrutura
    G = nx.Graph()
    G.add_nodes_from(V_graph)

    # Adicionando Adjascências ao Grafo
    G.add_edges_from([(V0, V1, {'weight': 4}), (V0, V6, {'weight': 7}), (V1, V6, {'weight': 11}), (V1, V2, {'weight': 9})])
    G.add_edges_from([(V1, V7, {'weight': 20}), (V2, V3, {'weight': 6}), (V2, V4, {'weight': 2}), (V3, V4, {'weight': 10})])
    G.add_edges_from([(V3, V5, {'weight': 5}), (V4, V5, {'weight': 15}), (V4, V7, {'weight': 1}), (V4, V8, {'weight': 5})])
    G.add_edges_from([(V5, V8, {'weight': 12}), (V6, V7, {'weight': 1}), (V7, V8, {'weight': 3})])

    # Desenhando o Grafo
    #draw_graph(G)

    # Execução do algoritmo
    dijkstra(G, V0)

    # Representação da árvore de caminhos mínimos
    V_min_way = [0, 1, 2, 3, 4, 5, 6, 7, 8]
    min_tree = nx.Graph()
    min_tree.add_nodes_from(V_min_way)

    for c in range(size):
        if V_graph[c].predecessor is not None:
            min_tree.add_edge(V_graph[c].num, V_graph[c].predecessor.num)

    # Desenhando o Grafo
    draw_graph(min_tree)
