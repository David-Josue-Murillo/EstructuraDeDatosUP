/* Adicione otras funciones para ordenar alfabéticamente los datos del archivo (use qsort). 
¿Puede ordenar directamente en el archivo? ¿Qué estructuras de datos ha utilizado antes 
para ordenar valores de diferentes tipos? Use otra función para producir un listado ordenado 
por nombres, que incluya las edades. ¿Conviene usar una estructura (struct) de C? */

#include <stdio.h>

int main() {
    // Variables
    FILE *archivo;
    char *nombreArchivo = "datos.dat";

    // Prototipos de funciones
    int verificarExisteArchivo(FILE *archivo);

    // Abrir el archivo
    archivo = fopen(nombreArchivo, "r");

    // Comprobar que el archivo existe
    if(!verificarExisteArchivo(archivo)) {
        printf("El archivo no existe\n");
        return 1; // Salir del programa si el archivo no existe
    }

    // Cerrar el archivo
    fclose(archivo);

    printf("\nFIN DEL PROGRAMA");
    return 0;
}

// Función que comprueba si el archivo existe
int verificarExisteArchivo(FILE *archivo) {
    if(!archivo) 
        return 0;
    return 1;
}

// Ordenar alfabéticamente
void ordenarAlfabeticamente(FILE *archivo, char *nombreMenor) {
    char nombre[10], sexo[10];
    int edad, edadMenor = 100;
    float salario;

    // Leer cada línea del archivo
    while (fscanf(archivo, "%s %d %f %s", nombre, &edad, &salario, sexo) != EOF) {
        // Comprobar si la edad es menor que la edad menor anterior
        if (edad < edadMenor) {
            edadMenor = edad;
            strcpy(nombreMenor, nombre);
        }
    }
}

