#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main(){
  ull d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;

  ull ans = (ull)1e15;

  if( k <= d )
    ans = min(ans, k*a + (d-k)*b); // drive then walk

  if( d <= k )
    ans = min(ans, d*a); // only drive

  ans = min(ans, (a*k+t)*(d/k) + (d%k)*a);
  ans = min(ans, (a*k+t)*(d/k) + (d%k)*b);

  cout << ans << endl;
  
  return 0;
}
