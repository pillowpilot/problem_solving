#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int n, m;
vll data;
vll fast;
vvll dp;

ll g(int a, int b){
  /*int ans = 0;
  for(int i = a; i <= b; i++){
    assert(0<=i);
    assert(i < data.size());
    ans += data[i];
  }
  return ans;*/
  if( a != 0 )
    return fast[b] - fast[a-1];
  else
    return fast[b];
}

ll f(int k, int b){
  assert(0<=k);
  assert(0<=b);
  assert(k<dp.size());
  assert(b<dp[k].size());

  if( dp[k][b] != -1 ) return dp[k][b];

  if( k == 1 ){
    ll ans = 0;
    for(int y = 0; y <= n-b-m; y++){
      ans = max(ans, g(b+y, b+y+m-1));
    }
    dp[k][b] = ans;
    return ans;
  }else{
    ll ans = 0;
    for(int y = 0; y <= (n-b-1)-(k-1)*m; y++){
      ans = max(ans, f(k-1, b + y + m) + g(b+y, b+y+m-1));
    }
    dp[k][b] = ans;
    return ans;
  }
}

int main(){
  int k;
  cin >> n >> m >> k;

  dp.resize( k+1 );
  fill(begin(dp), end(dp), vll(n+1, -1));
  while( n-- ){
    int a; cin >> a;
    data.push_back(a);
  }
  n = data.size();

  fast.push_back( data[0] );
  for(int i = 1; i < n; i++){
    fast.push_back( data[i] + fast[i-1] );
  }

  ll ans = f(k, 0);
  cout << ans << endl;
  return 0;
}

// TLE
/*
  Probably correct but the internal for takes O(n) for small m... T_T

  dp[i][j] = in the first i numbers choose j pairs...
 */
