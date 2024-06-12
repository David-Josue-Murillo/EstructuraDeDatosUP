#include <stdio.h>

int main() {
    struct empleado
    {
        int edad;
        float salario;
        char nombre[20];
        char sexo[20];
    };
    
    int i;
    struct empleado empleado[40];
    
    for( i = 0; i < 4; i++){
        printf("Nombre: ");
        scanf(" %s", empleado[i].nombre);
        
        printf("Edad: ");
        scanf("%d", &empleado[i].edad);
    }
    
    for ( i = 0; i < 4; i++){
    	printf("\n%s tiene %d \n", empleado[i].nombre, empleado[i].edad);
	}

    printf("\n\n");
    return 0;
}
