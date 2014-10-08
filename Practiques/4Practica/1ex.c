/* The stdio header provides functions for performing input and output */
#include <stdio.h>

/* rand, rand_r, srand - pseudo-random number generator, calloc, malloc */
#include <stdlib.h>

/* clock - determine processor time */
#include <time.h>


#include <math.h>

/* Recordar que files x columnes */
#include "matriu.h"

/**
  * dimencions de A mxn, x nx1 = b mx1
  * Ax = b, on A matriu, x, b vectors
  * t es l'estructura de temps inicial
  * te es l'estructura de temps final
  * tt es el double amb els segons total de l'execucio
  * ti es algo que per ara no se que serveix
  */
int main (void)
{
/* inicialitzant estructures pel temps, es mostren amb %ju */
	clock_t t, te, tp;
/* use current time as seed for random generator */
	int m, n;
	double **A, *x;//, *b;
	double tt, td;

// Begin programa
	printf ("Entri m i n:");
	scanf ("%d%d", &m, &n);

// Genera una matriu aleatoria, (maxim, minim, matriu desitjada, m, n)
	time (&tp);
	GMA (1, -1, &A, m, n);
	GVA (1, -1, &x, n);

// Operacio demanada
	time (&t);
	PMV (A, x, m, n);
	//b = PMV (A, x, m, n);
	time (&te);

	printf ("\nJa ha acabat el generador\n");

// Mostra la matriu
/*	SM (A, m, n);
	SV (x, n);
	SV (b, m);*/

//	printf ("temps:%ju", t);
	td = difftime (t, tp);
	tt = difftime (te, t);
	printf ("segons abans %ju\n", tp);
	printf ("segons abans %ju\n", t);
	printf ("segons abans %ju\n", te);
	printf ("\nA, matriu de m{files} x n{columnes}: %d x %d\n", m, n);
	printf ("Ha tardat %.20le segons\n", tt);
	printf ("Ha tardat en generar %.20le segons\n", td);
	printf ("Per una relacio t/mn = %le\n", tt/(m*n));

	return 0;
}
