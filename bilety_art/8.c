// транспонирование матрицы с помощью очереди O(n*m), n - строки, m - столбцы
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Item Item;
typedef struct Queue Queue;

struct Item {
    int value;
    Item *next;
};

struct Queue {
    int size;
    Item *first;
    Item *last;
};

Queue *init() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->size = 0;
    q->first = q->last = NULL;
    return q;
}

bool isEmpty(Queue *q) {
    return q->size == 0;
}

void push(Queue *q, int value) {
    Item *i = (Item *)malloc(sizeof(Item));
    i->value = value;
    i->next = NULL;
    if (isEmpty(q)) {
        q->first = q->last = i;
    } else {
        q->last->next = i;
        q->last = i;
    }

    q->size++;
}

int pop(Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }

    Item *pi = q->first;
    int value = pi->value;
    q->first = q->first->next;
    q->size--;
    free(pi);
    return value;
}

void destroy(Queue *q) {
    while (!isEmpty(q)) {
        pop(q);
    }

    free(q);
}

void transposedMatrix(int **arr, int rows, int cols) {
    Queue *q = init();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            push(q, arr[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[j][i] = pop(q);
        }
    }

    destroy(q);
}

void printMatrix(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Enter the number of rows:\n");
    scanf("%d", &rows);
    printf("Enter the number of columns:\n");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }

    printf("Enter the elements of matrix\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("original matrix:\n");
    printMatrix(matrix, rows, cols);

    if (rows == cols) {
        transposedMatrix(matrix, rows, cols);
        printf("transpose matrix:\n");
        printMatrix(matrix, rows, cols);
    } else {
        int **transposed = (int **)malloc(sizeof(int *) * cols);
        for (int i = 0; i < cols; i++) {
            transposed[i] = (int *)malloc(sizeof(int) * rows);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }

        printf("transpose matrix:\n");
        printMatrix(transposed, cols, rows);
    }
}