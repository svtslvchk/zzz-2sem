typedef struct Queue Queue;

const int MAX_SIZE = 100;

struct Queue {
    int size;
    int first;
    T data[MAX_SIZE];
};

void create(Queue *q) {
    q->first = 0;
    q->size = 0;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

int size(Queue *q) {
    return q->size;
}

bool push(Queue *q, T t) {
    if (q->size >= MAX_SIZE) {
        return false;
    }

    q->data[(q->first + q->size++) % MAX_SIZE] = t;
    return true;
}

bool pop(Queue *q) {
    if (isEmpty(q)) {
        return false;
    }

    q->first++;
    q->first %= MAX_SIZE;
    q->size--;
    return true;
}

T top(Queue *q) {
    if (q->size) {
        return q->data[q->first];
    }
}

void destroy(Queue *q) {
    q->size = 0;
}