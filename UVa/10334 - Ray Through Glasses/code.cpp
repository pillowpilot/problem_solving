#include <cstdio>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull memob[1010];
ull memoc[1010];

ull b(int);
ull c(int);

ull b(int n){
  ull ans;
  if( memob[n] != 0 ) return memob[n];
  
  if( n == 0 ) ans = 1;
  else if( n == 1 ) ans = 2;
  else ans = c(n-1) + b(n-2);

  memob[n] = ans;

  return ans;
}

ull c(int n){
  ull ans;
  if( memoc[n] != 0 ) return memoc[n];
  
  if( n == 0 ) ans = 1;
  else if( n == 1 ) ans = 2;
  else ans = c(n-2) + b(n-1);

  memoc[n] = ans;

  return ans;
}

void build(){
  fill_n(memoc, 1010, 0);
  fill_n(memob, 1010, 0);

  memoc[0] = memob[0] = 1;
  memoc[1] = memob[1] = 2;
  c(1000);
  c(999);
}

int main(){
  int n;
  build();
  while( scanf("%d", &n) == 1 ){
    printf("%ld\n", memoc[n]);
  }
  return 0;
}

// Overflow! the sequence is the fibo sequence, ~1.6^1000 >> ull max
