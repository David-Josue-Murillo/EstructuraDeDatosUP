#include <string.h>
#include <stdio.h>

int main()
{
    // Este programa solicita al usuario ingresar un número de cadenas, luego las lee y las ordena alfabéticamente para luego imprimirlas.
    char cadenas[15][20];
    char aux[20];
    int k, i, n;
    printf("indique cantidad de cadenas, no mas de 15==> ");
    scanf("%d", &n);

    if (n > 15)
    {
        printf("***No acepta mas de 15 cadenas");
        return 1;
    }

    // captura de las cadenas
    for (i = 0; i < n; i++) {
        printf("\nescriba una cadena y luego enter: ");
        scanf(" %[^\n]", cadenas[i]);
    }

    // proceso de ordenación por el método de ....
    for (i = 0; i < n - 1; i++) { 
        for (k = i + 1; k < n; k++) { 
            if (strcmp(cadenas[i], cadenas[k]) > 0)
            {
                strcpy(aux, cadenas[k]);
                strcpy(cadenas[k], cadenas[i]);
                strcpy(cadenas[i], aux);
            }
        }
    }

    for (i = 0; i < n; i++) { 
        printf("\n%s", cadenas[i]);
    }

    return 0;
} 