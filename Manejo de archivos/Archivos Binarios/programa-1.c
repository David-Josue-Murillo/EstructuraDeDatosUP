#include <stdio.h>
#include <stdlib.h>

int main(void){
    //Variables
    FILE *archivo;
    char *nombreArchivo = "archivo.txt";

    //Abrir el archivo
    archivo = fopen(nombreArchivo, "a");

    if (!archivo){
        printf("No puede abrir el archivo\n");
        return 1;
    }

    fprintf(archivo, "Hola mundo\n");

    fclose(archivo);


    printf("Fin del programa\n");
    return 0;
}