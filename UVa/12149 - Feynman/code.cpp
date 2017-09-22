#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;

ll f(ll n){
  ll ans = 0;
  rep(i, 0, n+1){
    ans += (n-i)*(n-i);
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  while( cin >> n && n != 0 ){
    cout << f(n) << "\n";
  }
  
  return 0;
}

// AC
/*
  Figure out the pattern.
  Every square can be mapped to its upper left vertex.
  Fix a length i in [1, n] and count. Add them all.
 */
