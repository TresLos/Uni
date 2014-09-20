#include <stdio.h>
#include <math.h>

int main (void)
{
	int i, tot = 1;
	for (i = 1; i < 36; i++)
	{
		tot *= i;
		printf ("%d\t%d\n", i, tot);
	}

	return 1;
}
