#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriu.h"


int main (void)
{
	// Testeix del programa en si
	int n;
	double tol = 1e-4;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	double **U = GMM (n, n);
	SM (U, n, n);
	printf ("\nEntri la vector:\n");
	double *b = GVM (n);
	printf ("\nEl que has entrat mostrat:");
	switch (trisup (n, U, b, tol))
	{
	case 0:
		SV (b, 2);
		break;
	case 1:
		printf ("diagonal < %le", tol);
		break;
	case -1:
		printf ("No es una matriu triangular superior");
		break;
	}
	return 0;
}
