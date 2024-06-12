#include <stdio.h>
#include <string.h>

int main()
{
	char cedula[7][12] = {
		"2-123-1234",
		"3-980-1428",
		"4-111-2374",
		"4-289-4318",
		"5-234-8902",
		"8-298-1299",
		"19-345-1232",
	};

	int n = sizeof(cedula) / sizeof(cedula[0]);
	char cbus[12]; // Variable para almacenar la cedula que se busca
	int desde, hasta, medio;
	char hallado;
	int cantIteracion = 1;

	// lea valor a buscar.
	printf("Indique cedula que desea buscar: ");
	scanf("%s", cbus);

	// indices del arreglo
	desde = 0;
	hasta = n - 1; // 7 - 1 = 6
	hallado = 'f'; // variable para indicar si se encontro o no

	// busqueda binaria
	while ((desde <= hasta) && (hallado == 'f'))
	{
		medio = desde + (hasta - desde) / 2;
		/* printf("\nel punto medio es: %d",medio); //analice como cambian los indices
			 printf("\ndesde es: %d",desde);
			 printf("\nhasta es: %d",hasta);*/
		if (strcmp(cedula[medio], cbus) == 0)
		{
			hallado = 'c'; // lo encontro
		}
		else
		{
			if (strcmp(cedula[medio], cbus) < 0)
			{
				desde = medio + 1; // buscar en la segunda mitad
			}
			else
			{
				hasta = medio - 1; //buscar en la primera mitad
			}
		}
		cantIteracion++;
	}

	/*------------------------------------------------------------*/

	if (hallado == 'c')
	{
		printf("\n La cedula - %s - se encuentra en la posicion: %d", cbus, medio);
	}
	else
	{
		printf("\n\n La cedula %s *** NO esta en el arreglo", cbus);
	}
	printf("\niteracion %d", cantIteracion);

	return 0;
}
