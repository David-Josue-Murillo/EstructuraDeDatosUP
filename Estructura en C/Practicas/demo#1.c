#include <stdio.h>

struct estudiantes {
    char nombre[25];
    char cedula[13];
    int edad;
    float indice;
    float calificaciones[5];
};

int main() {
    // Variables
    struct estudiantes estudiantes_up[5];

    // Prototipos de funciones
    void capturarEst(struct estudiantes estudiantes_up[], int cantidadEst);
    void desplegarEst(struct estudiantes estudiantes_up[], int cantidadEst);
    char *menor_edad(struct estudiantes estudiantes_up[], int num_estudiantes);
    struct estudiantes Mpromedio(struct estudiantes estudiantes_up[], int num_estudiantes);

    // Llamada a funciones
    capturarEst(estudiantes_up, 5);
    desplegarEst(estudiantes_up, 5);

    return 0;
}

// Funcion que recibe un arreglo de estructuras y devuelve el nombre del estudiante con menor edad
char *menor_edad(struct estudiantes estudiantes_up[], int num_estudiantes) {
    char *nombre = estudiantes_up[0].nombre;
    int menor_edad_index = 0, i;

    for ( i = 1; i < num_estudiantes; i++) {
        if (estudiantes_up[i].edad < estudiantes_up[menor_edad_index].edad) {
            menor_edad_index = i;
            nombre = estudiantes_up[menor_edad_index].nombre;
        }
    }

    return nombre;
}

// Funcion que recibe un arreglo de estructuras y devuelve la estructura con mayor promedio
struct estudiantes Mpromedio(struct estudiantes estudiantes_up[], int num_estudiantes) {
    int i, k;
    float mayorPromedio = 0, promedio, suma;
    struct estudiantes aux = {0};

    for (i = 0; i < num_estudiantes; i++) {
        suma = 0;
        for (k = 0; k < 5; k++) {
            suma += estudiantes_up[i].calificaciones[k];
        }
        promedio = suma / 5;
        if (promedio > mayorPromedio) {
            mayorPromedio = promedio;
            aux = estudiantes_up[i];
        }
    }
    
    return aux;
}

// Funcion que recibe un arreglo de estructuras y captura los datos de los estudiantes
void capturarEst(struct estudiantes estudiantes_up[], int cantidadEst) {
    int i, j;
    
    for (i = 0; i < cantidadEst; i++) {
        printf("Alumno #%d Introduzca su nombre: ", i + 1);
        scanf("%s", estudiantes_up[i].nombre);

        printf("Introduzca su cedula: ");
        scanf("%s", estudiantes_up[i].cedula);

        printf("Introduzca su edad: ");
        scanf("%d", &estudiantes_up[i].edad);

        printf("Introduzca su indice academico: ");
        scanf("%f", &estudiantes_up[i].indice);

        for (j = 0; j < 5; j++) {
            printf("Calificación #%d: ", j + 1);
            scanf("%f", &estudiantes_up[i].calificaciones[j]);
        }
        printf("\n");
    }
}

// Funcion que recibe un arreglo de estructuras y despliega los datos de los estudiantes
void desplegarEst(struct estudiantes estudiantes_up[], int cantidadEst) {
    int i, j;
    struct estudiantes newEst;

    printf("\nEl estudiante de menor edad es: %s\n", menor_edad(estudiantes_up, cantidadEst));

    newEst = Mpromedio(estudiantes_up, 5);
    // Desplegar estudiante con mayor promedio
    printf("\nEstudiante con mayor promedio en Estructura de Datos:\n");
    printf("Nombre: %s\n", newEst.nombre);
    printf("Cedula: %s\n", newEst.cedula);
    printf("Edad: %d\n", newEst.edad);
    printf("Indice Academico: %.2f\n", newEst.indice);


    for (i = 0; i < cantidadEst; i++) {
        printf("\nEstudiante: %s", estudiantes_up[i].nombre);
        printf("\nCedula: %s", estudiantes_up[i].cedula);
        printf("\nEdad: %d", estudiantes_up[i].edad);
        printf("\nIndice: %.2f", estudiantes_up[i].indice);

        for (j = 0; j < 5; j++) {
            printf("\nCalificación #%d: %.2f", j + 1, estudiantes_up[i].calificaciones[j]);
        }
        printf("\n");
    }    
}
