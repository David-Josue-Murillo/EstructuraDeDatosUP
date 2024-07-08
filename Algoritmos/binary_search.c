#include <stdio.h>

// Función de búsqueda binaria
int binarySearch(int lista[], int derecha, int izquierda, int valor) {
    while (derecha <= izquierda) {
        int medio = derecha + (izquierda - derecha) / 2;

        // Verificar si x está presente en el medio
        if (lista[medio] == valor) {
            return medio;
        }

        // Si x es mayor, ignorar la mitad izquierda
        if (lista[medio] < valor) {
            derecha = medio + 1;
        } else { // Si x es menor, ignorar la mitad derecha
            izquierda = medio - 1;
        }
    }

    // Si el elemento no está presente en el array
    return -1;
}

// Función para imprimir el resultado
void printResult(int result, int *arr) {
    if (result == -1) {
        printf("Elemento no presente en el array.\n");
    } else {
        printf("Elemento encontrado en el índice %d - valor %d.\n", result, arr[result]);
    }
}

// Programa principal
int main() {
    int arr[] = {1, 2, 3, 7, 11, 14, 15, 18, 21, 27, 32, 43, 45};
    int cantidad_elementos = sizeof(arr) / sizeof(arr[0]);
    int valor_buscado = 43;

    int result = binarySearch(arr, 0, cantidad_elementos - 1, valor_buscado);
    printResult(result, arr);

    return 0;
}
