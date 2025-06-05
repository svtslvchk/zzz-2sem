// конкатенация стэков (доделать)
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
    newNode->next= s->top;
    newNode->value = value;
    s->top = newNode;
    s->size++;
    
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        return;
    }

    s->top = s->top->next;
    s->size--;
}

int top(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }

    return s->top->value;
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty!\n");
        return;
    }

    
}