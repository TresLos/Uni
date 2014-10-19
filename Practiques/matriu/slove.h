/* Soluciona certs problemes plantejats */

/*
   trisup	Soluciona una triangular superior // No fa cap comprovacio, mes que la diagonal. ISTS, per a saber si es Triangular superior
   gauss	Soluciona una matriu amb gauss, per fer // A = LU // det, Trisup, ...
*/

/**
  * Et soluciona la matriu triangular superior de forma directa
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
  *
  * Altament testejat, fa exactament les operacions desitjades
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
  * Fa gauss i soluciona els multiplicants a la mateixa matriu, on anirien els zeros
  *
  * n, dimencio de la matriu
  * A, matriu
  * b, vector a solucionar
  * tol, tolerancia
  *
  * Return
  * 0, tot correcte
  * -1, la diagonal ha quedat nula, no se pot solucionar per gauss
  *
  * EM detectat l'error, i el problema surgueix del metode, no pas dels calculs
  * ara no ho se corregir.
  */
int gauss (int n, double **A, double *b, double tol)
{
	int k, i, j;
	double m;

	for (k = 0; k < n -1; k++)
	{
		if (A[k][k] < tol)
		{
			printf ("Peta pq ha quedat una matriu que no sabem fer gauss sense pivotatge.\n");
			exit (-1);
		}
		for (i = k +1; i < n; i++)
		{
			m = A[i][k] / A[k][k];
			b[i] -= m * b[k];
			A[i][k] = m;
			for (j = k +1; j < n; j++)
				A[i][j] -= m * A[k][j];
		}
	}

	return 0;
}
