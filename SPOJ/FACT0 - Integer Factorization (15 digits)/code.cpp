#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int mod = 1e9+7;
const int maxValue = sqrt(1e15)+50;
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
vector< pair<long long, int> > factorize(long long n){
  vector< pair<long long, int> > factors;
  int i = 0;
  while( i < primes.size() && n != 1 ){
    int prime = primes[i];
    if( n % prime == 0 ){
      pair<long long, int> p(prime, 0);      
      while( n % prime == 0 ){
	p.second++;
	n /= prime;
      }
      factors.push_back(p);
    }
    i++;
  }
  if( n != 1 ){ // prime number >= 1e6
    factors.push_back(make_pair(n, 1));
  }
  return factors;
}

int main(){
  sieve();

  long long n;
  while( cin >> n && n != 0 ){
    vector< pair<long long, int> > factors = factorize(n);
    for(int i = 0; i < factors.size(); i++){
      cout << factors[i].first << "^" << factors[i].second << " ";
    }
    cout << "\n";
  }
  
  return 0;
}

// AC
/*
  Factorization in pi(n).
 */
