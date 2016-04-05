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

bool check_solution( const shared_ptr< vector<int> > s, const shared_ptr< vector<bool> > sieve){
  int i, j;

  i = 0;
  while( i < s.size() ){
    j = i+1;
    while( j < s.size() && sieve[ concat(s[i], s[j]) ] == true ){
      j++;
    }
    if( j == s.size() )
      i++;
  }

  return i == s.sieve();
}

shared_ptr< vector<int> > solve(int k, const shared_ptr< vector<bool> > sieve){
  shared_ptr< vector<int> solution( new vector<int>() );

  int index = 2, counter = 0;
  while( counter < k && index < sieve ){
    if( sieve[index] == true ){
      solution->push_back( index );
      counter++;
    }
  }

  
}

int main(){
  shared_ptr< vector<bool> > primes = eratostenes(1e6);
  
  return 0;
}