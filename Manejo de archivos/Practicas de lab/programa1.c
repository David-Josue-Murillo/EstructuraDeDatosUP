/* Escriba un programa modular que lea y despliegue cada línea del archivo, 
cambie el color de la pantalla. ¿Cómo detectará el final del archivo? 
Revise los pasos para manejar un archivo. ¿Los cumplió? */

#include <stdio.h>

int main() {
    FILE *archivo;
    char *nombreArchivo = "datos.dat";

    // Prototipos de funciones
    int verificarExisteArchivo(FILE *archivo);
    void iterarArchivo(FILE *archivo);

    // Abrir el archivo
    archivo = fopen(nombreArchivo, "r");

    // Comprobar que el archivo existe
    if (!verificarExisteArchivo(archivo)) {
        printf("El archivo no existe\n");
        return 1; // Terminar el programa si el archivo no existe
    }

    // Leer y desplegar cada línea
    iterarArchivo(archivo);

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}

// Función que comprueba si el archivo existe
int verificarExisteArchivo(FILE *archivo) {
    if (!archivo) 
        return 0;
    
    return 1;
}

// Función que itera cada línea del archivo
void iterarArchivo(FILE *archivo) {
    char nombre[10], edad[4], salario[5], sexo[10];

    // Leer cada línea del archivo
    while (fscanf(archivo, "%s %s %s %s", nombre, edad, salario, sexo) != EOF) {
        printf("Nombre: %s - Edad: %s - Salario: %s - Sexo: %s\n", nombre, edad, salario, sexo);
    }
}