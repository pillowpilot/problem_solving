#include <iostream>
using namespace std;

typedef unsigned long long ull;

int main(){
  ull a, b, x, y, k;
  cin >> a >> b >> x >> y >> k;

  ull p = (ull) max(a, x);
  ull q = (ull) min(b, y);

  ull t;
  if( p <= q ) t = q - p + 1;
  else t = 0;
  
  if( p <= q && p <= k && k <= q ) t--;

  cout << t << endl;
  
  return 0;
}

// AC
