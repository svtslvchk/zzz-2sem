// реализация дэка
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Item Item;
typedef struct Deque Deque;

struct Item {
    int value;
    Item *next;
    Item *prev;
};

struct Deque {
    int size;
    Item *first;
    Item *last;
};

Deque *initDeque() {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->first = NULL;
    d->last = NULL;
    d->size = 0;
    return d;
}

bool isEmpty(Deque *d) {
    return d->size == 0;
}

int size(Deque *d) {
    return d->size;
}

void pushFront(Deque *d, int value) {
    Item *i = (Item *)malloc(sizeof(Item));
    i->value = value;
    i->prev = NULL;
    i->next = d->first;
    if (isEmpty(d)) {
        d->first = d->last = i;
    } else {
        d->first->prev = i;
        d->first = i;
    }

    d->size++;
}

void pushBack(Deque *d, int value) {
    Item *i = (Item *)malloc(sizeof(Item));
    i->value = value;
    i->next = NULL;
    i->prev = d->last;
    if (isEmpty(d)) {
        d->first = d->last = i;
    } else {
        d->last->next = i;
        d->last = i;
    }
    
    d->size++;
}

void popFront(Deque *d) {
    if (isEmpty(d)) {
        return;
    }

    Item *pi = d->first;
    if (d->first == d->last) {
        d->first = d->last = NULL;
    } else {
        d->first = d->first->next;
        d->first->prev = NULL;
    }

    free(pi);
    d->size--;
}

void popBack(Deque *d) {
    if (isEmpty(d)) {
        return;
    }

    Item *pi = d->last;

    if (d->first == d->last) {
        d->first = d->last = NULL;
    } else {
        d->last = d->last->prev;
        d->last->next = NULL;
    }

    free(pi);
    d->size--;
}

Item *front(Deque *d) {
    if (isEmpty(d)) {
        return NULL;
    }

    return d->first;
}

int back(Deque *d) {
    if (isEmpty(d)) {
        return -1;
    }

    return d->last->value;
}

void destroy(Deque *d) {
    while (!isEmpty(d)) {
        popBack(d);
    }

    free(d);
}