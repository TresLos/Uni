#include "../matriu.h"

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
	SM (A, n, n);
	SV (b, n);
	printf ("\nEl que has entrat mostrat:");
/* Copy past d'entrada manual */

	switch (gauss (n, A, b, tol))
	{
	case -1:
		printf ("La matriu no se pot fer gauss sense pivotatge.\n");
		break;
	case 0:
		printf ("Primera resolucio:\n");
		SM (A, n, n);
		SV (b, n);
		switch (PreTrisup (n, A, tol))
		{
		case 1:
			printf ("Te elements nuls a la diagonal, no se pot fer la triangular superior.\n");
			break;
		case -1:
			printf ("No es triangular, pero no importa, ja que no ho volem amb gauss.\n");
		case 0:
			trisup (n, A, b, tol);
			printf ("Solucio final.\n");
			SV (b, n);
		}
	}

/* Alliberant memoria */
	FV (b, n);
	FM (A, n, n);
	return 0;
}
