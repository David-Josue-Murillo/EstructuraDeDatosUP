#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h" 

int i;

void capturaElementos(int *vector, int *tamano, int capacidad);
void desplegarVector(int *vector, int tamano);
void correrElementos(int *vector, int posicinn, int tamano);
int determinarPosicion(int *vector, int valor, int tamano);
void insertarValor(int *vector, int valor, int *tamano);
int vectorLleno(int tamano, int capacidad);

