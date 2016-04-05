#include <iostream>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  ll a = (x1>x2)?x1-x2:x2-x1;
  ll b = (y1>y2)?y1-y2:y2-y1;
  ll c = (a>b)?a:b;

  cout << c << endl;
  
  return 0;
}

// AC
