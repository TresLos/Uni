#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriu.h"


int main (void)
{
/* clock_t --> t = \Apha t / CLOCKS_PER_SEC */
	/* Testeix del programa en si */
	int n;
	double tol = 1e-4;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	double **U = GMM (n, n);
	printf ("\nEntri la vector:\n");
	double *b = GVM (n);
	SM (U, n, n);
	SV (b, n);
	printf ("\nEl que has entrat mostrat:");


	switch (trisup (n, U, b, tol))
	{
	case 0:
		printf ("Solucio desitjada\n");
		SV (b, n);
		break;
	case 1:
		printf ("diagonal < %le", tol);
		break;
	case -1:
		printf ("No es una matriu triangular superior");
		break;
	}

	free (b);
	for (n = n -1; n >= 0; n--)
		free (U[n]);
	return 0;
}
