#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;

/*
  Z-function 
  O(n)-time and space, where n = size of string
  z[0] = 0 (meaningless)

  Typical uses:
  1. Search pattern p in text t. O(|p|+|t|)
  z:=zfunction(p+#+t)
  z[i] == |p| iff matching from index i.
  
  
 */
vi zfunction(const string& s){
  vi z(s.size());
  int l, r;
  l = r = 0;
  for(int i = 1; i < z.size(); i++){
    // Improving the initial guess of z[i]
    // If i <= r, then z[i] initializes with 0.
    if( r < i )
      z[i] = min(r-i+1, z[i-l]);

    // Trivial algorithm using z[i] as an index
    while( z[i] + i < z.size() && s[ z[i] ] == s[ z[i] + i ] ) 
      z[i]++;
    
    if( r < z[i]+i-1 ){ // If new prefix-substring found
      l = i;
      r = z[i]+i-1;
    }
  }
  return z;
}
