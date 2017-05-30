#include <iostream>
#include <vector>
#include <cmath>

#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)
using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vll;

inline ull getLowerBound(double k, double d){
  int i = 0;
  int n = 1;
  while( i < k ){
    i += n*d;
    n++;
  }
  return n-1;
}

/*inline ull getLowerBound(ull k, ull d){
  return (sqrt((double)(d+8*k)/d)-1)/2;
  }*/

ull polyEval(const vll& c, ull x){
  ull ans = 0;
  ull p = 1;
  rep(i, 0, c.size()-1){
    ans += c[i]*p;
    p*=x;
  }
  return ans;
}

int main(){
  int c;
  cin >> c;
  rep(cs, 1, c){
    int deg;
    cin >> deg;

    vll poly;
    rep(i, 0, deg){
      int coef;
      cin >> coef;
      poly.push_back(coef);
    }
    int k, d;
    cin >> d >> k;

    int index = getLowerBound(k, d);
    //debug(index);
    ull ans = polyEval(poly, index);

    cout << ans << "\n";
  }
  return 0;
}

// AC
/*
  Annoying problem. Look for the index n such that ((n-1)n/2)*d < k <= (n(n+1)/2)*d.
  Calculate in O(deg) the n-th term.

  You could look using "linear search" O(sqrt(k)) or using BS or in O(1) solving for n (tricky?).
 */
