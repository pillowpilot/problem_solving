#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull f(ull x, ull y, ull n){
  if( y == 1 ) return x % n;
  if( y % 2 == 0 ){
    ull r = f(x, y/2, n);
    return r*r % n;
  }else{
    ull r = f(x, y/2, n);
    return (r*r % n)*(x % n) % n;
  }
}

int main(){
  ull cases;
  scanf("%llu", &cases);
  while( cases-- > 0 ){
    ull x, y, n, r;
    scanf("%llu %llu %llu", &x, &y, &n);
    r = f(x, y, n);
    printf("%llu\n", r);
  }
  return 0;
}
