#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int gcd(int a, int b){
  if( a < b )
    swap(a, b);
  if( b == 0 )
    return a;
  else
    return gcd(b, a%b);
}

int main(){

  int limit = 1000;
  vector<int> pp(limit+1);

  for(int m = 2; m < limit; m++){
    for(int n = 1; n < m; n++){
      if(gcd(m, n) == 1 && (m%2==0 || n%2==0)){
	const int p = 2*m*(m+n);
	int k = 1;
	while( k*p < pp.size() ){
	  pp[k*p]++;
	  k++;
	}
      }
    }
  }

  int maxv = 0;
  int ans;
  for(int p = 0; p < pp.size(); p++){
    if( maxv < pp[p] ){
      maxv = pp[p];
      ans = p;
    }
  }

  cout << ans << ":" << maxv << endl;
  cout << pp[120] << endl;

  return 0;
}

// AC ans = 840
/*
  (a, b, c) is a primitive Pithagorean triple iff
  a = m^2 - n^2
  b = 2mn
  c = m^2 + n^2
  where gcd(m, n) = 1 and not both odd.

  p = a+b+c = ... = 2m(m+n)
 */
