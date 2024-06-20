#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar a una persona
struct persona {
    int edad;
    float salario;
    char nombre[30];
};

// Prototipos de funciones
int verificarExisteArchivo(FILE *archivo);
void leerDatos(FILE *archivo, struct persona personas[], int *numPersonas);
void ordenarPersonas(struct persona personas[], int numPersonas, int (*comparar)(const void *, const void *));
void desplegarPersonas(struct persona personas[], int numPersonas);
int compararPorNombre(const void *a, const void *b);

int main() {
    struct persona personas[10];
    int numPersonas = 0;
    FILE *archivo;
    char *nombreArchivo = "archivo_2.txt";

    // Abrir el archivo
    archivo = fopen(nombreArchivo, "r");

    // Comprobar que el archivo existe
    if (!verificarExisteArchivo(archivo)) {
        printf("El archivo no existe\n");
        return 1; // Salir del programa si el archivo no existe
    }

    // Leer los datos del archivo
    leerDatos(archivo, personas, &numPersonas);
    
    // Cerrar el archivo
    fclose(archivo);

    // Ordenar los datos por nombre
    ordenarPersonas(personas, numPersonas, compararPorNombre);

    // Desplegar los datos ordenados
    desplegarPersonas(personas, numPersonas);

    printf("Fin del programa\n");
    return 0;
}

// Funci�n que comprueba si el archivo existe
int verificarExisteArchivo(FILE *archivo) {
    return archivo != NULL;
}

// Funci�n que lee los datos del archivo usando fscanf
void leerDatos(FILE *archivo, struct persona personas[], int *numPersonas) {
    *numPersonas = 0;
    while (fscanf(archivo, "%d %f %[^\n]", &personas[*numPersonas].edad, &personas[*numPersonas].salario, personas[*numPersonas].nombre) == 3) {
        (*numPersonas)++;
    }
}

// Funci�n que ordena los datos por nombre
void ordenarPersonas(struct persona personas[], int numPersonas, int (*comparar)(const void *, const void *)) {
    qsort(personas, numPersonas, sizeof(struct persona), comparar);
}

// Funci�n que despliega los datos ordenados
void desplegarPersonas(struct persona personas[], int numPersonas) {
    int i;
	for (i = 0; i <= numPersonas; i++) {
        printf("%d %.2f %s\n", personas[i].edad, personas[i].salario, personas[i].nombre);
    }
}

// Funci�n que compara dos personas por su nombre
int compararPorNombre(const void *a, const void *b) {
    struct persona *personaA = (struct persona *)a;
    struct persona *personaB = (struct persona *)b;
    return strcmp(personaA->nombre, personaB->nombre);
}

