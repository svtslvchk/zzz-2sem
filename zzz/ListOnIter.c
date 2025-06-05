// линейный список на итераторах
typedef struct Item Item;
typedef struct Iterator Iterator;

struct Item {
    int data;
    Item *next;
    Item *prev;
};

struct Iterator {
    Item *node;
};

bool Equal(Iterator *a, Iterator *b) {
    return a->node == b->node;
}

bool notEqual(Iterator *a, Iterator *b) {
    return !Equal(a, b);
}

Iterator *next(Iterator *i) {
    i->node = i->node->next;
    return i;
}

Iterator *prev(Iterator *i) {
    i->node = i->node->prev;
    return i;
}

int Fetch(Iterator *i) {
    return i->node->data;
}

void Store(Iterator *i, int t) {
    i->node->data = t;
}