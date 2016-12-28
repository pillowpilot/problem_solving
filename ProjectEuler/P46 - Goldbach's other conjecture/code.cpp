#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

const int limit = 1e7;
vector<bool> isPrime(limit, true);
vector<int> primes;

void erathostenes(){
  isPrime[0] = isPrime[1] = false;

  int p = 2;
  while( p < limit ){
    if( isPrime[p] ){
      primes.push_back(p);
      ull j = p*p;
      while( j < limit ){
	isPrime[j] = false;
	j += p;
      }
    }
    p++;
  }
}

inline bool solution(int x, int p){
  if( (x-p)%2 == 0 ){
    double d = sqrt( (x-p)/2 );
    return (d - (int)d) < 1e-12;
  }
  return false;
}

int main(){
  erathostenes();

  cout << "#primes: " << primes.size() << endl;

  for(int x = 3; x < limit; x+=2){
    if( !isPrime[x] ){
      int i = 0;
      while( primes[i] < x && !solution(x, primes[i])){
	i++;
      }
      if( primes[i] > x ){
	cout << x << endl;
	break;
      }
    }
  }
  
  return 0;
}

// AC ans=5777
/*
  Brute force..
  assume x has a solution and try to find it. 
  the first one to fail... ans!
 */
