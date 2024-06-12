#include <stdio.h>

int main() {    
    //este programa lee un archivo secuencial y despliega
    // en panatalla su contenido
    FILE *txt;
    char nombre[15];
    float salario;

    txt = fopen("quiz.dat", "a"); //apertura

    if((txt=fopen("quiz.dat","r"))==NULL){
     	printf("No puede abrir el archivo\n"); 
    } else{    //utilizar contenido del archivo
	    printf("\t %s \t -- %f", nombre, salario);

	    while (!feof(txt)){
		    fscanf(txt, "%f %[^\n]", &salario, nombre);
		    printf("\n%15s --  %6.2f",  nombre, salario);
	    }
	 fclose(txt);   //cierre
	}

	return 0;
}