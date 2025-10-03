// линейные списки на динамических структурах

typedef struct {
    T data;
    Item *next;
    Item *prev;
} Item;

typedef struct {
    Item *node;
} Iterator;

bool equal(Iterator *a, Iterator *b) {
    return a->node == b->node;
}

bool notEqual(Iterator *a, Iterator *b) {
    return !equal(a, b);
}

Iterator *next(Iterator *i) {
    i->node = i->node->next;
    return i;
}

Iterator *prev(Iterator *i) {
    i->node = i->node->prev;
    return i;
}

T fetch(Iterator *i) {
    return i->node->data;
}

void store(Iterator *i, T t) {
    i->node->data = t;
}

typedef struct {
    Item *head;
    int size;
} List;

void create(List *l) {
    l->head = malloc(sizeof(Item));
    l->head->next = l->head->prev = l->head;
    l->size = 0;
}

Iterator first(List *l) {
    Iterator res = { l->head->next };
    return res;
}

Iterator last(List *l) {
    Iterator res = { l->head };
    return res;
}

bool empty(List *l) {
    Iterator fst = first(l);
    Iterator lst = last(l);

    return equal(&fst, &lst);
}

int size(List *l) {
    return l->size;
}

Iterator insert(List *l, Iterator *i, T t) {
    Iterator res = { malloc(sizeof(Item)) };
    if (!res.node) {
        return last(l);
    }

    res.node->data = t;
    res.node->next = i->node;
    res.node->prev = i->node->prev;
    res.node->prev->next = res.node;
    i->node->prev = res.node;
    l->size++;

    return res;
}

Iterator delete(List *l, Iterator *i) {
    Iterator res = last(l);
    if (equal(i, &res)) {
        return res;
    }

    res.node = i->node->next;

    res.node->prev = i->node->prev;
    i->node->prev->next = res.node;

    l->size--;

    free(i->node);
    i->node = 0;

    return res;
}

void destroy(List *l) {
    Item *i = l->head->next;

    while (i != l->head) {
        Item *pi = i;
        i = i->next;
        free(pi);
    }

    free(l->head);
    l->head = 0;
    l->size = 0;
}