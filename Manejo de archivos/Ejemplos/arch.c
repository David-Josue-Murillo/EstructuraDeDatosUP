#include <stdio.h>

int main() {
    FILE *file;
    char buffer[100];
    char filename[] = "example.txt";

    // Apertura del archivo en modo escritura
    file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error al abrir el archivo para escritura");
        return 1;
    }

    // Escribir datos en el archivo
    fprintf(file, "Hola, mundo!\n");
    fprintf(file, "Esta es una prueba de manejo de archivos en C.\n");
    
    // Cerrar el archivo después de escribir
    fclose(file);

    // Apertura del archivo en modo lectura
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo para lectura");
        return 1;
    }

    // Leer y mostrar datos del archivo
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Cerrar el archivo después de leer
    fclose(file);

    return 0;
}
