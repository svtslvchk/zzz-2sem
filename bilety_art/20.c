// удаление из дэка
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Deque Deque;
typedef struct Node Node;

struct Node {
    int value;
    Node *prev;
    Node *next;
};

struct Deque {
    Node *first;
    Node *last;
    int size;
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
    newNode->value = value;
    newNode->next = d->first;
    newNode->prev = NULL;
    if (d->first) {
        d->first->prev = newNode;
        d->first = newNode;
    } else {
        d->first = newNode;
        d->last = newNode;
    }

    d->size++;
}

void pushBack(Deque *d, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = d->last;
    if (d->last) {
        d->last->next = newNode;
        d->last = newNode;
    } else {
        d->first = newNode;
        d->last = newNode;
    }

    d->size++;
}

void printDeque(Deque *d) {
    if (isEmpty(d)) {
        printf("deque is empty!\n");
    }

    Node *current = d->first;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void popFront(Deque *d) {
    if (isEmpty(d)) {
        return;
    }

    if (d->first == d->last) {
        d->first = d->last = NULL;
        d->size = 0;
    } else {
        d->first = d->first->next;
        d->first->prev = NULL;
        d->size--;
    }
}

void popBack(Deque *d) {
    if (isEmpty(d)) {
        return;
    }

    if (d->first == d->last) {
        d->first = d->last = NULL;
        d->size = 0;
    } else {
        d->last = d->last->prev;
        d->last->next = NULL;
        d->size--;
    }
}

int main() {
    Deque *d = init();
    pushBack(d, 1);
    pushBack(d, 3);
    popFront(d);
    popBack(d);
    printDeque(d);
}