#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr< vector<bool> > eratostenes(int n){
  // vector[0] and vector[1] has no meaning!
  shared_ptr< vector<bool> > sieve_ptr( new vector<bool>(n + 1, true) );
  
  int index = 2;
  while( index * index <= n ){
    int upperIndex = index * index;
    while( upperIndex <= n ){
      (*sieve_ptr)[upperIndex] = false;
      upperIndex += index;
    }
    index++;
    while( index*index <= n && (*sieve_ptr)[index] == false )
      index++;
  }
  return sieve_ptr;
}

inline int f(int n, int a, int b){
  return n*n + a*n + b;
}

int main(){
  shared_ptr< vector<bool> > primes = eratostenes(5e3); // TODO Find the max possible value
  vector<int> bPrimes = vector<int>();
  
  int i = 2;
  while( i < primes->size() && i < 1e3 ){
    if( (*primes)[i] == true )
      bPrimes.push_back( i );
    i++;
  }

  cout << "Primes ready!\n";

  int maxLength = 0;
  int maxA, maxB;

  for(int a = -2; a <= 1000; a++){
    int length = 0;
    while( f(length, a, 2) >= 0 && (*primes)[ f(length, a, 2) ] == true )
      length++;
    if( maxLength < length ){
      maxLength = length;
      maxA = a;
      maxB = 2;
    }
  }
  
  for(int bi = 1; bi < bPrimes.size(); bi++){
    int b = bPrimes[bi];
    for(int a = -b; a <= 1000; a+=2){
      int length = 0;
      while( f(length, a, b) >= 0 && (*primes)[ f(length, a, b) ] == true )
	length++;
      if( maxLength < length ){
	maxLength = length;
	maxA = a;
	maxB = b;
      }
    }
  }

  cout << maxA << "*" << maxB << "=" << maxA*maxB << "(" << maxLength << ")" << endl;
}

/*
  If n=0, then b in Primes < 10**3. (Remove all quadratic formula of "chain length" equal to 0)
  If a < -b, then 1*1 + 1*a + b < 1. Finally, 1*1 + 1*a + b not in Primes.
  If 2|a and not 2|b and n=1, then 1*1 + 1*(2*a') + (2*b'+1) = 2*(a'+b'+1) not in Primes.
 */
// AC ~0.019s
