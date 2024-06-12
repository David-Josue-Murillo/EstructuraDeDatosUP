#include <stdio.h>

int main(){
	int a = 2, b = 4;
	char cadena[50] = "La suma es: ";
	printf("Valor #1: %d\n", a);
	printf("Valor #2: %d\n", b);
	
	void desplegar(char *cadena, int, int);
	int intercambio (int *a, int *b); 
	
	intercambio(&a, &b);
	desplegar(cadena, a, b);
	
	return 0;
}

void desplegar(char *cadena, int numero, int b ) {
    printf("%s %d %d\n", cadena, numero, b);
}

int intercambio(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
