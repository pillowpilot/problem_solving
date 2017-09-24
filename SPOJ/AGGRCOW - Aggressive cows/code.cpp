#include <bits/stdc++.h>
#define debug(x) //cerr << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int n, c;
vll xx;

bool possible(ll md){
  int cnt = 1;
  ll lastx = xx[0]; // It is always optimal to store a cow in the first stall
  rep(i, 1, xx.size()){
    ll d = xx[i]-lastx;
    if( d >= md ){
      cnt++;
      lastx = xx[i];
    }
    if( cnt == c )
      break;
  }
  return cnt == c;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tests;
  cin >> tests;
  while( tests-- > 0 ){
    cin >> n >> c;
    xx.clear();
    rep(i, 0, n){
      ll x;
      cin >> x;
      xx.push_back(x);
    }
    sort(all(xx));

    ll low, high;
    low = 0; // All stalls in the same spot
    high = 1e9+10;
    // ans in [low, high]
    while( low < high ){
      debug(low);
      debug(high);
      ll mid = (low+high)/2 + 1;
      debug(mid);
      if( possible(mid) )
	low = mid;
      else
	high = mid-1;
    }
    debug(low);
    debug(high);
    
    cout << low << endl;
  }

  return 0;
}

// AC
/*
  Binary Search over minimum distance.
  Assume a min dist m and the optimal min dist M.
  if m <= M, then is possible to store the cows.
  if M < m, then is not possible.
 */
