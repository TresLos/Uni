#include "../matriu.h"

int main (void)
{
	int n;

	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	double **A = GMM (n, n);
	printf ("\nEntri la vector:\n");
	double *b = GVM (n);
	SM (A, n, n);
	SV (b, n);
	printf ("\nEl que has entrat mostrat:");
/* Copy past d'entrada manual */

	double *x = PMV (A, b, n, n);
	printf ("aqui una possible solucio:\n");
	SV (x, n);

	FM (A, n, n);
	FV (b, n);
	FV (x, n);
	return 0;
}
