#include "funciones.h"
#include <stdio.h>

// Programa principal
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Array original: \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Array ordenado: \n");
    printArray(arr, n);
    return 0;
}
