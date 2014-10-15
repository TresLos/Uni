/* Generador de vectors i matrius, aleatories o no. */
/*
   GMM	Genera Matriu manual
   GMA	Genera Matriu aleatoria
   GMH	Genera Matriu Hilbert
   GVM	Genera Vector manual
   GVA	Genera Vector aleatoria
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
  * Genera la matriu de Hilbert
  *
  * a_{i, j} = \frac{1}{i + j -1} \forall i, j = 1, 2, \ddots, n
  *
  * n es la dimencio desitjada
  */
double **GMH (int n) /* Correcte lo de malloc dit per la Julia Rosa */
{
	double **a = (double **) malloc (m * sizeof (double *));
	if (a == NULL)
	{
		printf ("Error en GMH, no hi ha espai 1");
		exit (1);
	}

	int i, j;
	for (i = 0; i < m; i++)
	{
		a[i] = (double *) malloc (n * sizeof (double));
		if (a == NULL)
		{
			printf ("Error en GMH, no hi ha espai 2");
			exit (1);
		}

		for (j = 0; j < n; j++)
			a[i][j] = 1./ (i + j + 1);
	}
	return a;
}
/**
  * Genera el vector de Hilbert, suposant cert que la matriu ja ho es de Hilbert
  *
  * b_i = \sum_{j=1}{n} a_{ij} \forall i = 1, 2, \ddots, n
  *
  * a es la matriu de Hilbert
  * n es la dimencio de la sortida i d'a
  */
double *GVH (double **a, int n)
{
	double *b = (double *) calloc (n * sizeof (double));
	if (b == NULL)
	{
		printf ("Errro en GVH, no hi ha espai.");
		exit (1);
	}

	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			b[i] += a[i][j];
	return b;
}
