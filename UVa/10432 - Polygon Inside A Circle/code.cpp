#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  const double pi = M_PI;
  double n, r;
  while( cin >> r >> n ){
    double a = sin(pi/n);
    double b = sin(pi/2-pi/n);
    double ans = n*r*r*a*b;
    cout << setprecision(3) << fixed << ans << "\n";
  }

  return 0;
}

// AC
/*
  Trivial geometry. Split the polygon in 2n rectangular triangle.
  Calculate area of one and multiply.
*/
