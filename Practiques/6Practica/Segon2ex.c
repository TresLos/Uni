#include "../matriu.h"
/* Ni compilat, no se k fara muhaahahah */

/* Actualment no he fet res, nomes un copy past */
int main (void)
{
	int n, *p;
	double tol = 1e-10;
	double **A, *b, *x;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	A = GMM (n, n);
	printf ("\nEntri la vector:\n");
	b = GVM (n);
	x = CV (n, b);
	printf ("\nEl que has entrat mostrat:");
	SM (A, n, n);
	SV (b, n);
/* Copy past d'entrada manual */

	p = GVN (n);

	switch (palu (n, A, p, tol))
	{
	case -1:
		printf ("La matriu no se pot fer gauss.\n");
		break;
	case 0:
		printf ("Primera resolucio:\n");
		SM (A, n, n);
		SVI (p, n);
		switch (resolGauss (n, A, b, x, p, tol))
		{
		case -1:
			printf ("Es impossible, la diagonal es nula\n");
			break;
		case 0:
			printf ("Solucio final ?.\n\n");
			SM (A, n, n);
			SV (x, n);
			trisup (n, A, b, tol);
			printf ("Solucio final.\nDesitjada?\n");
			SV (b, n);
		}
	}

/* Alliberant memoria */
	FV (b, n);
	FM (A, n, n);
	return 0;
}
