#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

const int lmt = 1e9;
vector<bool> isPrime(lmt+1, true);

void erathostenes(){
  isPrime[0] = isPrime[1] = false;
  ull p = 2;
  while( p*p < isPrime.size() ){
    if( isPrime[p] ){
      ull b = p*p;
      while( b < isPrime.size() ){
	isPrime[b] = false;
	b += p;
      }
    }
    p++;
  }
}

int main(){
  erathostenes();

  double perc;
  int l = 1, primes = 0, total = 1;
  int a, b, c, d;
  a = b = c = d = 1;
  do{
    a += 4*l-2;
    b += 4*l;
    c += 4*l+2;
    d += 4*l+4;
    l += 2;
    total += 4;
    if(isPrime[a]) primes++;
    if(isPrime[b]) primes++;
    if(isPrime[c]) primes++;
    if(isPrime[d]) primes++;
    perc = (double)(primes)/total;
    //cout << a << " " << b << " " << c << " " << d << " " << perc << endl;
  }while(perc >= 0.1 && d + (4*l+4) < isPrime.size());

  cout << a << " " << b << " " << c << " " << d << " " << perc << endl;
  cout << l << endl;
  return 0;
}

// ans = 26241
/*
  8.6s with -O2!
  calculate upto 700e6!
 */
