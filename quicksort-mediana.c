#include "particiona.h"
#include "biblioteca.h"


/* -------------------------------------------------------------------------- */
/* devolve a mediana de a, b e c                                              */

static int mediana(int a, int b, int c) { //Árvore de comparações para achar o elemento mediano
	int x;	
	if (compara(b,a)==1)
		if (compara(c,a)==1)
			if (compara(c,b)==1)
				x=b;
			else
				x=c;
		else
			x=a;
	else
		if (compara(c,a)==1)
			x=a;
		else
			if (compara(c,b)==1)
				x=c;
			else
				x=b;
  return x;
}
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* ordena v[a..b]  usando o algoritmo  "QuickSort com mediana de  3" e
   devolve v                                                                  */

int *quicksort_mediana(int v[], int a, int b){
	int m;
	int x;
	if (a>=b)
		return v;
	x=mediana(v[sorteia(a,b)],v[sorteia(a,b)],v[sorteia(a,b)]); //Gera 3 índices aleatórios do vetor e passa os seus elementos como argumento para a função mediana
	for (int i = a; i <=b; ++i)
	{
		if (compara(x,v[i]==0))
		{
			troca(v,i,b); //Garante que o pivô sempre estará no último índice para asseguar o funcionamento da função particiona
			break;
		}
	}
	m=particiona(v,a,b,v[b]);
	quicksort_mediana(v,a,m-1);
	quicksort_mediana(v,m+1,b);
}


