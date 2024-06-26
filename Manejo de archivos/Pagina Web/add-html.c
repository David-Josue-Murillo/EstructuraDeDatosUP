#include <stdio.h>

int main() {
    FILE *archivo;
    char *nameHtml = "index.html";
    char parrafo[100];
    int i;

    // Abrir el archivo HTML para escritura
    archivo = fopen(nameHtml, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s para escritura\n", nameHtml);
        return 1;
    }

    for(i = 0; i < 10; i++) {
        /* code */
        fprintf(archivo, "<p>\
        n");
        printf("Indique el contenido del archivo HTML: ");
        scanf(" %[^\n]", parrafo);

        // Escribir el contenido del archivo HTML
        fprintf(archivo, "%s", parrafo);
        fprintf(archivo, "</p>\n");
    }
    
    // Escribir el pie de página HTML
    fprintf(archivo, "</body>\n</html>");

    // Cerrar el archivo
    fclose(archivo);

    printf("Fin del programa\n");
    return 0;
}
