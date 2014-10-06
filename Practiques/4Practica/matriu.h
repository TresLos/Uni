/**
  * reclama de:
  * #include <stdlib.h>
  * #include <stdio.h>
  *
  */

/***********************************************************************************************************************/
/*********************************************GENERATOR*****************************************************************/
/***********************************************************************************************************************/
/**
  * Genera la Matriu de forma Manual
  *
  * m, files
  * n, columnes
  */
double **GMM (int m, int n)
{
	double **a = (double **) malloc (m * sizeof (double *));
	int i, j;
	for (i = 0; i < m; i++)
	{
		a[i] = (double *) malloc (n * sizeof (double *));
		for (j = 0; j < n; j++)
			scanf ("%le" , &a[i][j]);
	}
	return a;
}
/**
  * Genera una matriu aleatoria
  *
  * max, el valor maxim de la matriu
  * min, " minim
  * e, la matriu que generarem "teoricament aqui sense inicialitzar
  * m, files
  * n, columnes
  *
  * rand => |max - min| rand ()/ RAND_MAX + min
  */
void GMA (double max, double min, double ***e, int m, int n)
{
	double **a = (double **) malloc (m * sizeof (double *)); // no faltaria un *?
	int i, j;
	max *= 10; // no entenc el perque els necessito.
	min *= 10; // sense ells no obtinc el resultat desitjat
	for (i = 0; i < m; i++)
	{
		a[i] = (double *) malloc (n * sizeof (double *));
		for (j = 0; j < n; j++)
			a[i][j] = (fabs (max - min) * rand ()) / (double) RAND_MAX + min;
	}
	*e = a;
}
/**
  * Genera un vector aleatori
  * max, valor maxim
  * min, valor minim
  * e, vector que generem, "teoricament sense inicialitzar"
  * n, files (nx1)
  */
void GVA (double max, double min, double **e, int n)
{
	int i;
	max *= 10;
	min *= 10;
	double *a = (double *) malloc (n * sizeof (double *));
	for (i = 0; i < n; i++)
		a[i] = (fabs (max - min) * rand ()) / (double) RAND_MAX + min;
	*e = a;
}
/***********************************************************************************************************************/
/*********************************************GENERATOR**********END****************************************************/
/***********************************************************************************************************************/

/***********************************************************************************************************************/
/**********************************************PRODUCTER****************************************************************/
/***********************************************************************************************************************/
/**
  * Producte de matriu amb vector Ax = b
  * A, matriu m, n
  * x, vector n, 1
  * m, n, dimencions
  * b, vector sortida m, 1
  * @return resultat del producte
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
/***********************************************************************************************************************/
/***************************END****************PRODUCTER****************************************************************/
/***********************************************************************************************************************/

/***********************************************************************************************************************/
/***********************************************SLOVE*******************************************************************/
/***********************************************************************************************************************/

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

	for (i = n; i < n; i--)
	{
		for (j = n; j < i; j--)
			b[i] -= U[i][j] * b[j];
		b[i] /= U[i][i];
	}

	return 0;
}

/***********************************************************************************************************************/
/***********************************END*********SLOVE*******************************************************************/
/***********************************************************************************************************************/

/***********************************************************************************************************************/
/************************************************SHOWWING***************************************************************/
/***********************************************************************************************************************/
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
			printf ("%20.3le", A[i][j]);
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
		printf ("%20.3le", v[i]);
	printf ("\n");
}
/***********************************************************************************************************************/
/************************************END*********SHOWWING***************************************************************/
/***********************************************************************************************************************/
