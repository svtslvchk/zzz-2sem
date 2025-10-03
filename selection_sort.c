#include <stdio.h>

void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int Selection(int *arr, int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i < end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}

void SelectionSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int minIndex = Selection(arr, i, len - 1);
        Swap(&arr[i], &arr[minIndex]);
    }
}