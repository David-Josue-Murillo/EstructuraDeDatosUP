#include <stdio.h>

int main(){
	char *s;
	char *imprimir();
	
	s = imprimir();
	
	printf("%s", s);
}

char *imprimir(){

	return("hola");	
}

