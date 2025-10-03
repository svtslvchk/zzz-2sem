// дэк по методичке

typedef struct {
    int *data;
    int size;
} Vector;

typedef struct {
    int data;
    Item *prev;
    Item *next;
} Item;

typedef struct {
    Item *left;
    Item *right;
    int size;
} Deque;

Deque *create(Vector *v);
bool isEmpty(Deque *d);
bool pushLeft(Deque *d, int t);
bool pushRight(Deque *d, int t);
bool popLeft(Deque *d);
bool popRight(Deque *d);
int topLeft(Deque *d);
int topRight(Deque *d);
bool deleteDeque(Deque *d);

Deque *create(Vector *v) {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    d->left = 0;
    d->right = 0;
    d->size = 0;

    for (int i = 0; i < v->size; i++) {
        pushLeft(d, v->data[i]);
    }

    return d;
}

bool isEmpty(Deque *d) {
    return d->size == 0;
}

bool pushLeft(Deque *d, int t) {
    Item *i = 0;

    if (d->left) {
        i = d->left;
        d->left = d->left->prev;
    }

    d->left = (Item *)malloc(sizeof(Item));
    d->left->data = t;
    d->left->next = i;
    d->left->prev = 0;

    if (d->left->next) {
        i->prev = d->left;
    }

    if (!i) {
        d->right = d->left;
    }

    d->size++;
    return true;
}

bool pushRight(Deque *d, int t) {
    Item *i = 0;
    if (d->right) {
        i = d->right;
        d->right = d->right->next;
    }

    d->right = (Item *)malloc(sizeof(Item));
    d->right->data = t;
    d->right->next = 0;
    d->right->prev = i;

    if (d->right->prev) {
        i->next = d->right;
    }

    if (!i) {
        d->left = d->right;
    }

    d->size++;

    return true;
}

bool popLeft(Deque *d) {
    if (isEmpty(d)) {
        return false;
    }
    Item *i = d->left->next;
    free(d->left);
    d->size--;
    d->left = i;

    if (!d->size) {
        d->right = d->left;
        return true; 
    }

    d->left->prev = 0;

    return true;
}

bool popRight(Deque *d) {
    if (isEmpty(d)) {
        return false;
    }

    Item *i = d->right->prev;
    free(d->right);
    d->size--;
    d->right = i;

    if (!d->size) {
        d->left = d->right;
        return true;
    }

    d->right->next = 0;

    return true;
}

int topLeft(Deque *d) {
    if (!isEmpty(d)) {
        return d->left->data;
    }
}

int topRight(Deque *d) {
    if (!isEmpty(d)) {
        return d->right->data;
    }
}

bool deleteDeque(Deque *d) {
    if (isEmpty(q)) {
        return false;
    }

    Item *i = d->left->next;
    free(d->left);
    d->size--;

    if (!i) {
        d->left = d->right = i;
        return true;
    }

    d->left = i;
    d->left->prev = 0;

    return deleteDeque(d);
}