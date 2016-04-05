#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << '[';
  if( v.size() > 0 ){
    typename vector<T>::const_iterator iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  os << ']';
  return os;
}

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
  const int limit = 1.1e5;
  const int target = 10001;
  auto sieve_ptr = eratostenes(limit);
  int index = 2, c = 0;
  while( index <= limit && c < target ){
    if( (*sieve_ptr)[index] == true )
      c++;
    index++;
  }
  if( target == c )
    cout << index - 1 << endl;
  else
    cout << "Increment limit!" << endl;
  return 0;
}

// AC
