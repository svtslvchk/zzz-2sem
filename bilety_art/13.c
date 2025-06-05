// вычислить константное буллевское значение выражение в постфиксной записи O(n)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack Stack;
typedef struct Item Item;

struct Item {
    bool value;
    Item *prev;
};

struct Stack {
    int size;
    Item *top;
};

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s) {
    return s->size == 0;
}

void push(Stack *s, int value) {
    Item *i = (Item *)malloc(sizeof(Item));
    i->prev = s->top;
    i->value = value;
    s->top = i;
    s->size++;
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty!\n");
        return;
    }
    Item *pi = s->top;
    s->top = s->top->prev;
    s->size--;
    free(pi);
}

Item *top(Stack *s) {
    if (isEmpty(s)) {
        return NULL;
    }

    return s->top;
}

int main() {
    char a, b, c;
    Stack *s = initStack();

    while ((c = getchar()) != EOF) {
        if (c == '0' || c == '1') {
            push(s, c - '0');
        } else if (c == '|') {
            a = top(s)->value;
            pop(s);
            b = top(s)->value;
            pop(s);
            push(s, a || b);
        } else if (c == '&') {
            a = top(s)->value;
            pop(s);
            b = top(s)->value;
            pop(s);
            push(s, a && b);
        } else if(c == '\n') {
            printf("%d\n", s->top->value);
            pop(s);
        }
    }

    
}