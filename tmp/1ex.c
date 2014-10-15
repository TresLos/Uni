#include "matriu.h"

int main (void)
{
	int n, i;
	double tol = 1e-4;
	double **A, *b;

	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	A = GMM (n, n);
	printf ("\nEntri la vector:\n");
	b = GVM (n);
	printf ("\nEl que has entrat mostrat:");

	switch (gauss (n, A, b, tol))
	{
	case 0:
		printf ("Solucio desitjada\n");
		SV (b, n);
		printf ("Mostra un cop fet Triangular superior\n");
		trisup (n, A, b, tol);
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
	for (i = 0; i < n; i++)
		free (A[i]);
	free (A);
	return 0;
}
