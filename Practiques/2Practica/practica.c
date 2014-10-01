#include <stdio.h>
#include <math.h>

int main (void)
{
	int i;
	double xDirecte, xDoubleRecursiu, xDoubleRecursiu1;
	float xFloat, xFloat1;
	double errorAbolutFloatRelatiu, errorRelatiuFloatRecursiu, errorAbsolutDdoubleRecursiu, errorRelatiuDoubleRecursiu;
	for (i = 0; i < 30; i++)
	{
		
		printf ("%3d\t%15.10le\t%15.10lf\t%15.10le\t%15.10le\t%15.10le\t%15.10le\t%15.10le\n", i, xDirecte, xFloat, errorAbolutFloatRelatiu, errorRelatiuFloatRecursiu, xDoubleRecursiu, errorAbsolutDdoubleRecursiu, errorRelatiuDoubleRecursiu);
	}
	return 0;
}
