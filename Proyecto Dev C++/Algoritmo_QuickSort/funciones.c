#include "funciones.h"

// Funci�n para intercambiar dos elementos
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Funci�n de partici�n
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
	int j;

    for (j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Funci�n QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Funci�n para imprimir el array
void printArray(int arr[], int size) {
    int i;
	for ( i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}
