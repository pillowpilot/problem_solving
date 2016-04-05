#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

typedef unsigned long long ull;
typedef long long ll;

int main(){
  double mind = numeric_limits<double>::max();
  double maxd = numeric_limits<double>::min();
  ll n, px, py;
  cin >> n >> px >> py;
  while( n-- > 0 ){
    ll x, y;
    cin >> x >> y;
    ll _x = x-px;
    _x *= _x;

    ll _y = y-py;
    _y *= _y;

    double d = sqrt(_x + _y);
    mind = min(mind, d);
    maxd = max(maxd, d);
  }

  double in = mind * mind;
  double out = maxd * maxd;
  double area = PI * (out - in);

  cout.precision(numeric_limits<double>::max_digits10);
  cout << fixed << area << endl;
  
  return 0;
}
