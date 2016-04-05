#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(){
  ull d1, d2, d3, a, b, c, d, m;

  cin >> d1 >> d2 >> d3;
  a = d1 + d2 + d3;
  b = 2*(d1+d2);
  c = 2*(d1+d3);
  d = 2*(d2+d3);
  m = min( a, min( b, min( c, d ) ) );
  cout << m << endl;
  
  return 0;
}

// AC
