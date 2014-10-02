#include <stdio.h>
#include <math.h>

#include "magia.h"

int main (void)
{
	int N = pow (10, 6);
	double h = 1./N;
// Solucions
	double y10 = FuntionY (10);
	double y0 = 1;
	double y1 = FuntionY (h);
	double tmpY;

// Nomes vull veure 50 resultats
	int vista = N/pow (10, 5);

	int i;
	for (i = 2; i < N; i++)
	{
		tmpY = RecurrentEstableInestable (y0, y1, h*i);
		y0 = y1;
		y1 = tmpY;
		if (i % vista == 0)
			printf ("\n%15.10le:   %15.20le", h*i, y10 - y1);
		if (y1 > 1.e50)
			return 1;
	}

	return 0;
}
/** Efectua curva estranya
  * Quan val: 2.6900000000e-03:   -9.09704156915047690291e-06
  * es el minim de la funcio, quan mes presisa es, pero de cop, la precicio desapareix i creix rapidament fins a inf
  */

