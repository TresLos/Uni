#include "matriu.h"

int main (void)
{
	double **A, *b, tol;
	int n;
	tol = 1e-4;

	for (n = 1; n < 15; n++)
	{
		A = GMH (n);
		b = GVH (A, n);

		gauss (n, A, b, tol);
		trisup (n, A, b, tol);

		printf ("%3d:\n", n);
		SV (b, n);
	}

/* Alliberem memoria */

	return 0;
}
