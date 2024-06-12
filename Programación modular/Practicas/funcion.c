#include <stdio.h>

int main(void) {
    void desplegar(char *cadena, int);
    int suma(int, int), res;
	
	res = suma(5,15);
	char cadena[50] = "La suma es: ";
	
    desplegar(cadena, res);
    return 0;
}


void desplegar(char *cadena, int numero ) {
    printf("%s %d\n", cadena, numero);
}

int suma(int a, int b){
	int res = a + b;
	return (res);
}
