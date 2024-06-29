#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
    int capacidad;
    printf("Ingrese la capacidad del vector: ");
    scanf("%d", &capacidad);

    int *vector = (int *)malloc(capacidad * sizeof(int));
    if (vector == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    int tamano = 0;
    int valor;
    char continuar;

    do {
        printf("Ingrese un valor: ");
        scanf("%d", &valor);
        insertarValor(vector, valor, &tamano);
        desplegarVector(vector, tamano);

        if (vectorLleno(tamano, capacidad)) {
            printf("El vector esta lleno.\n");
            break;
        }

        printf("Desea ingresar otro numero? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    free(vector);
    
    printf("\nFin del programa\n");
    return 0;
}
