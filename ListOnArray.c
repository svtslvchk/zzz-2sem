// линейный список на массиве

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

const int len = 100;

typedef struct {
    Item *head;
    Item *top;
    int size;
    Item data[len + 1];
} List;

void create(List *l) {
    for (int i = 0; i < len; i++) {
        l->data[i].next = &(l->data[i + 1]);
    }

    l->data[len - 1].next = 0;
    l->head = &(l->data[len]);
    l->head->next = l->head->prev = l->head;
    l->top = &(l->data[0]);
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

Iterator *next(Iterator *i) {
    i->node = i->node->next;
    return i;
}

Iterator *prev(Iterator *i) {
    i->node = i->node->prev;
    return i;
}

Iterator insert(List *l, Iterator *i, T t) {
    Iterator res = { l->top };
    if (!res.node) {
        return last(l);
    }

    l->top = l->top->next;

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
    i->node->next = l->top;
    l->top = i->node;

    l->size--;
    i->node = 0;
    return res;
}

void destroy(List *l) {
    l->head = 0;
    l->top = 0;
    l->size = 0;
}