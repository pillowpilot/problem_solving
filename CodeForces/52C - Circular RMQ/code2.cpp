#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll INF = 1LL<<61;

struct segtree{
  int N;
  vll st, d;
  segtree(int n){
    N = 1 << (32-__builtin_clz(n));
    /*if( n-(n&-n)==0 ) N = n;
    else N = 1;
    while( N<n ) N <<= 1;*/

    st.assign(2*N, INF);
    d.assign(2*N, 0);
  }
  inline void build(){
    for(int i = N-1; i >= 1; i--){
      st[i] = min(st[2*i], st[2*i+1]);
    }
  }
  ll query(int a, int b, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return INF;
    if( a <= x && y <= b ) return st[k];
    int mid = (x+y)/2;
    ll p = query(a, b, 2*k, x, mid);
    ll q = query(a, b, 2*k+1, mid+1, y);
    return min(p, q);
  }
  inline ll query(int a, int b){
    return query(a, b, 1, 0, N-1);
  }
  void update(int a, int b, ll v, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return ;
    if( a <= x && y <= b ){
      st[k] += v;
      if( x != y ){
	d[2*k] += v;
	d[2*k+1] += v;
      }
    }else{
      int mid = (x+y)/2;
      update(a, b, v, 2*k, x, mid);
      update(a, b, v, 2*k+1, mid+1, y);
      st[k] = min(st[2*k], st[2*k+1]);
    }
  }
  inline void update(int a, int b, ll v){
    return update(a, b, v, 1, 0, N-1);
  }
  inline void apply(int k, int x, int y){
    if( x != y ){
      d[2*k] += d[k];
      d[2*k+1] += d[k];
    }
    st[k] += d[k];
    d[k] = 0;
  }
  inline void print(){
    return ;
    debug(N);
    rep(i, 1, 2*N-1){
      if( i - (i&-i) == 0 ) cout << endl;
      if( st[i] == INF )
	cout << "INF ";
      else
	cout << st[i] << " ";
    }
    cout << endl;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n;
  cin >> n;
  segtree st(n);
  //st.print();
  rep(i, 0, n-1){
    int a;
    cin >> a;
    //st.update(i, i, a);
    st.st[st.N+i] = a;
    //st.print();
  }
  st.build();
  //st.print();
  
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
	ll ans1 = st.query(0, b);
	ll ans2 = st.query(a, st.N-1);
	ans = min(ans1, ans2);
      }else{
	ans = st.query(a, b);
      }
      cout << ans << endl;
    }else{
      int a = args[0];
      int b = args[1];
      int v = args[2];
      //st.print();
      if( b < a ){
	st.update(0, b, v);
	st.update(a, st.N-1, v);
      }else{
	st.update(a, b, v);
      }
      //st.print();
    }
  }
  return 0;
}

// AC
/*
  Fast IO!
  See code3 for details.
 */
