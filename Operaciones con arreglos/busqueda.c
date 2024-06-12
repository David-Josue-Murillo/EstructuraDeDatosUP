#include <stdio.h>
#include <string.h>

int main() {
	char cedula[7][12] = {
		"2-541-3445",
		"3-103-3344",
		"5-780-4326",
		"6-654-2001",
		"7-554-8979",
		"8-520-2344",
		"9-298-5001",
	};

	int n = 7, bucle = 0,desde, hasta, medio;
	char cbus[12]; // Variable para almacenar la c�dula que se busca
	char hallar;
	
	// lea valor a buscar.
	printf("Indique cedula que desea buscar: ");
	
	scanf("%s", cbus);

	// indices del arreglo8
	desde = 0;
	hallar = 'f';
	hasta = n - 1; // 7 - 1 = 6

	// busqueda binaria
	while ((desde <= hasta) && (hallar == 'f')) {
		medio = desde + (hasta - desde) / 2;

		/*printf("\nel punto medio es: %d",medio); //analice como cambian los indices
		printf("\ndesde es: %d",desde);
		printf("\nhasta es: %d",hasta);*/

		if (strcmp(cedula[medio], cbus) == 0) {
			hallar = 'c'; // lo encontr�
		} else {
			if (strcmp(cedula[medio], cbus) < 0) {
				desde = medio + 1; // buscar en la segunda mitad
			} else {
				hasta = medio - 1; ////buscar en la primera mitad
			}
		}
		bucle++;
	}

	/*------------------------------------------------------------*/

	if (hallar == 'c'){
		printf("\n La cedula - %s - se encuentra en la posicion: %d", cbus, medio);
	}
	else{
		printf("\nLa cedula %s *** NO esta en el arreglo", cbus);
	}

	printf("\niteracion %d\n\n", bucle);

	return 0;
}
