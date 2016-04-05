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

int main(){
  const int limit = 2e6;
  long long sum = 0;
  auto sieve_ptr = eratostenes(limit);
  
  for(int index = 2; index <= limit; index++){
    if( (*sieve_ptr)[index] == true ){
      sum += index;
    }
  }
  cout << sum << endl;
  return 0;
}

// AC
