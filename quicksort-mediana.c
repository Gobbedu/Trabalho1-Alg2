#include "particiona.h"

/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */

static int mediana(int a, int b, int c) {
	int x;

	if (a<=b)
		if (a<=c)
			if (b<=c)
				x=b;
			else
				x=c;
		else
			x=a;
	else
		if (a<=c)
			x=a;
		else
			if (b<=c)
				x=c;
			else
				x=b;
  return x;
}

/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b) {
	int m;
	if (a>=b)
		return v;
	m=particiona(v,a,b,mediana(v[sorteia(a,b)],v[sorteia(a,b)],v[sorteia(a,b)]));
	quicksort_mediana(v,a,m-1);
	quicksort_mediana(v,m+1,b);	 
  return v;
}



