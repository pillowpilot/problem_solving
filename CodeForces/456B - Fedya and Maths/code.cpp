#include <bits/stdc++.h>
#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;

ll fastpow(ll b, ll e, ll m){
  if( e==0 ) return 1LL;
  ll t = fastpow(b, e/2, m);
  ll t2 = t*t%m;
  if( e%2== 0 ) return t2;
  else return t2*b%m;
}

ll f(ll n){
  ll ans = 0;
  rep(i, 1, 5){
    ans += fastpow(i, n, 5);
  }
  return ans%5;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  rep(i, 0, 200){
    //cout << i << " : " << f(i) << endl;
  }

  string n;
  cin >> n;
  debug(n);

  ll d;
  if( n.size() > 2 )
    d = (stoll(n.substr(n.size()-2, 2))) % 4;
  else
    d = stoll(n)%4;
  debug(d);
  //cout << f(d) << endl;

  if( d == 0 )
    cout << 4 << endl;
  else
    cout << 0 << endl;
  
  return 0;
}
  
// AC
/*
  First notice the pattern for small n.
  Is easy to deduce that if 4|n, then ans=4, else ans=0.
  
  From the same pattern, is natural to analyze the expression for n=4k+r
  Using Fermat's Theorem, a^(p-1)=1 (mod p), p is prime
  (1^n + 2^n + 3^n + 4^n) mod 5 = (1^r + 2^r + 3^r + 4^r) mod 5, where 0 <= r < 4
  which can be trivially calculated.

  Notice that we only need the last TWO digits of n.
 */
