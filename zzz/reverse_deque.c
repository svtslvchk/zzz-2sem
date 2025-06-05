#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct Deque Deque;

struct Node {
    int value;
    Node *next;
    Node *prev;
};

struct Deque {
    int size;
    Node *first;
    Node *last;
};

Deque *init() {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->first = NULL;
    d->last = NULL;
    d->size = 0;
    return d;
}

bool isEmpty(Deque *d) {
    return d->size == 0;
}

void pushFront(Deque *d, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = d->first;
    newNode->prev = NULL;
    newNode->value = value;
    d->first = newNode;
    d->size++;
}

Node *popFront(Deque *d) {
    if (isEmpty(d)) {
        return NULL;
    }

    Node *current = d->first;
    d->first = current->next;
    if (d->first == NULL) {
        d->last = NULL;
    } else {
        d->first->prev = NULL;
    }

    current->next = NULL;
    d->size--;
    return current;
}

void printDeque(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque is empty\n");
        return;
    }

    Node *current = d->first;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

Deque *reverse(Deque *d) {
    Deque *r = init();
    while (!isEmpty(d)) {
        
        pushFront(r, popFront(d)->value);
        
    }
    
    return r;
}

int main() {
    Deque *d = init();
    pushFront(d, 1);
    pushFront(d, 2);
    pushFront(d, 3);
    printDeque(d);
    Deque *r = reverse(d);
    printDeque(r);
}