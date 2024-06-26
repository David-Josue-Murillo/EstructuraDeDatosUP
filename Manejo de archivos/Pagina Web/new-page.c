#include <stdio.h>

int main() {
    FILE *archivo;
    FILE *archivo_HTML;
    char *nameArch = "opinion.txt";
    char *nameweb = "webc.html";
    char text[200];

    // Abrir el archivo de opinión para lectura
    archivo = fopen(nameArch, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s para lectura\n", nameArch);
        return 1;
    }

    // Abrir el archivo HTML para escritura
    archivo_HTML = fopen(nameweb, "w");
    if (archivo_HTML == NULL) {
        printf("Error al abrir el archivo %s para escritura\n", nameweb);
        fclose(archivo);
        return 1;
    }

    // Creación de la página web

    fprintf(archivo_HTML, "<!DOCTYPE html>\n <html lang='en'>\n <head>\n");
    fprintf(archivo_HTML, "<meta charset='UTF-8'>\n");
    fprintf(archivo_HTML, "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n");
    fprintf(archivo_HTML, "<title>Document</title>\n");
    fprintf(archivo_HTML, "<style>\n :root { color-scheme: light dark;\n *{ font-family: Arial, Helvetica, sans-serif; text-align: center; }\n h1{ font-size: 30px; padding: 10px; background: #ff0c0c63; }\n p { font-size: 16px; margin: auto; width: 50%; background: #f1f1f123; border-radius: 10px; padding: 20px 30px; margin-bottom: 10px; text-align: justify; }\n }\n </style>");
    fprintf(archivo_HTML, "</head>\n <body>\n");

    fprintf(archivo_HTML, "<h1>Opinion del curso Progrmación 3</h1>\n");

    fprintf(archivo_HTML, "<p>");
    while (fgets(text, sizeof(text), archivo) != NULL) {
        fprintf(archivo_HTML, "%s", text);
    }
    fprintf(archivo_HTML, "</p>\n");


    // Escribir el pie de página HTML
    fprintf(archivo_HTML, "</body>\n</html>");

    // Cerrar los archivos
    fclose(archivo);
    fclose(archivo_HTML);

    printf("Fin del programa\n");
    return 0;
}
