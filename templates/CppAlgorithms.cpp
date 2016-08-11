#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
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

/*
  Fibonacci in O(lg^2(n))
  using identity
  |1 1|n  |f_n+1 f_n  |
  |1 0| = |f_n   f_n-1|
  which implies
  f(2n+1) = f(n+1)^2 + f(n)^2    (odd  n)
  f(2n)   = f(n)*(f(n+1)+f(n-1)) (even n)
  needs ull m=(ull)1e9+7;
 */
typedef map<ull, ull> muu;

muu dp;

ull f(ull n){
  auto iter = dp.find(n);
  if( iter != dp.end() )
    return iter->second;
  
  if( n == 0 )    return 0;
  if( n == 1 )    return 1;
  if( n == 2 )    return 1;

  ull ans;
  if( n % 2 == 0 ){
    ull k = n/2;
    ans = ( f(k+1) + f(k-1) ) % m;
    ans = ans * f(k);
    ans = ans % m;
  }else{
    ull k = n/2;
    ull t1 = f(k+1); t1 = (t1 * t1) % m;
    ull t2 = f(k); t2 = (t2 * t2) % m;
    ans = (t1 + t2) % m;
  }

  dp[n] = ans;
  return ans;
}


int main(){
  /*
    BEWARE!!
    untested algorithms... ^_^U

    except eratostenes
   */

  /*
    if a < 0, then a % M must be implemented as M - (a%M)
   */
  return 0;
}
