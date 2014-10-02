double BenMalCondicionat (double alpha, double x, double c) { return (alpha + 1/c) * exp (c * x) - 1/c; }


double FuntionY (double x) { return 1/2. * (exp (-2*x) + 1); }
double DirecteEstableInestable (double x, double h) { return (FuntionY (x + h) - FuntionY (x - h))/ 2*h; }// Derivable... no en faig res

/**
  * yn1 = y_{n-1}
  * yn = y_n
  * y_{n+1} = y_{n-1} + 2h (-2y_n +1)
  */
double RecurrentEstableInestable (double yn1, double yn, double h) { return yn1 + 2*h * (-2*yn + 1); }
