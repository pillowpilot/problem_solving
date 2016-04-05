#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;

vi primes;
/*
  Criba de Eratostenes.
  Con la mejora del cuadrado.
  O(n log log n)
  Para n=1e6 se tiene ~0.24s
 */
void sieveOfEratosthenes(int n){
  vb test = vb(n, true);
  primes  = vi();
  primes.reserve( 51e6 ); // (Según Wolfram) ~51e6 primos < 1e9 < 2^31 < 1e10

  int i = 2;
  while( i < test.size() ){
    if( test[i] == true ){ // Primo encontrado!
      primes.push_back( i );
      if( i < sqrt( numeric_limits<int>::max() ) ){ // Overflow check!
	int k = i * i;
	while( k < test.size() ){
	  test[k] = false;
	  k += i;
	}
      }
    }
    i++;
  }
}

vll tprimes;
void precompute(){
  tprimes = vll();
  tprimes.reserve( primes.size() );
  for( int i = 0; i < primes.size(); i++ ){
    tprimes.push_back( (long long)(primes[i]) * primes[i] );
  }
}

int main(){
  sieveOfEratosthenes(1e6+555);
  precompute();
  
  int n;
  cin >> n;
  while( n-- > 0 ){
    long long t;
    cin >> t;
    if( binary_search( tprimes.begin(), tprimes.end(), t ) == true )
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  cout << flush;
  
  return 0;
}

// AC
