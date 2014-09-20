#include <stdio.h>
#include <math.h>

int main (void)
{
	float Flot;
	double Dobl;
	printf ("Float\t\tDouble");
	while (1)
	{
		scanf ("%f", &Flot);
		scanf ("%le", &Dobl);
		printf ("%.20f\t\t%.20le\n", Flot, Dobl);
	}
	return 1;
}
