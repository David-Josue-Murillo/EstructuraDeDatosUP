#include <stdio.h>

int main() {
    char c;
    FILE *archivoTxt;

    // Abrir el archivo en modo lectura
    archivoTxt = fopen("archivo.txt", "r");
    printf("Leyendo el archivo...\n");

    // Leer el archivo
    while ((c = fgetc(archivoTxt)) != EOF) {
        printf("%c", c);    
    }

    return 0;
}