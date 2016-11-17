#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  const string separator = "";
  os << "[";
  if( v.size() != 0){
    typename vector<T>::const_iterator iter = begin(v);
    os << *iter;
    iter++;
    while( iter != end(v) ){
      os << separator << *iter;
      iter++;
    }
  }
  os << "]";
  return os;
}

int main(){
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int limit = (int) 1e6;

  for(int i = 1; i < limit; i++){
    next_permutation(begin(v), end(v));
  }
  
  cout << v << endl;
  
  return 0;
}

// AC ans = 2783915460

/*
  0123...789 is already the first permutation!
  therefore we only need to run next_permutation (limit-1) times!
 */
