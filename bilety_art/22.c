// скалярное произведение ДОДЕЛАТЬ!!!
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Item Item;
typedef struct Vector Vector;

struct Item {
    int value;
    int index;
};

struct Vector {
    int size;
    int nonzeros;
    Item *data;
};

Vector *init(int s, int nonzeros) {
    Vector *v = (Vector *)malloc(sizeof(Vector));\
    v->size = s;
    v->nonzeros = nonzeros;
    v->data = (Item *)malloc(sizeof(Item) * nonzeros);
}

bool isEmpty(Vector *v) {
    v->size == 0;
}

bool isZeroVector(Vector *v) {
    return v->nonzeros == 0;
}

void push(Vector *v, int value, int i, int pos) {
    if (i >= 0 && i < v->nonzeros && pos >= 0 && pos < v->size) {
        v->data[i].index = pos;
        v->data[i].value = value;
        v->size++;
    }
}

