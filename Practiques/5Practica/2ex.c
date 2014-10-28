#include "../matriu.h"

int main (void)
{
	int n;
	double tol = 1e-14;
	double **A, *b;

	for (n = 1; n <= 15; n++)
	{
		A = GMH (n);
		b = GV1 (n, A);

		gauss (n, A, b, tol);
		trisup (n, A, b, tol);

		printf ("%3d:\t%.30le\n", n, Norm (n, b)-1);

		FM (A, n, n);
		FV (b, n);
	}

	return 0;
}
