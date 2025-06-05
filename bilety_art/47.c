// слияние двух отсортированных стэков
// O(n + m) - линейная, где n и m - количество элементов в стэках

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

Stack *initStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s) {
        return NULL;
    }

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

Stack *reverse(Stack *s) {
    Stack *r = initStack();
    Item *current = s->top;
    while (current) {
        push(r, current->value);
        current = current->prev;
    }

    return r;
}

Stack *copy(Stack *s) {
    Stack *temp = reverse(s);
    Stack *copyStack = reverse(temp);
    destroy(temp);
    return copyStack;
}

void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty!\n");
        return;
    }
    Stack *temp = reverse(s);
    while (!isEmpty(temp)) {
        printf("%d ", top(temp)->value);
        pop(temp);
    }

    printf("\n");
    destroy(temp);
}

Stack *merge(Stack *a, Stack *b) {
    Stack *s1 = reverse(a);
    Stack *s2 = reverse(b);
    Stack *r = initStack();

    while (!isEmpty(s1) && !isEmpty(s2)) {
        int t1 = top(s1)->value;
        int t2 = top(s2)->value;
        
        if (t1 < t2) {
            push(r, t1);
            pop(s1);
        } else {
            push(r, t2);
            pop(s2);
        }
    }

    while (!isEmpty(s1)) {
        push(r, top(s1)->value);
        pop(s1);
    }

    while (!isEmpty(s2)) {
        push(r, top(s2)->value);
        pop(s2);
    }

    return r;
}

int main() {
    Stack *s1 = initStack(s1);
    push(s1, 1);
    push(s1, 5);
    printStack(s1);
    Stack *s2 = initStack();
    push(s2, 2);
    push(s2, 3);
    push(s2, 4);

    printStack(s2);
    Stack *r = merge(s1, s2);
    printStack(r);
}