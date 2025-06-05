#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item Item;
typedef struct Stack Stack;

struct Item {
    int value;
    Item *prev;
};

struct Stack {
    int size;
    Item *top;
};

Stack* init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

bool isEmpty(Stack *s) {
    return s->size == 0;
}

void push(Stack *s, int value) {
    Item *i = (Item *)malloc(sizeof(Item));
    i->value = value;
    i->prev = s->top;
    s->top = i;
    s->size++;
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        return;
    }

    Item *pi = s->top;
    s->top = s->top->prev;
    s->size--;
    free(pi);
}

Item* top(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }

    return s->top;
}

void destroy(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }

    free(s);
}

void printStack(Stack *s) {
    Stack *temp = init();

    while (!isEmpty(s)) {
        push(temp, top(s)->value);
        pop(s);
    }

    while (!isEmpty(temp)) {
        int a = top(temp)->value;
        printf("%d ", a);
        push(s, a);
        pop(temp);
    }

    printf("\n");

    destroy(temp);
}

Stack* cat(Stack *s1, Stack *s2) {
    Stack *temp = init();
    Stack *res = init();

    while (!isEmpty(s1)) {
        push(temp, top(s1)->value);
        pop(s1);
    }

    while (!isEmpty(temp)) {
        push(res, top(temp)->value);
        pop(temp);
    }

    while (!isEmpty(s2)) {
        push(temp, top(s2)->value);
        pop(s2);
    }

    while (!isEmpty(temp)) {
        push(res, top(temp)->value);
        pop(temp);
    }

    destroy(temp);
    destroy(s1);
    destroy(s2);
    return res;
}

int main() {
    Stack *s1 = init();
    push(s1, 1);
    push(s1, 3);
    push(s1, 2);
    printStack(s1);

    Stack *s2 = init();
    push(s2, 4);
    push(s2, 91);
    printStack(s2);

    Stack *res = cat(s1, s2);
    printStack(res);
}
