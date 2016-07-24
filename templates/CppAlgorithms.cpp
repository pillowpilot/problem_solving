#include <iostream>

using namespace std;

typedef unsigned long long ull;

/*
  Fast exponentiation mod (recursive)
 */
ull m=(ull)1e9+7;
ull fexpr(ull b, ull e){
  if(e==0)
    return 1;
  ull p=fexpr(b, e/2);
  p*=p;
  p%=m;
  if(e%2==1){
    p*=b;
    p%=m;
  }
  return p;
}

/*
  factorial mod m (recursive)
 */
ull facr(ull n){
  if(n==0) return 1;
  ull f=facr(n-1);
  f=f*(n%m)%m;
  return f;
}

/*
  binomial coef mod m (m is prime)
  based on factorial mod m (recursive) and pow mod m (recursive)
 */
ull bc(ull n, ull k){
  if(n<k)return 0;
  ull nf=facr(n);
  ull kf=facr(k);
  ull nkf=facr(n-k);
  ull kfi=fexpr(kf, m-2);
  ull nkfi=fexpr(nkf, m-2);
  return nf*kfi%m*nkfi%m; // (operator precedence) *=/=% (left-right)
}


int main(){
  /*
    BEWARE!!
    untested algorithms... ^_^U
   */
  return 0;
}
