#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int const m = (int) 1e9+7;
ll f(ll x, ll y, ll n){
  ll ans;
  n--;
  switch(n%6){
  case 0:
    ans = x;
    break;
  case 1:
    ans = y;
    break;
  case 2:
    ans = y - x;
    break;
  case 3:
    ans = -x;
    break;
  case 4:
    ans = -y;
    break;
  case 5:
    ans = x - y;
    break;
  }
  
  ans = ans % m;
  if( ans < 0 )
    ans = m+ans;
  return ans;
}

int main(){
  ll x, y;
  ull n;

  cin >> x >> y >> n;

  cout << f(x, y, n) << endl;

  return 0;
}

// AC
