#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Структура для узла списка смежности
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Структура графа
typedef struct {
    Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int numVertices;
} Graph;

// Создание нового узла
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Создание графа
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

// Добавление ребра
void addEdge(Graph* graph, int src, int dest) {
    // Добавляем ребро из src в dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Для неориентированного графа добавляем обратное ребро
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Поиск в глубину (DFS)
void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = true;
    printf("Посещена вершина: %d\n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }

        temp = temp->next;
    }
}

// Поиск в ширину (BFS)
void BFS(Graph* graph, int startVertex) {
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;

    // Помечаем начальную вершину как посещенную и добавляем в очередь
    graph->visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Извлекаем вершину из очереди
        int currentVertex = queue[front++];
        printf("Посещена вершина: %d\n", currentVertex);

        // Получаем все смежные вершины
        Node* temp = graph->adjLists[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
    }
}

// Очистка памяти
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);
}

int main() {
    Graph* graph = createGraph(6);
    
    // Добавляем ребра
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("Поиск в глубину (DFS):\n");
    DFS(graph, 0);  // Начинаем с вершины 0
    
    // Сбрасываем посещенные вершины
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = false;
    }

    printf("\nПоиск в ширину (BFS):\n");
    BFS(graph, 0);  // Начинаем с вершины 0

    freeGraph(graph);
    return 0;
}