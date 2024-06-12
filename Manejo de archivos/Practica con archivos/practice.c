#include <stdio.h>

int main(void) { 
    /*       captura datos desde teclado y los guarda en el archivo test.txt  */
    FILE *fp;
    char s[80];
    int t;

    if ((fp = fopen("test.txt", "w")) == NULL)
    {
        printf("No puede abrir el archivo\n");
    }

    printf("Indique una cadena y un número:");
    fscanf(stdin, "%s%d", s, &t); /*lectura desde teclado */

    fprintf(fp, "%s %d", s, t); /*grabación en el archivo*/
    fclose(fp);

    // abre el archivo pero ahora de "r" para leer y desplegar
    if ((fp = fopen("test.txt", "r")) == NULL) {
        printf("No puede abrir el archivo\n");
    }

    fscanf(fp, "%s%d", s, &t);      /*lectura del archivo*/
    fprintf(stdout, "%s %d", s, t); /*despliegue en pantalla*/

    return 0;
}