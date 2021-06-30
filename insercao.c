#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo m�todo da sele��o e devolve v */

int BuscaSimples(int x, int v[], int a, int b){
  while( compara(v[b], x) == 1 && b >= a)
    b--;
  return b;
}

int BuscaBina(int x, int v[], int a, int b){
        int m;
        m = (a + b)/2;
        
        if( a >= b ){
		if( compara(x, v[m]) == -1 )
			return m-1;
		return m;
	}
        
	if ( compara(x, v[m]) == 0 )
		return m;
	else if( compara(x, v[m]) == -1 )
                BuscaBina(x, v, a, m-1);
        else
                BuscaBina(x, v, m+1, b);
}

/* ==== insere v[b] no vetor ordenado v[a..b-1] ==== */
int *insere(int v[], int a, int b) {
  int p, i;

  p = BuscaBina(v[b], v, a, b-1);
  i = b;

  while( i > p+1 ){ /* empurra tudo para direita ao colocar v[b] */
    troca(v, i, i-1);
    i--;
  }

  return v;
}

int *insercao(int v[], unsigned int a, unsigned int b) {
  if( a >= b )
    return v;

  insercao(v, a, b-1);
  /* comeca com n = 1, e insere v[a+n] no vetor v[a..a+n] ; n++ */
  insere(v, a, b);
  return v;
}
