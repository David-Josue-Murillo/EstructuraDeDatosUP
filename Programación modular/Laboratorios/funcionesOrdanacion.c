/*
En grupos de a lo sumo dos personas, elabore un programa que coloque elementos en un vector (numérico o de caracteres)
de manera que los elementos siempre estén ordenados. A medida que entra un valor debe ser colocado en la posición
correspondiente para mantener el orden de los elementos.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declaración de variables
    int listaDeNumeros[10], cantidadElementos, posicionVacia, nuevoValor, boolListaLlena = 1;
    int longListaDeNumeros = (sizeof(listaDeNumeros) / sizeof(listaDeNumeros[0]));
    char respuesta;

    // Prototipos de las funciones
    void capturarElementos(int *vector, int, int);
    void desplegarVector(int *vector, int);
    void correrElementos(int *vector, int);
    void insertarElemento(int *vector, int, int);
    int determinarPosicion(int *vector, int, int);
    int vectorLleno(int *vector, int);

    // Inicializar el vector
    while (boolListaLlena)
    {
        // Capturar la cantida de elementos que se desean ingresar
        printf("\nIngrese la cantidad de elementos: ");
        scanf(" %d", &cantidadElementos);

        if (cantidadElementos <= longListaDeNumeros)
        {
            // Llamada a la función
            capturarElementos(listaDeNumeros, longListaDeNumeros, cantidadElementos);
            boolListaLlena = 0;
        }
        else
        {
            printf("La cantidad de elementos no puede ser mayor a %d, vuelva a intentarlo\n", longListaDeNumeros);
        }
    }

    while (!boolListaLlena)
    {
        // Determinar si el vector está lleno
        boolListaLlena = vectorLleno(listaDeNumeros, longListaDeNumeros);

        // Si el vector no está lleno se ejecuta el bloque de código
        if (!boolListaLlena)
        {
            // Llamada a la función para desplegar el vector y correr los elementos
            desplegarVector(listaDeNumeros, longListaDeNumeros);
            correrElementos(listaDeNumeros, longListaDeNumeros);

            // Preguntar si se desea ingresar otro valor
            printf("\nDesea ingresar otro valor? (s/n): ");
            scanf(" %c", &respuesta);

            // Si la respuesta es afirmativa se captura el valor
            if (respuesta == 's' || respuesta == 'S')
            {
                printf("Ingrese el valor a insertar: ");
                scanf(" %d", &nuevoValor);

                // Determinar la posición en la que se debe colocar el siguiente valor
                posicionVacia = determinarPosicion(listaDeNumeros, nuevoValor, longListaDeNumeros);

                // Insertar el valor en la posición correspondiente
                insertarElemento(listaDeNumeros, posicionVacia, nuevoValor);
            }
            else
            {
                boolListaLlena = 1;
            }
        }
    }

    boolListaLlena = vectorLleno(listaDeNumeros, longListaDeNumeros);

    // Mensaje de vector lleno
    if (boolListaLlena)
    {
        printf("**************El vector está lleno**************\n");
    }

    desplegarVector(listaDeNumeros, longListaDeNumeros);
    printf("\n**************Fin del programa**************\n");
    return 0;
}

// Función para captura de los elementos del vector
void capturarElementos(int *vector, int longVector, int cantidadElementos)
{
    // Capturar y ordenar los elementos del vector
    for (int iterador = 0; iterador < cantidadElementos; iterador++)
    {
        printf("Ingrese el valor %d: ", iterador + 1);
        scanf(" %d", &vector[iterador]);
    }

    // Ordenar los elementos del vector
    for (int iterador = 0; iterador < cantidadElementos; iterador++)
    {
        for (int iterador2 = 0; iterador2 < cantidadElementos; iterador2++)
        {
            // Si el elemento actual es menor que el siguiente, se intercambian
            if (vector[iterador] < vector[iterador2])
            {
                int auxiliar = vector[iterador];
                vector[iterador] = vector[iterador2];
                vector[iterador2] = auxiliar;
            }
        }
    }

    // Llenar el resto del vector con ceros
    for (int iterador = cantidadElementos; iterador < longVector; iterador++)
    {
        vector[iterador] = 0;
    }
}

// Función para desplegar el vector
void desplegarVector(int *vector, int longVector)
{
    int iterador;

    printf("\nElementos del vector:\n");
    // Bucle que imprime los elementos del vector
    for (int iterador = 0; iterador < longVector; iterador++)
    {
        printf("posición %d: %d\n", iterador + 1, vector[iterador]);
    }
    printf("\n");
}

// Función que permite correr los elementos de un vector a la siguiente posición
void correrElementos(int *vector, int longVector)
{
    int iterador;
    int auxiliar;

    // Bucle que corre los elementos del vector
    for (iterador = longVector; iterador >= 0; iterador--)
    {
        auxiliar = vector[iterador - 1];
        vector[iterador] = vector[iterador - 1];
        vector[iterador - 1] = auxiliar;
    }
}

// Función que determina la posición del vector en la que debe colocarse el siguiente valor
int determinarPosicion(int *vector, int valor, int longVector)
{
    int posicion = 0; // Variable que almacena la posición en la que se debe colocar el valor

    // Bucle que busca la posición en la que se debe colocar el valor
    while (posicion < longVector && vector[posicion] < valor)
    {
        posicion++;
    }

    // Retornar la posición
    return posicion;
}

// Función que permite insertar un valor en un vector
void insertarElemento(int *vector, int posicion, int valor)
{
    vector[posicion] = valor;
}

// Función que determina si el vector está lleno o no
int vectorLleno(int *vector, int tamanoVector)
{
    int iterador;
    int bandera = 1;

    // Bucle que determina si el vector está lleno
    for (iterador = 0; iterador < tamanoVector; iterador++)
    {
        // Si encuentra un valor 0 en el vector, no está lleno
        if (vector[iterador] == 0)
        {
            bandera = 0;
            return bandera;
        }
    }

    return bandera;
}

