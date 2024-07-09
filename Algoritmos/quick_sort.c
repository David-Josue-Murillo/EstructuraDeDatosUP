#include <stdio.h>

// Función para intercambiar dos elementos
void swap(int* elemento_a, int* elemento_b) {
    int auxiliar = *elemento_a;
    *elemento_a = *elemento_b;
    *elemento_b = auxiliar;
}

// Función de partición
int partition(int arr[], int menor, int mayor) {
    int pivot = arr[mayor];
    int i = (menor - 1);

    for (int j = menor; j <= mayor - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[mayor]);
    return (i + 1);
}

// Función QuickSort
void quickSort(int arr[], int menor, int mayor) {
    if (menor < mayor) {
        int pi = partition(arr, menor, mayor);
        quickSort(arr, menor, pi - 1);
        quickSort(arr, pi + 1, mayor);
    }
}

// Función para imprimir el array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Programa principal
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int cantidad_elementos = sizeof(arr) / sizeof(arr[0]);

    // Imprimir el array original
    printf("Array original: \n");
    printArray(arr, cantidad_elementos); // Obtener el array original

    // Ordenar el array
    quickSort(arr, 0, cantidad_elementos - 1);
    printf("Array ordenado: \n"); // Imprimir el array ordenado
    printArray(arr, cantidad_elementos); // Obtener el array ordenado
    
    return 0;
}
