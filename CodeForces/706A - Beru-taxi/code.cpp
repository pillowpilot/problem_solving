#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0); cout.tie(0);

  ll a, b;
  int n;
  cin >> a >> b >> n;

  double mint = 99999999;
  while( n-- > 0 ){
    ll x, y, v;
    cin >> x >> y >> v;
    double d = (a-x)*(a-x) + (b-y)*(b-y);
    d = sqrt(d);
    mint = min(mint, d/v);
  }

  printf("%.20lf\n", mint);
  //cout << mint << endl;
  
  return 0;
}

// AC
