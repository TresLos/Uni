#include <stdio.h>
#include <math.h>

int main (void)
{
	int i = 0;
	while (i > i - 3)
		i--;

	printf ("%d\n", i--);
	printf ("%d\n", i--);
	printf ("%d\n", i--);
	printf ("%d\n\n", i);
	return 1;
}
// %s/+/-/g de max.c
/*
-2147483646
-2147483647
-2147483648
2147483647
*/
