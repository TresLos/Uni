/* Generador de vectors i matrius, aleatories o no. */
/* Comprova que es */

/*
   GMM	Genera Matriu manual
   GMA	Genera Matriu aleatoria
   GMH	Genera Matriu de Hilbert
   GVM	Genera Vector manual
   GVA	Genera Vector aleatoria
   GV1	Genera Vector solucio 1

   PreTrisup	Dona tots els errors possibles abans d'efectuar la triangular superior

   FM	Allibera espai de memoria
   FV	El mateix pero per vectors

   SM	Mostra la matriu
   SV	Mostra el vector
*/


/**
  * Genera la Matriu de forma Manual
  *
  * m, files
  * n, columnes
  *
  * @param Matriu creada manualment
  * aparentment funciona correctament
  */
double **GMM (int m, int n)
{
	double **a = (double **) malloc (m * sizeof (double *));
	if (a == NULL)
	{
		printf ("Error en GMM, no hi ha espai");
		exit (1);
	}

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
  * Genera el Vector de forma Manual
  *
  * n x 1
  * Crec que es correcte dir-ho aixi
  *
  * @param Vector creat manualment
  * aparentment funciona correctament
  */
double *GVM (n)
{
	double *a = (double *) malloc (n * sizeof (double *));
	int i;
	for (i = 0; i < n; i++)
		scanf ("%le", &a[i]);
	return a;
}
/**
  * Genera una matriu aleatoria
  *
  * max, el valor maxim de la matriu
  * min, " minim
  * e, la matriu que generarem "teoricament aqui sense inicialitzar // &Matriu
  * m, files
  * n, columnes
  *
  * rand => |max - min| rand ()/ RAND_MAX + min
  * aparentment funciona correctament
  * fa magia, desconec el motiu de multiplicar per 10
  */
void GMA (double max, double min, double ***e, int m, int n)
{
	double **a = (double **) malloc (m * sizeof (double *)); /* no faltaria un * */
	int i, j;
	max *= 10; /* no entenc el perque els necessito. */
	min *= 10; /* sense ells no obtinc el resultat desitjat */
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
  *
  * max, valor maxim
  * min, valor minim
  * e, vector que generem, "teoricament sense inicialitzar" // &Vector
  * n, files (n x 1)
  * aparentment funciona correctament
  * fa magia, desconec el motiu de multiplicar per 10
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
/**
  * Genera una matriu de Hilbert
  *
  * n, dimencio
  */
double **GMH (int n)
{
	int i, j;
	double **a;

	a = (double **) malloc (n * sizeof (double *));
	for (i = 0; i < n; i++)
	{
		a[i] = (double *) malloc (n * sizeof (double *));
		for (j = 0; j < n; j++)
			a[i][j] = 1/(i + j + 1);
	}
	return a;
}

/**
  * Genera el vector pq tingui solucio 1.
  *
  * A, matriu que vols solucio 1
  * n, dimencio
  */
double *GV1 (int n, double **A)
{
	int i, j;
	double *b;
	b = (double *) calloc (n * sizeof (double *));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			b[i] += A[i][k];
	return b;
}

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
	{
		if (a[i][i] < tol)
			return -1;/* Diagonal */
		for (j = i; j >= 1; j--)
			if (a[i][j] < tol)
				return 1;/* Triangular superior */
	}
	return 0;
}

/**
  * Free matrix
  *
  * a, matrix
  * m, files
  */
void FM (double **a, int m) /* Les columnes no interessent aparentment */
{
	int i;

	for (i = 0; i < m; i++)
		free (a[i]);
	free (a);
}

/**
  * Free vector
  */
void FV (double *v, int n)
{
	free (v);
}

/**
  * Show matrix
  *
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
  * Mostra el vector
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
