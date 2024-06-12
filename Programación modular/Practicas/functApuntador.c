#include <stdio.h>


// Definición de la función
int sumar(int a, int b) {
    return a + b;
}

int main() {
    // Declaración del puntero a la función
    int (*func_ptr)(int, int);

    // Asignación de la dirección de la función sumar al puntero
    func_ptr = sumar;

    // Llamada a la función a través del puntero
    int resultado = func_ptr(3, 4);

    // Imprimir el resultado
    printf("El resultado es: %d\n", resultado);

    return 0;
}
