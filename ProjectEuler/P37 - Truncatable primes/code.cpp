#include <iostream>
#include <vector>
#include <memory>
#include <limits>

using namespace std;

shared_ptr< vector<bool> > eratostenes(int n){
  // vector[0] and vector[1] has no meaning!
  shared_ptr< vector<bool> > sieve_ptr( new vector<bool>(n + 1, true) );
  (*sieve_ptr)[0] = (*sieve_ptr)[1] = false;
  
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

inline int invert(int n){
  int m = 0;
  do{
    m *= 10;
    m += n % 10;
    n /= 10;
  }while( n != 0 );
  return m;
}

bool check(const vector<bool>& sieve, int n){
  do{
    n /= 10;
  }while( n != 0 && sieve[n] == true );
  return n == 0;
}

inline bool doubleCheck(const vector<bool>& sieve, int n){
  return check(sieve, n) && check(sieve, invert(n));
}

int main(){
  const int limit = 10e6;
  shared_ptr< vector<bool> > sieve = eratostenes(limit);

  int sum = 0;
  for(int i = 2; i < sieve->size(); i++)
    if( (*sieve)[i] == true && doubleCheck(*sieve, i)){
      cout << i << endl;
      sum += i;
    }
  
  cout << ">>> " << sum << endl;
  return 0;
}
