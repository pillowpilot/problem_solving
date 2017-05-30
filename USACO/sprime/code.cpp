/*
  ID: carlos.16
  PROG: sprime
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b;i++)

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

const int limit = 12000;
vb isPrime(limit, true);
vi primes;

void eratosthenes(){
  isPrime[0] = isPrime[1] = false;
  int p = 2;
  while( p*p < isPrime.size() ){
    if( isPrime[p] ){
      int j = p*p;
      while( j < isPrime.size() ){
	isPrime[j] = false;
	j += p;
      }
    }
    p++;
  }
  rep(i, 0, isPrime.size()-1){
    if( isPrime[i] )
      primes.push_back(i);
  }
}

bool testPrime(int n){
  if( n <= 1 ) return false;
  int i = 0;
  while( primes[i]*primes[i] <= n && n%primes[i] != 0 )
    i++;
  return primes[i]*primes[i] > n;
}

int pow(int b, int e){
  if( e == 0 )
    return 1;
  else if( e % 2 == 0 ){
    int x = pow(b, e/2);
    return x*x;
  }else{
    int x = pow(b, e/2);
    return x*x*b;
  }    
}

bool test(int n){
  while( n > 0 ){
    if( !testPrime(n) )
      return false;
    n /= 10;
  }
  return true;
}

int main(){
  ifstream input("sprime.in");
  ofstream output("sprime.out");
  eratosthenes();

  int n;
  input >> n;

  for(int i = pow(10, n-1)+2*pow(10, n-2)-1; i <= pow(10, n)-1; i+=2){
    if( test(i) ){
      cout << i << "\n";
    }
  }  
  return 0;
}
