/* Fa el producte entre matrius i/o vectors */

/*
   PMV	Producte entre matriu  vector
*/


/**
  * Producte de matriu amb vector Ax = b
  *
  * A, matriu m, n
  * x, vector n, 1
  * m, n, dimencions
  *
  * @return b, solucio m x 1
  * aparentment funciona correctament
  */
double *PMV (double **A, double *x, int m, int n)
{
	double *b = (double *) calloc (n, sizeof (double *));
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			b[i] += A[i][j] * x[j];
	return b;
}
