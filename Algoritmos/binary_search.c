#include <stdio.h>

// Función de búsqueda binaria
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Verificar si x está presente en el medio
        if (arr[m] == x) {
            return m;
        }

        // Si x es mayor, ignorar la mitad izquierda
        if (arr[m] < x) {
            l = m + 1;
        } else { // Si x es menor, ignorar la mitad derecha
            r = m - 1;
        }
    }

    // Si el elemento no está presente en el array
    return -1;
}

// Función para imprimir el resultado
void printResult(int result) {
    if (result == -1) {
        printf("Elemento no presente en el array.\n");
    } else {
        printf("Elemento encontrado en el índice %d.\n", result);
    }
}

// Programa principal
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;

    int result = binarySearch(arr, 0, n - 1, x);
    printResult(result);

    return 0;
}
