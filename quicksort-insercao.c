#include "insercao.h"
#include "particiona.h"


/* -------------------------------------------------------------------------- */
/* ordena v[a..b] usando o algoritmo QuickSort com inser��o e devolve v       */

int *quicksort_insercao(int v[], int a, int b, unsigned int m) {
  int aux; 

  /* BASE */
  if (a>=b)
    return v;

  aux = particiona(v,a,b,v[b]); /* ==> indice do pivo no vetor */

  /* === se tamanho particao <= m, usar insertion sort ==== */
  /* tamanho particao na esquerda eh (aux-1)-a +1 */
  if( aux-a <= m ){ insercao(v, a, aux-1); } 
  else { quicksort_insercao(v,a,aux-1, m); }

  /* tamanho particao na direita eh b-(aux+1) +1 */
  if( b-aux <= m ){ insercao(v, aux+1, b); }
  else { quicksort_insercao(v,aux+1,b, m);   }
  
  return v;
}
