#include <stdlib.h>

void Merge(int *arr, int start, int mid, int end) {
    int l1 = mid - start + 1;
    int l2 = end - mid;

    int *subArr1 = (int *)malloc(sizeof(int) * l1);
    if (subArr1 == NULL) {
        return;
    }

    int *subArr2 = (int *)malloc(sizeof(int) * l2);
    if (subArr2 == NULL) {
        free(subArr1);
        return;
    }

    for (int i = 0; i < l1; i++)
        subArr1[i] = arr[start + i];
    for (int j = 0; j < l2; j++)
        subArr2[j] = arr[mid + 1 + j];

    int count1 = 0, count2 = 0, count = 0;
    while (count1 < l1 && count2 < l2) {
        if (subArr1[count1] < subArr2[count2]) {
            arr[count++] = subArr1[count1++];
        } else {
            arr[count++] = subArr2[count2++];
        }
    }

    while (count1 < l1) {
        arr[count++] = subArr1[count1++];
    }

    while (count2 < l2) {
        arr[count++] = subArr2[count2++];
    }

    

    free(subArr1);
    free(subArr2);
}

void MergeSort(int* arr, int start, int end) {
    if (start >= end)
        return;
 
    int mid = start + (end - start) / 2;
    MergeSort(arr, start, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, start, mid, end);
}