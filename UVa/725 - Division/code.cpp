#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef list<vi> lvi;
typedef vector<lvi> vlvi;

vlvi memo;

int numerator(const vi& d){
  int multiplicator = 1, value = 0;
  for( int i = 4; 0 <= i; i-- ){
    value += d[i]*multiplicator;
    multiplicator *= 10;
  }
  return value;
}

int denominator(const vi& d){
  int multiplicator = 1, value = 0;
  for( int i = 9; 5 <= i; i-- ){
    value += d[i]*multiplicator;
    multiplicator *= 10;
  }
  return value;
}

void init(){
  vi d{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  memo = vlvi(100, lvi());

  do{
    int num = numerator( d );
    int den = denominator( d );
    int quotient = num / den;
    int remainder = num % den;
    if( remainder == 0 ){
      memo[quotient].push_back( d );
    }
  }while( next_permutation(d.begin(), d.end()) == true );
  
  /*auto iter = memo.begin();
  while( iter != memo.end() ){
    if( ! iter->empty() ){
      printf("%ld (%ld)\n", iter - memo.begin(), iter->size());
    }
    iter++;
  }*/
}

void printList(int q){
  lvi::const_iterator iter = memo[q].begin();
  while( iter != memo[q].end() ){
    for( int i = 0; i < 5; i++ ){
      printf("%d", iter->at(i));
    }
    printf(" / ");
    for( int i = 5; i < 10; i++ ){
      printf("%d", iter->at(i));
    }
    printf(" = %d\n", q);
    iter++;
  }
}

int main(){
  int q;

  init(); // Solo son 300 permutaciones las cuales cumplen la condicion (division exacta)
  scanf("%d", &q);
  while( q != 0 ){
    if( !memo[q].empty() ){
      printList(q);
    }else{
      printf("There are no solutions for %d.\n", q);
    }
    scanf("%d", &q);
    if( q != 0 ) printf("\n");
  }
  return 0;
}
