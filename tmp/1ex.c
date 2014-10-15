#include "matriu.h"

int main (void)
{
	int n;
	double tol = 1e-4;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	double **A = GMM (n, n);
	printf ("\nEntri la vector:\n");
	double *b = GVM (n);
	printf ("\nEl que has entrat mostrat:");

	switch (gauss (n, A, b, tol))
	{
	case 0:
		printf ("Solucio desitjada\n");
		SV (b, n);
		break;
	case 1:
		printf ("diagonal < %le", tol);
		break;
	case -1:
		printf ("No se pot fer Gauss");
		break;
	}
	SM (A, n, n);

	free (b);
	for (n = n; n >= 0; n--)
		free (A[n]);
	return 0;
}
