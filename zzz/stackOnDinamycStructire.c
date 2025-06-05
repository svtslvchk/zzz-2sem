// реализация стэка на динамических структурах

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item Item;
typedef struct Stack Stack;

struct Item {
    int data;
    Item *prev;
};

struct Stack {
    int size;
    Item *top;
};


void create(Stack *s) {
    s->size = 0;
    s->top = 0;
}

bool isEmpty(Stack *s) {
    return s->top == 0;
}

bool push(Stack *s, int t) {
    Item *i = malloc(sizeof(Item));
    if (!i) {
        return false;
    }

    i->data = t;
    i->prev = s->top;
    s->top = i;
    s->size++;
    free(i);
    return true;
}

bool pop(Stack *s) {
    if (isEmpty(s)) {
        return false;
    }

    Item *i = s->top;
    s->top = i->prev;
    s->size--;
    free(i);
    return true;
}

int top(Stack *s) {
    if (s->top) {
        return s->top->data;
    }
}

void destroy(Stack *s) {
    if (isEmpty(s)) {
        return;
    }

    while (!isEmpty(s)) {
        pop(s);
    }

    s->size = 0;
    s->top = 0;
}