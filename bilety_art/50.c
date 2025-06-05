// палиндром на дэке O(n)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item Item;
typedef struct Deque Deque;

struct Item {
    int value;
    Item *prev;
    Item *next;
};

struct Deque {
    int size;
    Item *first;
    Item *last;
};

Deque *init() {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    if (!d) {
        return NULL;
    }
    d->first = NULL;
    d->last = NULL;
    d->size = 0;
    return d;
}

bool isEmpty(Deque *d) {
    return d->size == 0;
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
    d->first = d->first->next;
    d->first->prev = NULL;
    d->size--;
    free(pi);
}

void popBack(Deque *d) {
    if (isEmpty(d)) {
        return;
    }

    Item *pi = d->last;
    d->last = d->last->prev;
    d->last->next = NULL;
    d->size--;
    free(pi);
}

Item *getFront(Deque *d) {
    if (isEmpty(d)) {
        return NULL;
    }

    return d->first;
}

Item *getBack(Deque *d) {
    if (isEmpty(d)) {
        return NULL;
    }

    return d->last;
}

void printDeque(Deque *d) {
    if (isEmpty(d)) {
        printf("deque is empty!\n");
        return;
    }

    Item *current = d->first;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void destroy(Deque *d) {
    while (!isEmpty(d)) {
        popBack(d);
    }

    free(d);
}

bool palindrom(Deque *d) {
    if (isEmpty(d) || d->size == 1) {
        return true;
    }

    while (d->size > 1) {
        int a = getFront(d)->value;
        int b = getBack(d)->value;
        if (a != b) {
            return false;
        }

        popFront(d);
        popBack(d);
    }

    return true;
}

int main() {
    Deque *d = init();
    pushBack(d, 1);
    pushBack(d, 1);
    
    
    printDeque(d);
    if (palindrom(d)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}