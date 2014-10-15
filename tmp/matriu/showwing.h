/* Mostra continguts */
/*
   SM	Mostra la matriu
   SV	Mostra el vector
*/

/**
  * Show matrix
  * m, files
  * n, columnes
  */
void SM (double **A, int m, int n)
{
	int i, j;
	printf ("\nShow matrix:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			printf ("%20.3lf", A[i][j]);
		printf ("\n");
	}
}
/**
  *
  *
  */
void SV (double *v, int n)
{
	int i;
	printf ("\nShow vector\n");
	for (i = 0; i < n; i++)
		printf ("%20.3lf", v[i]);
	printf ("\n");
}
