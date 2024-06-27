#include <stdio.h>

int main() {
    FILE *archivo;
    FILE *archivo_HTML;
    char *nameArch = "opinion.txt";
    char *nameweb = "webc.html";
    char text[200];
    char title[20];
    
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
    
    printf("Escriba un titulo para su pagina: ");
    scanf("%[^\n]", title);

    // Creación de la página web
    fprintf(archivo_HTML, "<!DOCTYPE html>\n");
    fprintf(archivo_HTML, "<<html lang='en'>\n");
    fprintf(archivo_HTML, "<head>\n");
    fprintf(archivo_HTML, "<meta charset='UTF-8'>\n");
    fprintf(archivo_HTML, "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n");
    fprintf(archivo_HTML, "<title>%s</title>\n", title);
    fprintf(archivo_HTML, "<style>\n * { font-family: Arial, Helvetica, sans-serif; text-align: center; }\n h1{ font-size: 30px; padding: 10px; background: #ff0c0c63; }\n p { font-size: 16px; margin: auto; width: 50%; background: #f1f1f123; border-radius: 10px; padding: 20px 30px; margin-bottom: 10px; text-align: justify; }\n }\n </style>\n");
    fprintf(archivo_HTML,":root { color-scheme: light dark }\n ");
    fprintf(archivo_HTML,":</style");
	fprintf(archivo_HTML, "</head>\n\n <body>\n");

    fprintf(archivo_HTML, "<h1>Opinion del curso Progrmación 3</h1>\n");

    fprintf(archivo_HTML, "<p>");
     // Leer y escribir cada palabra usando fscanf
    while (fscanf(archivo, "%s", text) != EOF) {
        fprintf(archivo_HTML, "%s ", text);
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
