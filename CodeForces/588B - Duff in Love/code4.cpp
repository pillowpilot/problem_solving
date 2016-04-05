#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

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

vll factors;
/*
  Factorización de Enteros, sobre precalculo de primos.
  Se necesitan todos los primos hasta al menos sqrt(n).
  |{primos <= 1e6}| = 78498 (Según Wolfram)
 */
void factorize(long long n){
  factors = vll(); // Los factores primos terminan aca, ordenados.
  // factors.push_back(1); // Interesante para n = 1.
  int i = 0; // Indice sobre los primos ordenados en "primes"!
  while( i < primes.size() && n > 1 ){ // operator[] no comprueba limites!
    while( n % primes[i] == 0 ){ // Factor primo encontrado!
      factors.push_back(primes[i]);
      n /=  primes[i];
    }
    i++;
  }
  // Si n posee un factor primo f mayor a sqrt(n), entonces f es primo.
  // Demostración por contradicción (suponer que f no es primo y llegar a que f > n)
  if( n != 1 ) factors.push_back( n );
}


int main(){
  ll n, a = 1;

  cin >> n;
  
  sieveOfEratosthenes( sqrt(n) + 588 );
  factorize(n);
  
  ll i = 0;
  while( i < factors.size()){
    ll factor = factors[i];
    a *= factor;
    while( factors[++i] == factor );
  }

  cout << a << endl;
  return 0;
}

// AC
