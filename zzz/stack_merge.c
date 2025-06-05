#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node {
    int value;
    Node *next;
};

struct Stack {
    int size;
    Node *top;
};

Stack *init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s) {
    return s->size == 0;
}

void push(Stack *s, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

Node *pop(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }

    Node *current = s->top;
    s->top = current->next;
    s->size--;
    current->next = NULL;
    return current;
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty\n");
        return;
    }

    Node *current = s->top;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

void destroy(Stack *s) {
    if (isEmpty(s)) {
        return;
    }

    Node *current = s->top;
    while(current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    free(s);
}

Stack *reverse(Stack *s) {
    Stack *r = init();
    while (!isEmpty(s)) {
        push(r, pop(s)->value);
    }

    destroy(s);
    return r;
}

Stack *merge(Stack *left, Stack *right) {
    Stack *res = init();
    while (!isEmpty(left) && !isEmpty(right)) {
        if (left->top->value <= right->top->value) {
            push(res, pop(left)->value);
        } else {
            push(res, pop(right)->value);
        }
    }

    while (!isEmpty(left)) {
        push(res, pop(left)->value);
    }

    while (!isEmpty(right)) {
        push(res, pop(right)->value);
    }

    return reverse(res);
}

Stack *mergeSort(Stack *s) {
    if (s->size <= 1) {
        return s;
    }
    Stack *left = init();
    Stack *right = init();
    int m = s->size / 2;

    for (int i = 0; i < m; ++i) {
        push(left, pop(s)->value);
    }

    while (!isEmpty(s)) {
        push(right, pop(s)->value);
    }

    left = mergeSort(left);
    right = mergeSort(right);

    Stack *sorted = merge(left, right);
    destroy(left);
    destroy(right);

    return sorted;
}

int main() {
    Stack *s = init();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printStack(s);
    Stack *sort = mergeSort(s);
    printStack(sort);
    destroy(s);
    destroy(sort);
}