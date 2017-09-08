#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;
const int maxValue = 1e6;
vector<bool> isPrime(maxValue, true);
vector<int> primes;

// Criba de Eratostenes Extendida O(n lg lg n)
void sieve(){
  isPrime[0] = isPrime[1] = false;
  
  int prime = 2;
  while( prime*prime < isPrime.size() ){ // Optimizacion
    if( isPrime[prime] ){
      // Eliminar/marcar numeros multiplos del primo
      int primeMultiple = prime*prime; // Optimizacion
      while( primeMultiple < isPrime.size() ){
	isPrime[primeMultiple] = false;
	primeMultiple += prime;
      }
    }
    prime++;
  }

  for(int i = 2; i < isPrime.size(); i++)
    if( isPrime[i] )
      primes.push_back(i);
}

// Factorizacion en O( pi(n) )
vector<long long> factorize(long long n){
  vector<long long> factors;
  int i = 0;
  while( i < primes.size() && n != 1 ){
    int prime = primes[i];
    if( n % prime == 0 )
      factors.push_back(prime);
    while( n % prime == 0 ){
      //factors.push_back(prime);
      n /= prime;
    }
    i++;
  }
  if( n != 1 ){ // prime number >= 1e6
    factors.push_back(n);
  }
  return factors;
}

int main(){
  sieve();

  long long n;
  cin >> n;
  vector<long long> factors = factorize(n);
  for(int i = 0; i < factors.size(); i++){
    cout << factors[i] << "\n";
  }
  
  return 0;
}

// AC
/*
  Factorize using Prime list builded from Eratosthenes.
 */
