#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll pos, ww;
vvll dp;
vvll sumdp;
//vvll dpmin;

ll sum(int a, int b){
  return sumdp[a][b];
}

ll f(int n, int k){
  ll& memo = dp[n][k];
  if( memo != -1 )
    return memo;

  if( k == 1 ){
    ll ans = sum(0, n-1);
    memo = ans;
  }else{
    ll ans = 9999999;
    for(int i = k; i < n; i++){
      ans = min(ans, f(i, k-1) + sum(i, n-1) );
    }
    memo = ans;
  }
  
  return memo;
}

void init(int n, int k){
  
}

int main(){
  int n, k;
  while(cin >> n >> k){
    pos.clear();
    ww.clear();
    for(int i = 0; i < n; i++){
      int p, w; cin >> p >> w;
      pos.push_back(p);
      ww.push_back(w);
    }
    init(n, k);
    dp.resize(n+1); fill( begin(dp), end(dp), vll(k+1, -1) );
    //dpmin.resize(n); fill( beign(dpmin), end(dpmin), vll(k+1, -1) );

    cout << f(n, k) << endl;
  }
  return 0;
}
