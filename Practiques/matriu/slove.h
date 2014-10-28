/* Soluciona certs problemes plantejats */
/* Pre passos a fer per a trobar les solucions */

/*
   PreTrisup	Dona tots els errors possibles abans d'efectuar la triangular superior

   trisup	Soluciona una triangular superior // No fa cap comprovacio, mes que la diagonal. ISTS, per a saber si es Triangular superior
   triinf	Soluciona una triangular inferior // Suposa la diagonal 1 //
   gauss	Canvia una matriu amb gauss, per fer // A = LU // det, Trisup, inversa, ...
   palu		Canvia una matriu amb gauss, per fer //PA = LU // ...

   Norm		Dona la norma infinita: || x ||_\inf
*/

/**
  * Possibles errors abans d'executar la trianguar superior
  *
  * n, es la dimencio de la matriu
  * a, es la matriu
  * t, es la tolerancia
  *
  * Return
  * 0, tot correcte
  * 1, no es triangular superior
  * -1, no es pot aplicar el trisup, ja que te la diagonal nula.
  */
int PreTrisup (int n, double **a, double tol) /* No ha sigut testejat */
{
	int i, j;

	for (i = 0; i < n; i++)
		if (a[i][i] < tol)
			return -1;/* Diagonal */
	for (i = 0; i < n; i++)
		for (j = i; j >= 1; j--)
			if (a[i][j] < tol)
				return 1;/* Triangular superior */
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
  * Triangular superior en forma L
  *
  * L = Matriu inferior amb diagonal = Id.
  * aixi que no cal fer la divisio
  *
  * n, dimencio
  * L, matriu
  * b, vector
  *
  * b, es el vector amb el resultat desitjat
  */
void triinf (int n, double **L, double *b)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			b[i] -= L[i][j] * b[j];
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
  * Vercio corregida (que la entrada era erronia)
  * ara tot funciona com hauria :)
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
			return -1;
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

		if (A[k][k] < tol)
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
  * Un cop efectuat PA = LU, Ax = b, troba x
  *
  * n, dimencio
  * A, matriu
  * b, vector donat
  * p, permutacions
  *
  * x, sortida desitjada
  * 0, tot correcte
  * -1, IMPOSSIBLE continuar
  */
int resol (int n, double **A, double *b, double *x, int **pi, double tol)
{
	int i;
	double v; /* per fer permutacions a la b */
	int *p;

	p = GVN (n);
/* Reordenem la b, per tal que sigui la mateixa que LU */
	for (i = 0; i < n; i++)
	{
		v = b[i];
		b[i] = b[p[i]];
		b[p[i]] = v;
	}

/* Tinc dubtes de que el for anterior estigui gaire correcte */

	x = CV (n, b);

	triinf (n, A, x);

	if (PreTrisup (n, A, tol) == -1)
	{
		printf ("Impossible continuar, diagonal zero.\n");
		return -1;
	}

	trisup (n, A, x, tol);

	*pi = p;
	return 0;
}
/* Plantejament 2 de resol, no he testejat l'anterior, aixi de liante soc jo xD */
int resolGauss (int n, double **A, double *b, double *x, int *p, double tol)
{
	int i, k;
	double *tp; /* nomes son per a fer permutacions */

/* Calculem el valor real de b */
	/* Primer permutem b */
	tp = (double *) malloc (n * sizeof (double *));
	for (i = 0; i < n; i++)
		tp[i] = b[p[i]];
	free (b);
	b = tp;
	/* Ara ja podem sumar valors a b */
	for (k = 0; k < n -1; k++)
		for (i = k +1; k < n; i++)
			b[i] -= A[i][k] * b[k];
/* Aqui representa que ja puc fer la trisuperior normal */
	return trisup (n, A, b, tol);
}
/**
  * Norma
  *
  * || ||_\inf = max | |.
  */
double Norm (int n, double *v)
{
	double tmp = fabs (v[0]);
	int i;

	for (i = 1; i < n; i++)
		if (fabs (v[i]) > tmp)
			tmp = fabs(v[i]);
	return tmp;
}
