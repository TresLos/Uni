#include <stdio.h>
#include <math.h>

#include "Vicent/Inestabilitat.h"

int main (void)
{
	FILE *f;
	f = fopen ("brosaEx2.gnuplot", "w");

	int n, nEnd = 300;
	double dx0 = 1, dx1 = 1/3.;
//	double directe, rM2, rM1;
//	float rM2, rM1;
	for (n = 0; n <= nEnd; n++)
	{
		fprintf (f, "%d\t%le\n", n, directe (n, dx0, dx1));
	}
	fclose (f);
	return 0;
}
// divide & conquer, algorismica
// http://prosa-msc.blogspot.com.es/2012/06/apuntes-matematicas-ub.html
