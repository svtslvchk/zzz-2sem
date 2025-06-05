// физическое представление вектора

typedef struct Vector Vector;

struct Vector {
    T *data;
    int size;
};

void create(Vector *v, int s) {
    v->size = s;
    v->data = malloc(sizeof(T) * v->size);
}

bool isEmpty(Vector *v) {
    return v->size == 0;
}

int size(Vector *v) {
    return v->size;
}

void save(Vector *v, T t, int i) {
    if (i >= 0 && i < v->size) {
        v->data[i] = t;
        v->size++;
    }
}

T load(Vector *v, int i) {
    if (i >= 0 && i < v->size) {
        return v->data[i];
    }
}

void resize(Vector *v, int s) {
    v->size = s;
    v->data = realloc(v->data, sizeof(T) * v->size);
}

bool isEqual(Vector *a, Vector *b) {
    if (a->size != b->size) {
        return false;
    }

    for (int i = 0; i < a->size; i++) {
        if (a->data[i] != b->data[i]) {
            return false;
        }
    }

    return true;
}

void destroy(Vector *v) {
    v->size = 0;
    free(v->data);
}