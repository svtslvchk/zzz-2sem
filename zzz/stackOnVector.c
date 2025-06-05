// реализация стэка на векторе

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct Vector Vector;
typedef struct Stack Stack;

struct Vector {
    int size;
    T data;
};

void vectorCreate(Vector *v, int s) {
    v->size = s;
    v->data = malloc(sizeof(T) * v->size);
}

bool isEmptyVector(Vector *v) {
    return v->size == 0;
}

void saveVector(Vector *v, T t, int i) {
    if (i >= 0 && i < v->size) {
        v->data[i] = t;
        v->size++;
    }
}

T loadVector(Vector *v, int i) {
    if (i >= 0 && i < v->size) {
        return v->data[i];
    }
}

void vectorDestroy(Vector *v) {
    v->size = 0;
    free(v->data);
}

struct Stack {
    int size;
    Vector data;
    int capacity;
};

void createStack(Stack *s) {
    s->size = 0;
    s->capacity = MAX_SIZE;
    vectorCreate(&s->data, s->capacity);
}

bool stackIsEmpty(Stack *s) {
    return s->size == 0;
}

void push(Stack *s, T t) {
    if (s->size >= s->capacity) {
        s->capacity *= 2;
        vectorCreate(&s->data, s->capacity);
    }

    saveVector(&s->data, t, s->size);
    s->size++;
}

void pop(Stack *s) {
    if (stackIsEmpty(s)) {
        return;
    }

    s->size--;
}

T top(Stack *s) {
    if (!stackIsEmpty(s)) {
        return loadVector(&s->data, s->size);
    }
}

void stackDestroy(Stack *s) {
    vectorDestroy(&s->data);
}







