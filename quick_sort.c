#include <stdlib.h>

void Swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int Partition(int *arr, int start, int end) { // одна итерация сортировки
 
    // выбираем первый элемент как точку опоры
    int pivot = arr[start];
 
    // считаем сколько элементов меньше либо равно точки опоры
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Ставим точку опоры так, чтобы в массиве перед ней уместились бы все элементы меньше либо равны её
    int pivotIndex = start + count;
    Swap(&arr[pivotIndex], &arr[start]);
 
    // Все что больше точки опоры идет вправо, все что меньше - влево
    int i = start, j = end - 1;
 
    while (i < pivotIndex && j > pivotIndex) {
        if (arr[i] <= pivot) {
            i++;
        } else if (arr[j] > pivot) {
            j--;
        } else {
            Swap(&arr[i++], &arr[j--]);
        }
    }
 
    return pivotIndex;
}

void QuickSort(int *arr, int start, int end) { // рекурсивно вызываем эту сортировку для всех подразбиений
    if (start < end) {
        int pi = Partition(arr, start, end);

        QuickSort(arr, start, pi - 1);  // Before pi
        QuickSort(arr, pi + 1, end); // After pi
    }
}