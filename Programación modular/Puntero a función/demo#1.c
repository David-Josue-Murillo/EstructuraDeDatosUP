#include <stdio.h>

int main()
{
    /* Descripción del uso de apuntadores a funciones y diferencias con apuntadores a variables
       ... primeras ideas de https://beginnersbook.com/2014/01/c-function-pointers/
      Adecuado por Diego Santimateo G. 18/06/2021
   */
    int sum(int num1, int num2); // prototipo de la función
    int (*f2p)(int, int);        // f2p es un apuntador a una funcion que recibe 2 enteros y devuelve un entero
    f2p = &sum;                   // ahora fp2 aputa a la función sum que tiene 2 enteros y devuelve un entero

    int x[3] = {211, 10, 55},
    *ptr; // ptr es un apuntador a enteros

    // llamada a la función sum usando el apuntador f2p , hay dos formas ... (*f2p) <=> f2p
    int op1 = f2p(10, 13);
    // int op1 = (*f2p)(10, 23);

    ptr = x; // dirección del arreglo x, se guarda en ptr

    // se muestra que cuando se trata de variables son diferentes
    printf("\n(*ptr) => %d ... *ptr => %d ... ptr => %d ... x => %d\n", (*ptr), *ptr, ptr, x);
    /*
      Se muestra que cuando se trata de código las expresiones  (*f2p), f2p, sum, &sum
      corresponden a la dirección donde inicia el código de la función ... son iguales
    */
    printf("\n*f2p => %d ... f2p => %d ... sum => %d ... &sum => %d\n", (*f2p), f2p, sum, &sum);

    // llamada usual a la función sum para verificar valores
    int op2 = sum(10, 13);

    printf("\nresultado1: invocando con el apuntador a funcion f2p : %d", op1);
    printf("\nOutput2: Call using function name: %d", op2);

    return 0;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}
