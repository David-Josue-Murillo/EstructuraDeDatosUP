#include <stdio.h>

struct estudiantes
{
    char nombre[25];
    char cedula[13];
    int edad;
    float indice;
    float calificaciones[5];
};


int main() {
    // Variables
    int i, j;
    char menorEdadEst[25];
    struct estudiantes estudiantes_up[5], newEst;

    // Prototipos de funciones
    void capturarEst(struct estudiantes estudiantes_up[], int cantidadEst);
    void desplegarEst(struct estudiantes estudiantes_up[], int cantidadEst, char);
    char menor_edad(struct estudiantes estudiantes_up[], int num_estudiantes);
    struct estudiantes Mpromedio(struct estudiantes estudiantes_up[]);

    // Llamada a funciones
    newEst = Mpromedio(estudiantes_up);
    capturarEst(estudiantes_up, 5);
    menorEdadEst = menor_edad(estudiantes_up, 5);
    desplegarEst(estudiantes_up, 5, menorEdadEst);

    return 0;
}

char menor_edad(struct estudiantes estudiantes_up[], int num_estudiantes)
{
    char *nombre;
    for (int i = 1; i < num_estudiantes; i++)
    {
        if (estudiantes_up[i].edad < estudiantes_up[i+1].edad)
        {
            nombre = estudiantes_up[i].nombre;
        }
    }

    return *nombre;
}

struct estudiantes Mpromedio(struct estudiantes estudiantes_up[]) {
    int i, k;
    float mayorPromedio, promedio, suma;
    struct estudiantes aux;

    for(i = 0; i<5; i++){
    	suma = 0;
    	
    	for(k = 0; k<5; i++){
    		suma += estudiantes_up[i].calificaciones[k];
            promedio = suma / 5;

			if(promedio > mayorPromedio){
				mayorPromedio = promedio;
				aux = estudiantes_up[i];
			} 
		}
	}    
	
	return aux;
}

void capturarEst(struct estudiantes estudiantes_up[], int cantidadEst) {
    int i, j;
    
    for (i = 0; i < cantidadEst; i++)
    {
        printf("Alumno #%d Introduzca su nombre: ", i + 1);
        scanf("%s", estudiantes_up[i].nombre);

        printf("Introduzca su cedula: ");
        scanf("%s", estudiantes_up[i].cedula);

        printf("Introduzca su edad: ");
        scanf("%d", &estudiantes_up[i].edad);

        printf("Introduzca su indice academico: ");
        scanf("%f", &estudiantes_up[i].indice);

        for (j = 0; j < 5; j++)
        {
            printf("Calificación #%d: ", j + 1);
            scanf("%f", &estudiantes_up[i].calificaciones[j]);
        }
        printf("\n");
    }
}

void desplegarEst(struct estudiantes estudiantes_up[], int cantidadEst, char menorEdadEst) {
 int i, j;

    for (i = 0; i < cantidadEst; i++)
    {
        printf("\nEstudiante: %s", estudiantes_up[i].nombre);
        printf("\nCedula: %s", estudiantes_up[i].cedula);
        printf("\nEdad: %d", estudiantes_up[i].edad);
        printf("\nIndice: %.2f", estudiantes_up[i].indice);

        for (j = 0; j < 5; j++)
        {
            printf("\nCalificación #%d: %.2f", j + 1, estudiantes_up[i].calificaciones[j]);
        }
        printf("\n");
    }    
}


