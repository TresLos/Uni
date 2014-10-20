/* es tan majo que ja ho fa tot ell mateix :) */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Les llibreries que he anat fent al llarg del temps */
#include "matriu/basic.h"
#include "matriu/binaryOperation.h"
#include "matriu/slove.h"

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

   PMV	Producte entre matriu  vector
   RVV	Resta entre vector vector

   trisup	Soluciona una triangular superior // No fa cap comprovacio, mes que la diagonal. ISTS, per a saber si es Triangular superior
   gauss	Soluciona una matriu amb gauss, per fer // A = LU // det, Trisup, ...


pendents:
   PMM Producte entre matriu i matriu
   TSI Soluciona una triangular superior de forma indirecte "recurrent", cada reiteracio millora l'aproximacio
*/
