#include <stdio.h>

void insertionSort(int a[], int n) {
    int i, j, k, x;
    for (i = 1; i < n; i++) {
        x = a[i];
        j = 0;
        while (a[j] <= x && j < i) {
            j++;
        }

        for (k = i; k > j; k--) {
            a[k] = a[k - 1];
        }

        a[j] = x;
    }
}

void selectionSort(int a[], int n) {
    int i, j, k, x;
    for (i = 0; i < n; i++) {
        x = a[i];
        k = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[k]) {
                k = j;
            }
        }

        a[i] = a[k];
        a[k] = x;
    }
}

void shellSort(int a[], int n) {
    int i, j, gap, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = a[i];
            for (j = i; a[j - gap] > temp && j >= gap; j -= gap) {
                a[j] = a[j - gap];
            }

            a[j] = temp;
        }
    }
}

void create(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    create(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);
}