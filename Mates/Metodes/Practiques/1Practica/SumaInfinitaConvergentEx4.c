#include <stdio.h>

void lola (int i)
{
	float u = 1/ (float) i;
	int tmpI = i;
	while (--i > 0)
		u += 1/ (float) i;
	printf ("2n:\t%d\t%.30f\n", tmpI, u);
}

int main (void)
{
	int i = 1;
	float u = 1;
	while (u + 1/ (float) i > u)
		u += 1/ (float) i++;
	printf ("\n1er:\t%d\t%.30f\n", i, u);

	lola (i);
	lola (2*i);
	return 0;
}
