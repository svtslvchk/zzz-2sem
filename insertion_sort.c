#include <stdio.h>

int FindCurrentPlace(int *arr, int length, int val) {
    for (int i = 0; i <= length; i++) {
        if (arr[i] >= val) {
            return i;
        }
    }
}

void Insertion(int *arr, int oldIndex, int newIndex) {
    int buf = arr[newIndex];
    for (int i = oldIndex; i > newIndex; i--) {
        arr[i] = arr[i - 1];
    }

    arr[newIndex] = buf;
}

void InsertionSort(int *arr, int length) {
    for (int i = 1; i < length; i++) {
        if (arr[i] < arr[i - 1]) {
            Insertion(arr, i, FindCurrentPlace(arr, i, arr[i]));
        }
    }
}
