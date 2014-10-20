#include "../matriu.h"


/* Residu */
/* Ax = b */
/* b - Ay */
int main (void)
{
	int n;
	double tol = 1e-14;
	double **A, *b, *y;

	for (n = 1; n < 15; n++)
	{
		A = GMH (n);
		b = GV1 (n, A);
		y = CV (n, b);

		gauss (n, A, y, tol);
		trisup (n, A, y, tol);

		RVV (n, b, PMV (A, y, n, n));

		printf ("%3d:\t%.30le\n", n, Norm (n, b));

		FM (A, n);
		FV (b);
	}

	return 0;
}
