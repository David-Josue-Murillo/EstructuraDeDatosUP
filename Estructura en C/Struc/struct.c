#include <stdio.h>

int main() {
    struct empleado
    {
        int edad;
        float salario;
        char nombre[20];
        char sexo[20];
    };
    
    struct empleado emp, emp1;
    
    printf("Nombre: ");
    scanf(" %s", emp.nombre);
    
    printf("Edad: ");
    scanf("%d", &emp.edad);
    
    printf("\n%s tiene %d", emp.nombre, emp.edad);

    printf("\n\n");
    return 0;
}
