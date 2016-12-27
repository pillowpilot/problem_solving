#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int limit = (int) 1e7;
vector<bool> isPrime(limit, true);
vector<int> primes;

inline void eratosthenes(){
  isPrime[0] = isPrime[1] = false;
  int prime = 2;
  while( prime * prime < isPrime.size() ){
    if( isPrime[prime] == true ){
      primes.push_back( prime );
      int index = prime * prime;
      while( index < isPrime.size() ){
	isPrime[index] = false;
	index += prime;
      }
    }
    prime++;
  }
}


inline bool isTruncatable(int n){
  string s = to_string(n);
  while( s != "" ){
    int a = stoi(s);
    //cout << ">> " << a << endl;
    if( !isPrime[a] ){
      return false;
    }
    s = s.substr(0, s.size()-1);
  }
  
  s = to_string(n);
  while( s != "" ){
    int b = stoi(s);
    //cout << ">> " << b << endl;
    if( !isPrime[b] )
      return false;
    s = s.substr(1, s.size()-1);
  }

  return true;
}

int main(){
  eratosthenes();
  cout << "DEBUG: Sieve complete." << endl;
  int ans = 0, c = 0;
  for(int i = 10; i < limit; i++){
    if( isTruncatable(i) ){
      ans += i;
      c++;
      cout << ">> (" << c << ") " << i << endl;
    }
  }
  cout << ans << endl;
  return 0;
}

// AC ans = 748317

/*
  Calculate better upper bound!!
 */
