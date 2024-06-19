/* Incluya otra función para adicionar más personas a su archivo. 
Entre al directorio del disco y luego a la carpeta que contiene su 
archivo y verifique los nuevos registros ¿Quedaron alineados? 
¿ forman columnas perfectas?  */

#include <stdio.h>

struct persona {
    char nombre[10];
    char edad[5];
    char salario[6];
    char sexo[11];
};

int verificarExisteArchivo(FILE *archivo);
void adicionarPersona(FILE *archivo, struct persona persona);

int main() {
    // Variables
    char *nombreArchivo = "datos.dat";
    char flag;
    FILE *archivo; // variable que almacena el archivo
    struct persona persona; // Estructura que almacenara los datos de una persona

    // Abrir el archivo 
    archivo = fopen(nombreArchivo, "a+"); // "a+" abre un archivo para añadir y leer datos

    if (!verificarExisteArchivo(archivo)) {
        printf("El archivo no existe\n");
        return 1; // Terminar el programa si el archivo no existe
    }

    // Agregar datos a la lista
    do {
        printf("Ingresa tu nombre: ");
        scanf("%9s", persona.nombre); // Limitar la entrada a 19 caracteres

        printf("Ingresa tu edad: ");
        scanf("%4s", persona.edad); // Limitar la entrada a 3 caracteres

        printf("Ingresa tu salario: ");
        scanf("%5s", persona.salario); // Limitar la entrada a 5 caracteres

        printf("Ingresa tu sexo (Masculino/Femenino): ");
        scanf("%10s", persona.sexo); // Limitar la entrada a 9 caracteres

        adicionarPersona(archivo, persona);

        printf("¿Quieres agregar más personas? (S/N): ");
        scanf(" %c", &flag); // Leer un carácter, notando el espacio antes de %c para consumir cualquier espacio en blanco

    } while (flag == 'S' || flag == 's');

    printf("Datos agregados correctamente\n");
    fclose(archivo);

    printf("Fin del programa\n");
    return 0;
}

// Función que comprueba si el archivo existe
int verificarExisteArchivo(FILE *archivo) {
    return (archivo != NULL);
}

// Función para adicionar persona al archivo
void adicionarPersona(FILE *archivo, struct persona persona) {
    fprintf(archivo, "%-10s %-2s %-4s %-10s\n", persona.nombre, persona.edad, persona.salario, persona.sexo);
}