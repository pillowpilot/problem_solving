#include <iostream>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef map<ull, ull> muu;

ull const m = (ull) 1e9+7;
muu dp;

ull f(ull n){
  auto iter = dp.find(n);
  if( iter != dp.end() )
    return iter->second;
  
  if( n == 0 )    return 0;
  if( n == 1 )    return 1;
  if( n == 2 )    return 1;

  ull ans;
  if( n % 2 == 0 ){
    ull k = n/2;
    ans = ( f(k+1) + f(k-1) ) % m;
    ans = ans * f(k);
    ans = ans % m;
  }else{
    ull k = n/2;
    ull t1 = f(k+1); t1 = (t1 * t1) % m;
    ull t2 = f(k); t2 = (t2 * t2) % m;
    ans = (t1 + t2) % m;
  }

  dp[n] = ans;
  return ans;
}

int main(){
  ll x, y;
  cin >> x >> y;
  if( x < 0 ) x = m + x;
  if( y < 0 ) y = m + y;
  ull n;
  cin >> n;

  ull a = f(n-3);
  ull b = f(n-2);
  ull ans = (a*x) % m + (b*y) % m;

  cout << ans << endl;
  
  return 0;
}
// WA (wrong approach)
