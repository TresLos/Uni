#include <stdio.h>
#include <math.h>

int main (void)
{
	int NIUB, i, n;
	double a, y;

	n = 20; /* Recurencies */
	NIUB = 16237555;
	a = 2 + NIUB/1.e8;
	y = a - 1; /* Valor inicial */

	printf ("\ny_0 = %.6le\n", y);

	for (i = 1; i <= n; i++)
	{
		y = a * pow (log (a), i) - i * y;
		printf ("\n%2d => %.6le", i, y);
	}

	printf ("\ny_n = %.6le\n", y);

	return 0;
}
