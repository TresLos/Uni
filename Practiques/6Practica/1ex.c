#include "../matriu.h"

/* Testejat per:
3
7 2 5
8 4 3
1 12 6
Funciona millor del esperat "m'ha superat a mi"
Tot correcte aparentment
*/

int main (void)
{
	int n, *p;
	double tol = 1e-4;
	double **A;
	printf ("Entri dim de la matriu:\n");
	scanf ("%d", &n);
	printf ("\nEntri la matriu:\n");
	A = GMM (n, n);
	SM (A, n, n);
	printf ("\nEl que has entrat mostrat:");
/* Copy past d'entrada manual */

	switch (palu (n, A, &p, tol))
	{
	case -1:
		printf ("La matriu no se pot fer gauss.\nAlmenys amb PALU, segurament no es determinada amb una unica solucio.\n");
		break;
	case 0:
		printf ("Primera resolucio:\n");
		SM (A, n, n);
		SVI (p, n);
	}

/* Alliberant memoria */
	FVI (p);
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
