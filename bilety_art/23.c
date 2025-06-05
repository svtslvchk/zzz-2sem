// сортировка очереди O(nlogn)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;

struct Node {
    int value;
    Node *prev;
    Node *next;
};

struct Queue {
    Node *head;
    Node *tail;
    int size;
};

Queue *init() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

void push(Queue *q, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = q->tail;
    if (q->tail) {
        q->tail->next = newNode;
        q->tail = newNode;
    } else {
        q->head = q->tail = newNode;
    }

    q->size++;
}

void pop(Queue *q) {
    if (isEmpty(q)) {
        return;
    }

    if (q->head == q->tail) {
        q->head = q->tail = NULL;
    } else {
        q->head = q->head->next;
        q->head->prev = NULL;
    }

    q->size--;
}

int top(Queue *q) {
    if (!q) {
        return -1;
    }

    return q->head->value;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty!\n");
        return;
    }

    Node *current = q->head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void quickSort(Queue *q) {
    if (isEmpty(q) || q->size == 1) {
        return;
    }

    Queue *q1 = init();
    Queue *q0 = init();
    Queue *q2 = init();

    int pivot = top(q);
    while (!isEmpty(q)) {
        int current = top(q);
        pop(q);
        if (current < pivot) {
            push(q1, current);
        } else if(current == pivot) {
            push(q0, current);
        } else {
            push(q2, current);
        }
    }

    quickSort(q1);
    quickSort(q2);

    while (!isEmpty(q1)) {
        push(q, top(q1));
        pop(q1);
    }

    while (!isEmpty(q0)) {
        push(q, top(q0));
        pop(q0);
    }

    while (!isEmpty(q2)) {
        push(q, top(q2));
        pop(q2);
    }
}

int main() {
    Queue *q = init();
    printQueue(q);
    push(q, 1);
    push(q, 5);
    push(q, 3);
    printf("original queue:\n");
    printQueue(q);
    quickSort(q);
    printQueue(q);
}