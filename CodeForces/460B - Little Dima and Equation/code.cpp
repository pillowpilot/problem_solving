#include <iostream>
#include <queue>

using namespace std;

typedef priority_queue<int> pqi;
typedef long long ll;

ll p(ll b, ll e){
  ll ans = 1;
  while( e-- > 0 )
    ans *= b;
  return ans;
}

int s(ll n){
  int ans = 0;
  while(n>0){
    ans += n%10;
    n /= 10;
  }
  return ans;
}

/*
  we could check for every x in (0, 1e9)
  or we could check for every s(x) in [1, 9*9=81].

  and we could reverse the priority pushing -x and printing -x.
 */

int main(){
  ll a, b, c;
  cin >> a >> b >> c;

  pqi ans;
  for(int i = 1; i <= 81;i++){
    ll e = b*p(i, a) + c;

    //cout << i << ' ' << e << ' ' << s(e) << endl;
    if( 0 < e && e < (ll) 1e9 && s(e) == i)
      ans.push(-e);
  }

  cout << ans.size() << '\n';
  while( !ans.empty() ){
    cout << -ans.top() << ' ';
    ans.pop();
  }
  cout << endl;
  
  return 0;
}

// AC
