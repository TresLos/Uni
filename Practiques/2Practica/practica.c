#include <stdio.h>
#include <math.h>

#include "magia.h"

int main (void)
{
// Valors que donem per a operar per comenzar
	int i, n = 50;
	double x0 = 1, x1 = 1/3.;

	double xDirecte, xDoubleRecursiu = x1, xDoubleRecursiu1 = x0, xDoubleTmp;
	float xFloat = (float) x1, xFloat1 = (float) x0, xFloatTmp;

	double errorAbsolutDdoubleRecursiu, errorRelatiuDoubleRecursiu;
	float errorAbolutFloatRelatiu, errorRelatiuFloatRecursiu;

	printf ("   i   Directe               Float               Err Abs               Err Relatiu               Double               Err Abs               Err Relatiu\n");

	for (i = 0; i < n; i++)
	{
		xDirecte = DoubleDirecte (i, x0, x1);

		xDoubleTmp		= DoubleRecursiu (xDoubleRecursiu, xDoubleRecursiu1);
		xDoubleRecursiu1	= xDoubleRecursiu;
		xDoubleRecursiu		= xDoubleTmp;
		errorAbsolutDdoubleRecursiu	= xDoubleRecursiu - xDirecte;
		errorRelatiuDoubleRecursiu	= errorAbsolutDdoubleRecursiu / xDirecte;

		xFloatTmp		= FloatRecursiu (xFloat, xFloat1);
		xFloat1			= xFloat;
		xFloat			= xFloatTmp;
		errorAbolutFloatRelatiu	= xFloat - xDirecte;
		errorRelatiuFloatRecursiu	= errorAbolutFloatRelatiu / xDirecte;

		printf ("%3d   %15.10le     %15.10le     %15.10le     %15.10le     %15.10le     %15.10le     %15.10le\n", i, xDirecte, xFloat, errorAbolutFloatRelatiu, errorRelatiuFloatRecursiu, xDoubleRecursiu, errorAbsolutDdoubleRecursiu, errorRelatiuDoubleRecursiu);
	}
	return 0;
}
