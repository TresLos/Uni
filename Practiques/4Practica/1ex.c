/* The stdio header provides functions for performing input and output */
#include <stdio.h>

/* rand, rand_r, srand - pseudo-random number generator, calloc, malloc */
#include <stdlib.h>

/* clock - determine processor time */
#include <time.h>


#include <math.h>

#include "matriu.h"

/**
  * dimencions de A mxn, x nx1 = b mx1
  * Ax = b, on A matriu, x, b vectors
  * t es l'estructura de temps
  */
int main (void)
{
/* inicialitzant estructures pel temps, es mostren amb %ju */
	clock_t t, te;
/* use current time as seed for random generator */
	srand (time (0));// Aqui ja puc fer anar tranquilament el>> rand() <<
	int m, n;
	double **A, *x, *b;

// Begin programa
	printf ("Entri m i n:");
	scanf ("%d%d", &m, &n);

// Genera una matriu aleatoria, (maxim, minim, matriu desitjada, m, n)
	GMA (1, -1, &A, m, n);
	GVA (1, -1, &x, n);

// Operacio demanada
	time (&t);
	b = PMV (A, x, m, n);
	time (&te);

	printf ("Ja ha acabat el generador");

// Mostra la matriu
	SM (A, m, n);
	SV (x, n);
	SV (b, m);

	printf ("temps:%ju", t);

	return 0;
}
