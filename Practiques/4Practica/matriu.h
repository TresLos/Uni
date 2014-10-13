/* es tan majo que ja ho fa tot ell mateix :) */
#include <stdlib.h>
#include <stdio.h>

/* Les llibreries que he anat fent al llarg del temps */
#include "matriu/generator.h"
#include "matriu/producter.h"

/*
   GMM	Genera Matriu manual
   GMA	Genera Matriu aleatoria
   GVM	Genera Vector manual
   GVA	Genera Vector aleatoria

   PMV	Producte entre matriu  vector
*/
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

	for (i = n -1; i >= 0; i--)
	{
		for (j = n -1; j > i; j--)
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
/***********************************************************************************************************************/
/************************************END*********SHOWWING***************************************************************/
/***********************************************************************************************************************/
