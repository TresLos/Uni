#include <stdio.h>

// Epsilon de la m`aquina

int main (void)
{
	float u = 1, tu;// u = estudi, pero quedava llarg i diferent al enunciat
	while (u + 1 > 1)
	{
		tu = u;
		u /= 2;
	}
	printf ("\nFantastic:\t\t%.30f\n", tu);

	double v = 1, tv; // si la t inicial es de temporal
	while (v + 1 > 1)
	{
		tv = v;
		v /= 2;
	}
	printf ("\nFantastic:\t\t%.40le\n", tv);
	return 0;// si retorno 1, pensa el programa que ha petat... Flipant xD
}
