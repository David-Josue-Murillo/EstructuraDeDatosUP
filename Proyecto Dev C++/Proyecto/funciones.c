#include "funciones.h" 

int i;

void capturaElementos(int *vector, int *tamano, int capacidad) {
    printf("Ingrese el numero de elementos: ");
    scanf("%d", tamano);
    if (*tamano > capacidad) {
        printf("El numero de elementos excede la capacidad del vector.\n");
        *tamano = capacidad;
    }
    for ( i = 0; i < *tamano; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vector[i]);
    }
}

void desplegarVector(int *vector, int tamano) {
    printf("Vector: ");
    for ( i = 0; i < tamano; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

void correrElementos(int *vector, int posicion, int tamano) {
    for ( i = tamano; i > posicion; i--) {
        vector[i] = vector[i - 1];
    }
}

int determinarPosicion(int *vector, int valor, int tamano) {
    int pos = 0;
    while (pos < tamano && vector[pos] < valor) {
        pos++;
    }
    return pos;
}

void insertarValor(int *vector, int valor, int *tamano) {
    int pos = determinarPosicion(vector, valor, *tamano);
    correrElementos(vector, pos, *tamano);
    vector[pos] = valor;
    (*tamano)++;
}

int vectorLleno(int tamano, int capacidad) {
    return tamano >= capacidad;
}

