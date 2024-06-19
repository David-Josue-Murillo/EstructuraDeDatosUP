/* Construya una función para determinar el nombre de la persona de menor edad. 
Claro debe leer los datos del archivo, imprima en el programa principal ¿qué modo de apertura debe usar? 
¿Cuáles serán los formatos de conversión que debe usar en el fscanf()? 
¿Qué código (segmento de programa) debe incluir para verificar si el archivo existe? ¿Cuál es el tipo de la función? */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
    // Variables
    char nombreMenor[10];
    FILE *archivo;
    char *nombreArchivo = "datos.dat";

    // Prototipos de funciones
    int verificarExisteArchivo(FILE *archivo);
    void nombreMenorEdad(FILE *archivo, char *nombreMenor);
    
    // Abrir el archivo
    archivo = fopen(nombreArchivo, "r");

    // Comprobar que el archivo existe
    if (!verificarExisteArchivo(archivo)) {
        printf("El archivo no existe\n");
        return 1; // Salir del programa si el archivo no existe
    }

    // Determinar el nombre de la persona de menor edad
    nombreMenorEdad(archivo, nombreMenor);

    printf("El nombre de la persona de menor edad es: %s\n", nombreMenor);

    // Cerrar el archivo
    fclose(archivo);

    printf("Fin del programa\n");
    return 0;
}

// Función que comprueba si el archivo existe
int verificarExisteArchivo(FILE *archivo) {
    if (!archivo)
        return 0;
    return 1;
}

// Función que determina el nombre de la persona de menor edad
void nombreMenorEdad(FILE *archivo, char *nombreMenor) {
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