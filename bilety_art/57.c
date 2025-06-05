// пересечение двух стэков
// временная O(n * m)
// пространственная O(n + m)
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

Stack *init() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s) {
        return NULL;
    }
    s->size = 0;
    s->top = NULL;
    return s;
}

bool isEmpty(Stack *s) {
    return s->size == 0;
}

void push(Stack *s, int value) {
    Item *i = (Item *)malloc(sizeof(Item));
    if (!i) {
        return;
    }
    i->value = value;
    i->prev = s->top;
    s->top = i;
    s->size++;
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        return;
    }

    Item *i = s->top;
    s->top = s->top->prev;
    s->size--;
    free(i);
}

Item *top(Stack *s) {
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
    if (isEmpty(s)) {
        printf("stack is empty!\n");
        return;
    }

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

Stack *copy(Stack *s) {
    Stack *temp = init();
    Stack *res = init();
    Item *current = s->top;
    while (current) {
        push(temp, current->value);
        current = current->prev;
    }

    while (!isEmpty(temp)) {
        push(res, top(temp)->value);
        pop(temp);
    }

    destroy(temp);
    return res;
}

Stack *intersection (Stack *a, Stack *b) {
    if (isEmpty(a) || isEmpty(b)) {
        return NULL;
    }

    Stack *s1 = copy(a);
    Stack *res = init();
    while (!isEmpty(s1)) {
        int pivot = s1->top->value;
        Stack *s2 = copy(b);
        while (!isEmpty(s2)) {
            if (top(s2)->value == pivot) {
                push(res, pivot);
                destroy(s2);
                break;
            }

            pop(s2);
        }

        destroy(s2);
        pop(s1);
    }

    destroy(s1);

    return res;
}

int main() {
    Stack *s1 = init();
    push(s1, 1);
    push(s1, 3);
    push(s1, 6);

    Stack *s2 = init();
    push(s2, 3);
    push(s2, 4);
    push(s2, 1);

    printStack(s1);
    printStack(s2);

    Stack *res = intersection(s1, s2);

    printStack(res);
    
}