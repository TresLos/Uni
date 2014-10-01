double DoubleRecursiu	(double xn1, double xn2)	{ return 10./3 * xn1 - xn2; }
float FloatRecursiu	(float xn1, float xn2)		{ return 10./3 * xn1 - xn2; }

double DoubleDirecte (int n, double x0, double x1) { return 3/8. * (3 * x0 - x1) * pow (1/3., n) + 1/8.*(3*x1 - x0)*pow(3,n); }
// Realment voldria arrivar a comprovar aixo de d'aquesta igualtat. Perque em molesta molt no aconseguiro
