typedef struct Item Item;
typedef struct Queue Queue;

struct Item {
    T *data;
    Item *next;
};

struct Queue {
    int size;
    Item *first;
    Item *last;
};

void create(Queue *q) {
    q->first = q->last = malloc(sizeof(Item));
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

int size(Queue *q) {
    return q->size;
}

bool push(Queue *q, T t) {
    if (!(q->last->next = malloc(sizeof(Item)))) {
        return false;
    }

    q->last->data = t;
    q->last = q->last->next;
    q->size++;
    return true;
}

bool pop(Queue *q) {
    if (isEmpty(q)) {
        return false;
    }

    Item *pi = q->first;
    q->first = q->first->next;
    q->size--;
    free(pi);
    return true;
}

T top(Queue *q) {
    if (q->size) {
        return q->first->data;
    }
}

void destroy(Queue *q) {
    while (!isEmpty(q)) {
        pop(q);
    }

    free(q->first);
    q->first = q->last = 0;
    q->size = 0;
}

void reverse(Queue *q) {
    if (!isEmpty(q)) {
        T t = top(q);
        pop(q);
        reverse(q);
        push(q, t);
    }
}