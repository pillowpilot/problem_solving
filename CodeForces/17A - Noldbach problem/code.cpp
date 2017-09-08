#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int maxv = 5050;
vb isPrime(maxv, true);
vi primes;

void eratosthenes(){
  isPrime[0] = isPrime[1] = false;
  int n = 2;
  while( n*n < isPrime.size() ){
    if( isPrime[n] ){
      int m = n*n;
      while( m < isPrime.size() ){
	isPrime[m]=false;
	m += n;
      }
    }
    n++;
  }

  rep(i, 0, isPrime.size()){
    if(isPrime[i])
      primes.push_back(i);
  }
}

int main(){
  eratosthenes();
  int n, k;
  cin >> n >> k;

  int c = 0;
  int i = 0;
  while( primes[i] + primes[i+1] + 1 <= n ){
    int a = primes[i]+primes[i+1]+1;
    if( isPrime[a] )c++;
    i++;
  }

  if(c >= k )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}

// AC
/*
  BT. Check for every i if the i-th prime + (i+1)th prime + 1 is prime.
  Count them all and compare.

  Because of the constrains (N<=1e3), trial division should be enough.
 */
