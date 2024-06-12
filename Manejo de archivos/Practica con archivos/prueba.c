#include <stdio.h>
/*  Captura datos desde teclado y los graba en un archivo y luego lee los datos
    desde el archivo....NOTE el espacio después del último formato de conversión
    en el fscanf, lo uso para que el salto de línea( \n) que se lee, no se confunda 
    con el fin de archivo (EOF). Pruebe con y sin el espacio y comente. */
int main()
{
    FILE *arch;
    int edad, i, n;
    char nom[30];

    arch = fopen("prueba.txt", "w");
    printf("Indique edad y luego el nombre\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &edad, nom);
        fprintf(arch, "%d %s\n", edad, nom);
    }
    fclose(arch);
    
    arch = fopen("prueba.txt", "r");
    if (!arch)
        printf("\n***Archivo no se puede abrir");
    while (!feof(arch) && arch)
    {
        fscanf(arch, "%d %s ", &edad, nom);
        printf(" %d %s\n", edad, nom);
    }
    return 0;
}