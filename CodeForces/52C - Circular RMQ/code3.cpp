#include <bits/stdc++.h>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll INF = 1LL<<60;
const int N = 2e5+505;
int n;
ll st[4*N];
ll d[4*N];

void apply(int k, int x, int y){
  if( x != y ){
    d[2*k] += d[k];
    d[2*k+1] += d[k];
  }
  st[k] += d[k];
  d[k] = 0;
}

ll update(int k, int x, int y, int a, int b, int v){
  apply(k, x, y);
  if( y < a || b < x ) return st[k];
  if( a <= x && y <= b ){
    d[k] += v;
    apply(k, x, y);
    return st[k];
  }
  int mid = (x+y)/2;
  ll p = update(2*k, x, mid, a, b, v);
  ll q = update(2*k+1, mid+1, y, a, b, v);
  st[k] = min(p, q);
  return st[k];
}
ll update(int a, int b, int v){
  return update(1, 0, n-1, a, b, v);
}

ll query(int k, int x, int y, int a, int b){
  apply(k, x, y);
  if( y < a || b < x ) return INF;
  if( a <= x && y <= b ) return st[k];
  int mid = (x+y)/2;
  ll p = query(2*k, x, mid, a, b);
  ll q = query(2*k+1, mid+1, y, a, b);
  return min(p, q);
}

ll query(int a, int b){
  return query(1, 0, n-1, a, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  rep(i, 0, 4*N-1){
    st[i] = 0;
    d[i] = 0;
  }
  rep(i, 0, n-1){
    int a;
    cin >> a;
    update(i, i, a);
  }
  
  int m;
  cin >> m;
  string line;
  getline(cin, line);
  rep(i, 1, m){
    getline(cin, line);
    //debug(line);
    stringstream oss(line);
    vll args;
    ll t;
    while( oss >> t )
      args.push_back(t);
    if( args.size() == 2 ){ // query
      int a = args[0];
      int b = args[1];
      ll ans;
      if( b < a ){
	ll ans1 = query(0, b);
	ll ans2 = query(a, n-1);
	ans = min(ans1, ans2);
      }else{
	ans = query(a, b);
      }
      cout << ans << endl;
    }else{
      int a = args[0];
      int b = args[1];
      int v = args[2];
      if( b < a ){
	update(0, b, v);
	update(a, n-1, v);
      }else{
	update(a, b, v);
      }
    }
  }

  return 0;
}

// AC
/*
  Finally!!! First lazy segtree AC!!
  fast io is NECESARY! 

  To handle cyclic queries just decompose them (if necesary) into 2 queries.
  [a, b] (b < a) = [0, b] + [a, N-1]
 */
