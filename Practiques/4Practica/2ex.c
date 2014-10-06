#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matriu.h"


int main (void)
{
	// Testeix del programa en si
//	int a = trisup ();
	printf ("Entri dim de la matriu:\n")
	scanf ("%d%d", &n)
	printf ("\nEntri la matriu:\n")
	double **U = GMM (n, n);
	printf ("\nEntri la vector:\n")
	double *b = GVM (n);
	printf ("\nEl que has entrat mostrat:");
	switch (trisup (n, U, b, tol))
	{
	case 0:
		SM (b, 2, 2);
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
