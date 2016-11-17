#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int n, m;
vll sum;
vvll dp;

inline ll g(int a, int b){
  /*assert(0<=a);
  assert(0<=b);
  assert(a<sum.size());
  assert(b<sum.size());*/
  if( a == 0 )
    return sum[b];
  else
    return sum[b] - sum[a-1];
}

ll f(int i, int j){
  /*assert(0<=i && 0<=j);
  assert(i<dp.size());
  assert(j<dp[i].size());*/
  
  if( dp[i][j] != -1 ) return dp[i][j];

  if( j == 0 )
    return 0;
  if( i == m-1 && j == 1 )
    return g(0, m-1);
  else{
    ll ans = 0;
    ll a = 0;
    if( 0 <= i-1 ) // if we can continue deleting items
      a = f(i-1, j); // last item does not belongs in a segment
    ll b = 0;
    if( 0 <= i-m ) // if last item can belong in a segment
      b = f(i-m, j-1) + g(i-m+1, i); // last item does belong in a segment
    
    ans = max(a, b);
    dp[i][j] = ans;
    return ans;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int k; cin >> n >> m >> k;

  while( n-- ){
    int a; cin >> a;
    if( sum.size() == 0 )
      sum.push_back( a );
    else
      sum.push_back( a + sum[sum.size()-1] );
  }
  n = sum.size();

  dp.resize(n+1);
  fill(begin(dp), end(dp), vll(k+1, -1));

  ll ans = f(n-1, k);
  cout << ans << endl;
  
  
  return 0;
}

// AC

/*
  decision: for every item. create or not a segment..??
  O(n^2)
 */
