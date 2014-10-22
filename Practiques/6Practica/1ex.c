#include "../matriu.h"

int main (void)
{
	int n;
	double tol = 1e-4;
	double **A, *b, *p;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	A = GMM (n, n);
	SM (A, n, n);
	printf ("\nEl que has entrat mostrat:");
/* Copy past d'entrada manual */

	switch (palu (n, A, p, tol))
	{
	case -1:
		printf ("La matriu no se pot fer gauss.\nAlmenys amb PALU, segurament no es determinada amb una unica solucio.\n");
		break;
	case 0:
		printf ("Primera resolucio:\n");
		SM (A, n, n);
		SV (p, n);
	}

/* Alliberant memoria */
	FV (b, n);
	FM (A, n);
	return 0;
}
/*
Comprovar que fa correctament les coses, aixi que primer haure de fer un exemple manual, aixi podre fer anar el debbug i comprovar k tot es correcte
gcc nom.c -Wall -ansi --debug
gdb a.out
break palu
run
n
p i
*/
