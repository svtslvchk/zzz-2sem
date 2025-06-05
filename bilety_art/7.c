// быстрая сортировка Хоара O(nlogn)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack Stack;

#define MAX_SIZE 100

struct Stack {
    int data[MAX_SIZE];
    int size;
};

void initStack(Stack *s) {
    s->size = 0;
}

bool isEmpty(Stack *s) {
    return s->size == 0;
}

bool push(Stack *s, int value) {
    if (s->size >= MAX_SIZE) {
        return false;
    }

    s->data[s->size++] = value;
    return true;
}

bool pop(Stack *s) {
    if (isEmpty(s)) {
        return false;
    }

    s->size--;
    return true;
}

int top(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }

    return s->data[s->size - 1];
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty!\n");
        return;
    }

    for (int i = 0; i < s->size; i++) {
        printf("%d ", s->data[i]);
    }

    printf("\n");
}

void destroy(Stack *s) {
    s->size = 0;
}

void partStack(Stack *s, Stack *l, Stack *r, int pivot) {
    while (!isEmpty(s)) {
        int current = top(s);
        if (current < pivot) {
            push(l, current);
        } else {
            push(r, current);
        }

        pop(s);
    }
}

void quickSort(Stack *s) {
    if (s->size == 1) {
        return;
    }
    if (isEmpty(s)) {
        return;
    }

    int pivot = top(s);
    pop(s);

    Stack l;
    Stack r;
    initStack(&l);
    initStack(&r);

    partStack(s, &l, &r, pivot);

    quickSort(&l);
    quickSort(&r);

    Stack temp;
    initStack(&temp);

    while (!isEmpty(&r)) {
        push(&temp, top(&r));
        pop(&r);
    }

    push(&temp, pivot);

    while (!isEmpty(&l)) {
        push(&temp, top(&l));
        pop(&l);
    }

    while (!isEmpty(&temp)) {
        push(s, top(&temp));
        pop(&temp);
    }

    destroy(&temp);
}

int main() {
    Stack s;
    initStack(&s);
    printStack(&s);
    push(&s, -1);
    push(&s, 3);
    push(&s, 2);
    printStack(&s);
    quickSort(&s);
    printStack(&s);
    destroy(&s);
}