#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
typedef map<ll, ll> mll;

mll memo;
ll f(ll n){
  if( n == 0 ) return 0;
  if( memo.find(n) != memo.end() ) return memo[n];
  ll a = f(n/2);
  ll b = f(n/3);
  ll c = f(n/4);

  ll ans = max(n, a+b+c);
  memo[n] = ans;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  ll n;
  while( cin >> n ){
    ll ans = f(n);
    cout << ans << "\n";
  }
  
  return 0;
} 
// AC
/*
  DP. Use map because of range of n <= 1e9. 
  I guest is O(lg n lg lg n)
 */
