#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

vi frec;
vi marbles;

void init(){
  frec.reserve( 10474 );
  marbles.reserve( 10474 );
}

void initPerCase(){
  frec = vi(10474, 0); //Init all to zero
  marbles.clear();
}

int main(){
  int cases = 1, n, q;
  
  init();
  while( scanf("%d %d", &n, &q) == 2 && n != 0 && q != 0 ){
    initPerCase();
    
    while( n-- > 0 ){
      int id;
      scanf("%d", &id);
      frec[id]++;
    }
    for( vi::iterator iter = frec.begin();  iter != frec.end(); iter++ ){
      while( (*iter)-- > 0 ){
	marbles.push_back(iter - frec.begin());
      }
    }
    printf("CASE# %d:\n", cases++);
    while( q-- > 0 ){
      int query;
      scanf("%d", &query);
      vi::const_iterator pos = lower_bound( marbles.begin(), marbles.end(), query );
      if( pos == marbles.end() || *pos != query ){
	printf("%d not found\n", query);
      }else{
	printf("%d found at %ld\n", query, pos - marbles.begin() + 1);
      }
    }
  }
  return 0;
}


/*
  Existe un metodo mas eficiente. O(n) + O(n) + O(q) <= 2*10^4 + q
  1. Cargar la tabla de frecuencias. // Leer x y frec[x]++
  2. Cargar el vector data tal que ( data[x] = 0 si frec[x] = 0 ) y ( data[x] = data[y] + frec[y] donde y es el elemento anterior a x que posee frec[y] != 0 y el primero es 1). 
Asi la entrada <1, 1, 3, 5, 7, 1, 3, 9, 12, 1> genera frec[x] = [0, 4, 0, 2, 0, 1, 0, 1, 0, 1, 0, 0, 1] y data[x] = [0, 1, 0, 5, 0, 7, 0, 8, 0, 9, 0, 0, 10].
 */
