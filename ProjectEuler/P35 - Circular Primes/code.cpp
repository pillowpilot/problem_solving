#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

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

bool isSolution(const shared_ptr< vector<bool> >& sieve, int n){
  int t = n, exp = int(log(n)/log(10));
  do{
    int d = n % 10;
    n /= 10;
    n += d * pow(10, exp);
    //cout << n << endl;
  }while( n != t && (*sieve)[n] == true );
  return n == t;
}

int main(){
  const int limit = 1e6;

  auto sieve = eratostenes(limit*10);
  auto primes = vector<int>();
  for(int i = 2; i < limit; i++) // Primes with even digits will not be a solution!
    if( (*sieve)[i] == true )    // Primes with their digit sum multiple of 3?
      primes.push_back( i );

  int counter = 0;
  for(int i: primes){
    if( isSolution(sieve, i) ){
      counter++;
      //cout << ">> " << i << endl;
    }
  }
  cout << counter << endl;
  
  return 0;
}

// AC
