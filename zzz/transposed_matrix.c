#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    FILE* f;
    int rows, cols;

    f = fopen("matrix.txt", "r");
    if (f == NULL) {
        printf("not found\n");
        return 1;
    }

    fscanf(f, "%d %d", &rows, &cols);
    int **matrix = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * cols);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(f, "%d", &matrix[i][j]);
        }
    }

    int **transponsed = (int **)malloc(sizeof(int *) * cols);
    for (int i = 0; i < cols; i++) {
        transponsed[i] = (int *)malloc(sizeof(int) * rows);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transponsed[j][i] = matrix[i][j];
        }
    }

    printf("original matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }

    printf("transposed matrix (%d x %d):\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transponsed[i][j]);
        }

        printf("\n");
    }
}