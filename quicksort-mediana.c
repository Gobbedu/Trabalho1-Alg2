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

int *quicksort_mediana(vetor v, int a, int b){
	int m;
	int x;
	if (a>=b)
		return v;
	x=mediana(v[sorteia(a,b)],v[sorteia(a,b)],v[sorteia(a,b)]);
	for (int i = a; i <=b; ++i)
	{
		if (v[i]==x)
		{
			Troca(v,i,b);
			break;
		}
	}
	m=particiona(v,a,b,v[b]);
	quicksort(v,a,m-1);
	quicksort(v,m+1,b);
}



