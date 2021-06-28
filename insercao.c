#include "biblioteca.h"

/* -------------------------------------------------------------------------- */
/* ordena v[a..b] pelo m�todo da sele��o e devolve v */

int BuscaSimples(int x, int v[], int a, int b){
  while( x > v[b] && b >= a)
    b--;
  return b;
}

int *insercao(int v[], unsigned int a, unsigned int b) {
  int p, i;

  p = BuscaSimples(v[b], v, a, b);
  i = b;

  while( i > p+1 ){
    troca(v, i, i-1);
    i--;
  }

  return v;
}
