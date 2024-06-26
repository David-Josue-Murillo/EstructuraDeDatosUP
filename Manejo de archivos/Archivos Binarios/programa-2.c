#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[15];
    int edad;
    float salario;
} empleado;

// Declaraciones de funciones
void creafile();
void despliega();

int main(void) { // grabacion y lectura de un archivo binario
    // invocación
    creafile();  // para crear el archivo
    despliega(); // para desplegar contenido del archivo
    return 0;
} // fin main

void creafile() { // captura y graba en el archivo
    FILE *arch = fopen("datos.bin", "wb");
    if (arch == NULL) {
        printf("Error al abrir el archivo para escritura\n");
        return;
    }

    char continuar = 's';
    empleado emp;
    while (continuar == 's') {
        printf("Indique nombre, edad y salario:\n");
        scanf("%s %d %f", emp.nombre, &emp.edad, &emp.salario);
        fwrite(&emp, sizeof(empleado), 1, arch);

        printf("Desea continuar s/n: ");
        scanf(" %c", &continuar);
        memset(emp.nombre, ' ', sizeof(emp.nombre)); // limpia la cadena nombre
    } // fin del while
    fclose(arch);

} // fin de creafile

void despliega() { // lectura de los datos del archivo
    FILE *arch = fopen("datos.bin", "rb");
    if (arch == NULL) {
        printf("\n***No se puede abrir datos.bin\n");
        return; // se cancela la ejecución
    }

    char tnom[15] = "--Nombre--";
    char tedad[6] = " Edad";
    char tsal[8] = "Salario";
    empleado emp;
    int haybyte; // indica si el archivo tiene byte por leer

    printf("\n%10s%6s%8s", tnom, tedad, tsal);

    // se asume que el archivo no esta vacio para que entre al ciclo
    haybyte = fread(&emp, sizeof(empleado), 1, arch);

    while (haybyte) { // si los bytes leídos son cero, sale del ciclo
        printf("\n%10s %6d %7.2f\n", emp.nombre, emp.edad, emp.salario);
        haybyte = fread(&emp, sizeof(empleado), 1, arch);
    }
    fclose(arch);
} // fin de despliega
