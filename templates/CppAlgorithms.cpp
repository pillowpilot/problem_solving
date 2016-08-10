#include <iostream>
#include <algorithm>

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

/*
  sieve of eratostenes
  5761455 primes upto 1e8 in 2.9s
  664579 primes upto 1e7 in 0.29s
  78498 primes upto 1e6 in 0.029s

  needs
  typedef unsigned long long ull;
 */

int const MAXP = (int) 1e7; // 1e9 could produce MLE
bool primes[MAXP+1]; // +1 to include MAXP

void eratostenes(){
  fill(primes, primes+MAXP+1, true);  // needs <algorithm>
  
  primes[0] = primes[1] = false;
  ull index = 2; // ull for next line calculation
  while( index*index <= MAXP ){
    if( primes[index] == true ){
      int n = index * index;
      while( n <= MAXP ){
	primes[n] = false;
	n += index;
      }
    }
    index++;
  }
}


int main(){
  /*
    BEWARE!!
    untested algorithms... ^_^U

    except eratostenes
   */
  return 0;
}
