#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull f(ull n, ull k){
  if( n < k ) return 0;
  else return n / k + f(n / k + n % k, k);
}

int main(){
  ull n, k;
  while(scanf("%llu %llu", &n, &k) == 2){
    printf("%llu\n", f(n*k, k));
  }
  return 0;
}
