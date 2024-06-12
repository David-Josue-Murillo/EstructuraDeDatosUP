#include <stdio.h>

int main(){
    // Crear un archivo de texto
    FILE *archivoTxt;

    // Abrir el archivo en modo escritura
    archivoTxt = fopen("archivo.txt", "w");

    // Escribir en el archivo
    fprintf(archivoTxt, "Hola mundo\n");
    fprintf(archivoTxt, "Soy tu padre\n");

    // Cerrar el archivo
    fclose(archivoTxt);
    
    return 0;
}