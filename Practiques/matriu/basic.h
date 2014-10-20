/* Generador de vectors i matrius, aleatories o no. */
/* Comprova que es */

/*
   GMM	Genera Matriu manual
   GMA	Genera Matriu aleatoria
   GMH	Genera Matriu de Hilbert
   GVM	Genera Vector manual
   GVA	Genera Vector aleatoria
   GV1	Genera Vector solucio 1

   FM	Allibera espai de memoria
   FV	El mateix pero per vectors

   CV	Copia el vector

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
			a[i][j] = 1./(i + j + 1);
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
	b = (double *) calloc (n, sizeof (double *));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			b[i] += A[i][j];
	return b;
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
  *
  * No cal coneixer la seva dimencio
  */
void FV (double *v)
{
	free (v);
}

/**
  * Copia el vector
  *
  * n, dimencio
  * v, el vector a copiar
  */
double * CV (int n, double *v)
{
	int i;
	double *a = (double *) malloc (n * sizeof (double *));

	for (i = n -1; i > -1; i--)
		a[i] = v[i];
	return a;
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
