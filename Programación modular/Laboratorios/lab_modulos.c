
 
/* programa que coloque elementos en un vector (num�rico o de caracteres) de manera que los elementos siempre est�n ordenados. A medida que entra un valor debe 
ser colocado en la posici�n correspondiente para mantener el orden de los elementos.*/
																																					
 #include <stdio.h>

int main ()
{
	int i, n, val_insert;
	int cant_elements = 0;   // variable para llevar un registro de la cantidad de elementos presentes en el vector
	printf("cantidad de elementos -- ");
	scanf("%d", &n);
	int vector[n + 1]; //se incrementa el tama�o para permitir la inserci�n de un nuevo elemento
	
	// prototipos de funciones
	void cap_elementos(int vector[], int *n, int *cant_elements, void (*ordenacion)(int[], int, int), void (*desplegar_vector)(int[], int), int(*posicion)(int[], int, int)); // para la funcion capturar elementos
	void ordenacion(int vector[], int cant_elements, int valor); // prototipo de la funci�n ordenacion
	void desplegar_vector(int vector[], int n);  // prototipo de la funci�n desplegar_vector
	void correr_elementos(int vector[], int n);   // prototipo de la funci�n correr_elementos
	int posicion (int vector[], int n, int valor);  // prototipo de la funci�n posicion
	void insertar (int vector[], int *n, int *cant_elements, int val_insert);// prototipo de la funci�n insertar
	void vect_lleno_true_false(int n, int cant_elements); // prototipo de la funci�n que determina si el vector est� lleno o no.
	
    cap_elementos(vector, &n, &cant_elements, ordenacion, desplegar_vector, posicion);  // llama a la funci�n cap_elementos
    
    
    correr_elementos(vector, n);
    printf("\nelementos corridos -- ");
    for (i = 0; i < n; i++){
    	printf("%d ", vector[i]);
	}
	printf("\n");
	
	printf("\nvalor que desea insertar -- ");
	scanf("%d", &val_insert);
	insertar(vector, &n, &cant_elements, val_insert);  // se pasa el tama�o del vector por referencia
	printf("Vector despu%cs de la inserci%cn ", 130, 162);
    for (i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
    
    vect_lleno_true_false(n, cant_elements);

	return 0;
}

//  	Funci�n para captura de los elementos del vector
void cap_elementos (int vector[], int *n, int *cant_elements, void (*ordenacion)(int[], int, int), void (*desplegar_vector)(int[], int), int (*posicion)(int[], int, int))
{
	int valor;  // variable para almacenar el valor ingresado por el usuario
    int sw = 1; // variable de control para el bucle
    //int cant_elements = 0;
    int p_v;  // variable para almacenar la posici�n en la que se debe agregar el valor
	
	printf("\nintroduzca valores (o ingrese un numero negativo para terminar)\n");
	while (sw == 1 && *cant_elements  < *n) {
       	printf("\ningrese un valor -- ");
        scanf("%d", &valor);

        if (valor < 0 ) {  // verifica si el valor ingresado es negativo
            sw = 0;    // se cambia el valor de sw a 0 para salir del bucle
       /* } else if (*cant_elements == *n){
        	printf("\nEl vector est� lleno.\n");
        	sw = 0;*/
		} else {
			p_v = posicion(vector, *cant_elements, valor);  // calcula la posici�n en la que se debe agregar el valor
			printf("posici%cn en la que debe agregarse -- %d", 162, p_v);
    		ordenacion(vector, *cant_elements, valor);
            (*cant_elements)++;  // incrementa la cantidad de elementos en el vector
            printf("\nVector: ");
            desplegar_vector(vector, *cant_elements);
		}
    }

    *n = *cant_elements; // Actualizar n con la cantidad real de elementos ingresados
} 

// ordenacion por insercion
void ordenacion (int vector[], int cant_elements, int valor)
{
	int i = cant_elements - 1;
    while (i >= 0 && vector[i] > valor) {
        vector[i + 1] = vector[i];
        i--;
    }
    vector[i + 1] = valor;
	
}


//  	Funci�n para desplegar el vector.
void desplegar_vector(int vector[], int n) 
{
	int i;
    for (i = 0; i < n; i++) { 
        printf("%d ", vector[i]);
    }
    printf("\n");
  
}


// Funci�n para correr los elementos de un vector a la siguiente posici�n
void correr_elementos(int vector[], int n)
 {
	int i;
	int aux = vector[n - 1]; // variable temporal para guardar el ultimo elemento del vector
	for (i = n - 2; i >= 0; i-- ){  // se mueve el elemento del indice n - 2 hasta el indice 0
		vector[i + 1] = vector[i];	 // se mueve cada elemento a la derecha
	}
	vector[0] = aux; // se le asigna el valor temporal al primer elemento
}


//  	Funci�n que determina la posici�n del vector en la que debe colocarse el siguiente valor.
int posicion(int vector[], int n, int valor)
{
	int i = 0;
	while (i < n && vector[i] < valor){  // bucle para encontrar la posici�n donde debe colocarse el valor
		i++;
	}
	return i; // devuelve el �ndice despu�s del �ltimo elemento 
}


 //	Funci�n que permite insertar un valor en un vector.
 // buscara la posicion adecuada para insertar el valor, utilizando busqueada secuencial
void insertar (int vector[], int *n, int *cant_elements, int val_insert)
{
	int i = *n - 1;
    while (i >= 0 && vector[i] > val_insert) {
        vector[i + 1] = vector[i];   // aqui se desplaza los elementos del vector
        i--;
    }
    vector[i + 1] = val_insert;
    (*cant_elements)++; // incrementar la cantidad de elementos en el vector
    (*n)++; // incrementar el tama�o del vector
}


//  	Funci�n que determina si el vector est� lleno o no.
void vect_lleno_true_false(int n, int cant_elements)
{
	if (cant_elements == n ) {  // comprueba si la cantidad de elementos es igual al tama�o del vector
        printf("\nel vector est%c lleno", 160);
    } else if (cant_elements == 0){  // comprueba si el vector est� vac�o
        printf("\nel vector est%c vac%co",160, 161);
	}
}
