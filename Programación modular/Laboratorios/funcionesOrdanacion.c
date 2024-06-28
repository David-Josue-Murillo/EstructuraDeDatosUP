#include <stdio.h>
#include <stdlib.h>

void capturaElementos(int *vector, int *tamaño, int capacidad);
void desplegarVector(int *vector, int tamaño);
void correrElementos(int *vector, int posición, int tamaño);
int determinarPosicion(int *vector, int valor, int tamaño);
void insertarValor(int *vector, int valor, int *tamaño);
int vectorLleno(int tamaño, int capacidad);

int main() {
    int capacidad;
    printf("Ingrese la capacidad del vector: ");
    scanf("%d", &capacidad);

    int *vector = (int *)malloc(capacidad * sizeof(int));
    if (vector == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    int tamaño = 0;
    int valor;
    char continuar;

    do {
        printf("Ingrese un valor: ");
        scanf("%d", &valor);
        insertarValor(vector, valor, &tamaño);
        desplegarVector(vector, tamaño);

        if (vectorLleno(tamaño, capacidad)) {
            printf("El vector está lleno.\n");
            break;
        }

        printf("¿Desea ingresar otro número? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    free(vector);
    return 0;
}

void capturaElementos(int *vector, int *tamaño, int capacidad) {
    printf("Ingrese el número de elementos: ");
    scanf("%d", tamaño);
    if (*tamaño > capacidad) {
        printf("El número de elementos excede la capacidad del vector.\n");
        *tamaño = capacidad;
    }
    for (int i = 0; i < *tamaño; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

void desplegarVector(int *vector, int tamaño) {
    printf("Vector: ");
    for (int i = 0; i < tamaño; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void correrElementos(int *vector, int posición, int tamaño) {
    for (int i = tamaño; i > posición; i--) {
        vector[i] = vector[i - 1];
    }
}

int determinarPosicion(int *vector, int valor, int tamaño) {
    int pos = 0;
    while (pos < tamaño && vector[pos] < valor) {
        pos++;
    }
    return pos;
}

void insertarValor(int *vector, int valor, int *tamaño) {
    int pos = determinarPosicion(vector, valor, *tamaño);
    correrElementos(vector, pos, *tamaño);
    vector[pos] = valor;
    (*tamaño)++;
}

int vectorLleno(int tamaño, int capacidad) {
    return tamaño >= capacidad;
}
