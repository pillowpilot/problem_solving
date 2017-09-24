#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int maxm = 42;
vvll memo(maxm+1, vll(3, -1));

ll f(int n, int m){
  if( memo[n][m] != -1 ) return memo[n][m];
  ll ans;
  if( m == 0 ) ans = f(n-1, 2)+f(n-2, 0)+f(n-2, 1)+f(n-2, 2);
  if( m == 1 ) ans = f(n, 0)+f(n-2, 1);
  if( m == 2 ) ans = f(n, 0)+f(n-1, 0)+f(n-2, 2);
  memo[n][m] = ans;
  return ans;  
}

void prep(){
  memo[0][0] = memo[1][0] = 1;
  memo[0][1] = memo[1][1] = 1;
  memo[0][2] = 1;
  memo[1][2] = 2;

  /*rep(n, 2, memo.size()){
    memo[n][0] = memo[n-1][2] + memo[n-2][0] +  memo[n-2][1] + memo[n-2][2];
    memo[n][1] = memo[n][0] + memo[n-2][1];
    memo[n][2] = memo[n][0] + memo[n-1][0] + memo[n-2][2];
  }*/
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  prep();
  int tests;
  cin >> tests;

  rep(c, 1, tests+1){
    int x;
    cin >> x;
    cout << c << " " << f(x, 0) << "\n";
  }
  
  return 0;
}

// AC
/*
  DP w/ bit masks
  Notice that only 3 type of masks are needed.
 */
