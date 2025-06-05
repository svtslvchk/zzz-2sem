// уничтожение линейного списка
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Item Item;
typedef struct Iterator Iterator;

struct Item {
    Item *prev;
    Item *next;
    int value;
};

struct Iterator {
    Item *current;
};

void init(Iterator *it, Item *head) {
    it->current = head;
}

bool next(Iterator *it) {
    if (it->current == NULL) {
        return false;
    }

    it->current = it->current->next;
    return true;
}

int getData(Iterator *it) {
    return it->current->value;
}

void destroy(Iterator *it) {
    while (it->current != NULL) {
        Item *pi = it->current;
        next(it);
        free(pi);
    }

    free(it);
}