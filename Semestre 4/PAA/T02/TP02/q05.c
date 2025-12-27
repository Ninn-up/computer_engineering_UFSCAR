//Aluna: Nicole Ramos
//Curso: Engenharia da Computação

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Estrutura para representar um nó no minheap
typedef struct MinHeapNode {
    int v;
    int dist;
} MinHeapNode;

// Estrutura para representar um minheap
typedef struct MinHeap {
    int size;
    int capacity;
    int *pos;
    MinHeapNode **array;
} MinHeap;

// Função para criar um novo nó do minheap
MinHeapNode* createMinHeapNode(int v, int dist) {
    MinHeapNode* minHeapNode = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}

// Função para criar um minheap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->pos = (int *) malloc(capacity * sizeof(int));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// Função para trocar dois nós do minheap
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Função para fazer o heapify
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];

        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;

        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

        minHeapify(minHeap, smallest);
    }
}

// Função para verificar se o minheap está vazio
int isEmpty(MinHeap* minHeap) {
    return minHeap->size == 0;
}

// Função para extrair o nó de menor distância do minheap
MinHeapNode* extractMin(MinHeap* minHeap) {
    if (isEmpty(minHeap))
        return NULL;

    MinHeapNode* root = minHeap->array[0];

    MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;

    minHeap->pos[root->v] = minHeap->size - 1;
    minHeap->pos[lastNode->v] = 0;

    --minHeap->size;
    minHeapify(minHeap, 0);

    return root;
}

// Função para diminuir a distância de um nó
void decreaseKey(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;

    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Função para verificar se um vértice está no minheap
int isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

// Função para imprimir as distâncias calculadas
void printDist(int dist[], int n) {
        printf("%d\n", dist[n-1]);
}

// Estrutura para representar um nó na lista de adjacência
typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

// Estrutura para representar a lista de adjacência
typedef struct AdjList {
    AdjListNode *head;
} AdjList;

// Estrutura para representar um grafo
typedef struct Graph {
    int V;
    AdjList* array;
} Graph;

// Função para criar um novo nó na lista de adjacência
AdjListNode* newAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Função para criar um grafo
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;

    graph->array = (AdjList*) malloc(V * sizeof(AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Função para adicionar uma aresta ao grafo
void addEdge(Graph* graph, int src, int dest, int weight) {
    AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Implementação do algoritmo de Dijkstra
void dijkstra(Graph* graph, int src) {
    int V = graph->V;
    int dist[V];

    MinHeap* minHeap = createMinHeap(V);

    for (int v = 0; v < V; ++v) {
        dist[v] = INF;
        minHeap->array[v] = createMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }

    minHeap->array[src] = createMinHeapNode(src, dist[src]);
    minHeap->pos[src] = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);

    minHeap->size = V;

    while (!isEmpty(minHeap)) {
        MinHeapNode* minHeapNode = extractMin(minHeap);
        int u = minHeapNode->v;

        AdjListNode* pCrawl = graph->array[u].head;
        while (pCrawl != NULL) {
            int v = pCrawl->dest;

            if (isInMinHeap(minHeap, v) && dist[u] != INF &&
                pCrawl->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }

    printDist(dist, V);
}

int main(void) {
    int V, E;
    
    //printf("Digite o número de vértices e arestas: ");
    scanf("%d %d", &V, &E);

    Graph* graph = createGraph(V);

    //printf("Digite as arestas no formato v1 v2 peso (direcionado):\n");
    for (int i = 0; i < E; i++) {
        int v1, v2, peso;
        scanf("%d %d %d", &v1, &v2, &peso);
        addEdge(graph, v1, v2, peso);
    }

    int origem = 0;

    dijkstra(graph, origem);

    return 0;
}
