#include <bits/stdc++.h>

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
    //N = 1 << (32-__builtin_clz(n));
    if( n-(n&-n)==0 ) N = n;
    else N = 1;
    while( N<n ) N <<= 1;

    st.assign(2*N, 0); //*
    d.assign(2*N, 0); //*
  }
  inline void build(){
    for(int i = N-1; i >= 1; i--){
      st[i] = st[2*i]+ st[2*i+1];
    }
  }
  ll query(int a, int b, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return 0; //*
    if( a <= x && y <= b ) return st[k];
    int mid = (x+y)/2;
    ll p = query(a, b, 2*k, x, mid);
    ll q = query(a, b, 2*k+1, mid+1, y);
    return p+q; //*
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
      st[k] = st[2*k] + st[2*k+1];//*
    }
  }
  inline void update(int a, int b, ll v){
    return update(a, b, v, 1, 0, N-1);
  }
  inline void apply(int k, int x, int y){//*
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
      cout << st[i] << " ";
    }
    cout << endl;
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, k, q;
  cin >> n >> k >> q;

  const int range = 200200;
  segtree st1(range);
  rep(i, 1, n){
    int a, b;
    cin >> a >> b;
    st1.update(a, b, 1);
  }

  segtree st2(range);
  rep(i, 0, range-1){
    ll e = st1.query(i, i);
    if( k <= e )
      st2.st[st2.N+i] = 1;
    else
      st2.st[st2.N+i] = 0;
  }
  st2.build();

  rep(i, 1, q){
    int a, b;
    cin >> a >> b;
    ll e = st2.query(a, b);
    cout << e << endl;
  }

  return 0;
}

// AC
/*
  Double use of a segtree for range add const and range sum.
  First use a st to store all recipes ranges. Adding 1 to elements in [l, r].
  Get all items e (sum over [i, i]) to initizalize another st where each element
  is 1 if e >= k, 0 otherwise.
  Answer all queries trivially as the sum over [l, r]

  There is a O(n) solution!
 */
