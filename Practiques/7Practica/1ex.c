
#define tol 1.e-10

int aluTridiag (int n, double *r, double *p, double *q)
{
	int k;

/* Fa A = LU */
	for (k = 0; k < n -1; k++)
	{
		if (fabs (p[k]) < tol)
		{
			printf ("\n|p[k]| < tol:\n%5le < %3le\nAixi que parem el programa\n");
			exit (1);
		}
		r[k] /= p[k];
		p[k +1] -= r[k] * q[k];
		y[k +1] -= r[k] * y[k]; /* Segon punt */
	}

/* Fa el 3 punt */
	y[k] /= p[n-1];
	for (k = n -2; k >= 0; k--)
		y[k] = (y[k] - q[k] * y[k +1]) / p[k];
}
