#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
  * Mostra el vector
  *
  */
void SV (double *v, int n)
{
	int i;
	printf ("\nShow vector\n");
	for (i = 0; i < n; i++)
		printf ("%20.6lf", v[i]);
	printf ("\n");
}
void SVI (int *v, int n)
{
	int i;
	printf ("\nShow vector\n");
	for (i = 0; i < n; i++)
		printf ("%7d", v[i]);
	printf ("\n");
}
/* Genera la matriu */
double ** GM (int n, double a)
{
	int i;
	double **A;
	
	A = (double **) malloc (n * sizeof (double *));
	if (A == NULL)
	{
		printf ("\nError en generar la matriu, no hi ha espai.\n");
		exit (1);
	}
	for (i = 0; i < n; i++)
	{
/* Ho faig amb calloc per no tenir que pensar amb tots els zeros a omplir */
		A[i] = (double *) calloc (n, sizeof (double *));
		if (A[i] == NULL)
		{
			printf ("\nError en generar la matriu, no hi ha espai.\n");
			exit (2);
		}
	}

/* Omplo la matriu */
	for (i = 0; i < n; i++)
		A[i][i] = a;
	for (i = 0; i < n -1; i++)
	{
		A[i][i +1] = a + i;
		A[i +1][i] = a + i;
	}
	for (i = 0; i < n -2; i++)
	{
		A[i][i +2] = a - i;
		A[i +2][i] = a - i;
	}
	return A;
}

/* Genera el vector */
double * GV (int n, double K)
{
	int i;
	double *b;

	b = (double *) malloc (n * sizeof (double *));
	if (b == NULL)
	{
		printf ("\nError en generar el vector, no hi ha espai.\n");
		exit (1);
	}

	for (i = 0; i < n; i++)
		b[i] = K;
	return b;
}
/**
  * Factoritzacio PA = LU
  *
  * n, dimencio
  * A, canviarem per LU
  * p, permutacio "P"
  * tol, tolerancia
  *
  * 0, tot correcte
  * 1, a la diagonal hi ha un element nul
  */
int palu (int n, double **A, int *p, double tol)
{
	int k, i, j;
	double m;
	double *tv; /* per buscar els maxims */

	for (k = 0; k < n -1; k++)
	{
/* Busquem el maxim // Fixeu-vos, m, j i i son variables k ja defineixo mes tard correctament // */
		m = fabs (A[k][k]);
		j = k;
		for (i = k +1; i < n; i++)
			if (fabs (A[i][k]) > m)
			{
				m = fabs (A[i][k]);
				j = i;
			}
		tv = A[k];
		A[k] = A[j];
		A[j] = tv;

		i = p[k];
		p[k] = p[j];
		p[j] = i;
/* Ja tenim el maxim, gauss normal */
		SVI (p, n);

		if (fabs (A[k][k]) < tol)
		{
			printf ("Peta pq ha quedat una matriu que no sabem fer gauss fins i tot amb pivotatge 'no existeix'.\n");
			return -1;
		}
		for (i = k +1; i < n; i++)
		{
			m = A[i][k] / A[k][k];
			A[i][k] = m;
			for (j = k +1; j < n; j++)
				A[i][j] -= m * A[k][j];
		}
	}
	return 0;
}
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
  * Un cop efectuat PA = LU, Ax = b, trobar x
  *
  * n, dimencio
  * A, matriu
  * b, vector donat
  * p, permutacions
  *
  * 0, tot correcte
  * -1, IMPOSSIBLE continuar
  */
int resol (int n, double **A, double **bi, int *p, double tol)
{
	int i, k;
	double *tp, *b = *bi; /* nomes son per a fer permutacions */

/* Calculem el valor real de b */
	/* Primer permutem b */
	tp = (double *) malloc (n * sizeof (double *));
	for (i = 0; i < n; i++)
		tp[i] = b[p[i]];
	free (b);
	b = tp;
	/* Ara ja podem sumar valors a b */
	for (k = 0; k < n -1; k++)
		for (i = k +1; i < n; i++)
			b[i] -= A[i][k] * b[k];
/* Aqui representa que ja puc fer la trisuperior normal */
	*bi = b;
	return trisup (n, A, b, tol);
}

int main (void)
{
	int NIUB, n, *p, i;
	double a, **A, *b, tol;

	n = 6;
	NIUB = 16237555;
	tol = 1.e-10;
	a = NIUB/1.e6;
	A = GM (n, a);
	b = GV (n, 100);

	printf ("\nValor de a = %.6le\n", a);

/* Calculo p */
	p = (int *) malloc (n * sizeof (int *));
	if (p == NULL)
	{
		printf ("\nNo hi ha memoria per a Generar p de permutacions\n");
		exit (1);
	}
	for (i = 0; i < n; i++)
		p[i] = i;

/* Programa en si */
	if (palu (n, A, p, tol) == 1)
	{
		printf ("\nDiagonal te element neutre\n");
		exit (1);
	}

	printf ("\nDeterminant\n");
	a = 1;
	for (i = 0; i < n; i++)
		a *= A[i][i];
	printf ("det A = %.5le\n", a);

	if (resol (n, A, &b, p, tol) == -1)
	{
		printf ("\nNo ha pogut continuar el resol\n");
		exit (1);
	}

	printf ("\nSolucio de x:\n");
	SV (b, n);

	free (p);
	free (b);

	for (i = 0; i < n; i++)
		free (A[i]);
	free (A);
	return 0;
}
