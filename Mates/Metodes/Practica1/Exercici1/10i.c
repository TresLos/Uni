#include <stdio.h>
#include <math.h>

int main (void)
{
	int i;
	for (i = 1; i < 15; i++)
		printf ("%d\t%d\n" ,i, (int) pow (10, i));

	printf ("Altra forma\n\n");
	int tot = 1;
	for (i = 1; i < 15; i++)
	{
		tot *= 10;
		printf ("%d\t%d\n", i, tot);
	}
	return 1;
}
