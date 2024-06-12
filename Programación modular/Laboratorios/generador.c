/* 

1- Función que genere n valores aleatorios 
2- Función que determine la cantidad de números pares que contiene el conjunto de valores dados.

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaración de variables
    int vector[10];
    int cantidadNumPares, cantidadNumImpares;
    int cantidadElementos = sizeof(vector) / sizeof(vector[0]);

    // Prototipos de las funciones
    void generarValoresAleatorios(int *vector, int);
    int contarNumerosPares(int *vector, int );
    int contarNumerosImpares(int *vector, int );    
    void desplegarVector(int *vector, int );

    // Llamada a la función
    generarValoresAleatorios(vector, cantidadElementos);
    cantidadNumPares = contarNumerosPares(vector, cantidadElementos);
    cantidadNumImpares = contarNumerosImpares(vector, cantidadElementos);

    printf("El conjunto de valores generado tiene %d números pares y %d números impares\n", cantidadNumPares, cantidadNumImpares);

    desplegarVector(vector, cantidadElementos);

    return 0;
}

void generarValoresAleatorios(int *vector, int cantidadElementos){
    int i;
    for(i = 0; i < cantidadElementos; i++){
        vector[i] = rand() & 30;
    }
}

int contarNumerosPares(int *vector, int cantidadElementos) {
    int contador = 0;
    for (int i = 0; i < cantidadElementos; i++) {
        if (vector[i] % 2 == 0) {
            contador++;
        }
    }
    return contador;
}

int contarNumerosImpares(int *vector, int cantidadElementos) {
    int  i, contador = 0;
    for(i = 0; i < cantidadElementos; i++) {
        if(vector[i] % 2 != 0){
            contador++;
        }
    }

    return contador;
}

void desplegarVector(int *vector, int cantidadElementos) {
    for (int i = 0; i < cantidadElementos; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

