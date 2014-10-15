/* Resol incognites */
/*
   trisup	Soluciona una triangular superior Ux = b
   gauss	Soluciona una matriu cualsevol Ax = b
*/

/**
  * Et soluciona la matriu triangular superior
  *
  * Ux = b, troba  la x
  * n, dimencio de la matriu
  * U, matriu triangular superior
  * b, vector amb les solucions que vols trobar
  * tol, tolerancia que tindra el programa
  *
  * @param b, retorna la solucio desitjada
  * 1, diagonal < tol
  *-1, U no es triangular superior
  * 0, L'algoritme a sigut executat sense problemes
  */
int trisup (int n, double **U, double *b, double tol)
{
	int i, j;

	for (i = n -1; i >= 0; i--)
	{
		for (j = n -1; j > i; j--)
			b[i] -= U[i][j] * b[j];
		b[i] /= U[i][i];
	}

	return 0;
}
/**
  * Primer fa gauss i tot seguit fa la triangular superior
  *
  * Ax = b, troba la x
  *
  */
int gauss (int n, double **A, double *b, double tol)
{
	int k, i, j;
	double m;
	for (k = 0; k < n -1; k++)
	{
		if (fabs (A[k][k] < tol)) return -1;
		for (i = k +1; i < n; i++)
		{
			m = A[i][k] / A[k][k];
			A[i][k] = m;
			for (j = k +1; j < n; j++)
				A[i][j] -= m * A[k][j];
			b[i] -= m * b[k];
		}
	}
	/* Gauss esta acabat */
	return trisup (n, A, b, tol);
}
