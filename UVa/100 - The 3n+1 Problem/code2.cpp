#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll maxSize;
vi memo;

int len(ll n){
  if( maxSize < n ) maxSize = n;
  if( n < memo.size() && memo[n] != -1 ) return memo[n];
  if( n < memo.size() ){
    memo[n] = 1 + len( (n%2==0)?n/2:3*n+1 );
    return memo[n];
  }else return 1 + len( (n%2==0)?n/2:3*n+1 );
}

int main(){
  int i, j, m;
  memo = vi(1e6, -1);
  memo[1] = 1; // Caso base!
  maxSize = 1;

  while( scanf("%d %d", &i, &j) == 2 ){
    printf("%d %d ", i, j);
    if(i>j)swap(i, j);                               // j puede ser menor a i, y buscamos en [j, i]
    m = 1;
    for(int k = i; k <= j; k++) m = max(m, len(k));  // i = j -> [i, j] = {i} = {j}
    printf("%d\n", m);
  }
  //printf("%ld\n", maxSize);
  return 0;
}

// AC (0.013s)
