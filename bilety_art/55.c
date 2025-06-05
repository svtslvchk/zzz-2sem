// очередь на стэках
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item Item;
typedef struct Stack Stack;
typedef struct Queue Queue;

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

struct Queue {
    Stack *head;
    Stack *tail;
};

Queue *queueInit() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q) {
        return NULL;
    }

    q->head = init();
    q->tail = init();
    return q;
}

int queueSize(Queue *q) {
    return q->head->size + q->tail->size;
}

bool isEmptyQueue(Queue *q) {
    return queueSize(q) == 0;
}

void pushQueue(Queue *q, int value) {
    if (isEmptyQueue(q)) {
        push(q->head, value);
    } else {
        push(q->tail, value);
    }
}

void vnezapnyDeb(Stack *s1, Stack *s2) {
    if (isEmpty(s2)) {
        while (!isEmpty(s1)) {
            push(s2, top(s1)->value);
            pop(s1);
        }
    }

}

void popQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        return;
    }

    vnezapnyDeb(q->tail, q->head);
    pop(q->head);
}

Item *topQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        return NULL;
    }

    vnezapnyDeb(q->tail, q->head);
    return top(q->head);
}

void destroyQueue(Queue *q) {
    destroy(q->head);
    destroy(q->tail);
}

void printQueue(Queue *q) {
    if (isEmptyQueue(q)) {
        printf("queue is empty!\n");
        return;
    }

    printStack(q->head);
    printStack(q->tail);
}

int main() {
    Queue *q = queueInit();
    pushQueue(q, 1);
    pushQueue(q, 3);
    printQueue(q);
    popQueue(q);
    printQueue(q);
    printf("%d\n", topQueue(q)->value);
}