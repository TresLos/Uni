#include <stdio.h>
#include <math.h>

int main (void)
{
	float a, b, c;
	scanf ("%f%f%f", &a, &b, &c);// Correcte
	float tmp = b*b - 4 * a * c;
	if (tmp > 0)
	{
		float x1 = (-b + sqrt (tmp)) / (2*a);
		float x2 = (-b - sqrt (tmp)) / (2*a);
		printf ("x_1 = %.60f\n", x1);
		printf ("x_2 = %.60f\n", x2);
		printf ("x_1 + x_2 = − b/a: (%.60f) = (%.60f)\n", x1+x2, -b/a);
		printf ("x_1 * x_2 = c/a: (%.60f) = (%.60f)\n", x1*x2, c/a);
	} else {return 1;}
	return 0;
}
// unic error trobat per ara 1 -6 6
