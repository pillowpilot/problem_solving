#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

/*
  Segment Tree w/ Lazy
 */

struct segtree{
  int N;
  vll st, d;
  segtree(int n){
    N = 1 << (32-__builtin_clz(n));
    /*if( n-(n&-n)==0 ) N = n;
    else N = 1;
    while( N<n ) N <<= 1;*/

    st.assign(2*N, 0); //*
    d.assign(2*N, 0); //*
  }
  // Add elements in [st.N, st.N+n]
  inline void build(){
    for(int i = N-1; i >= 1; i--){
      st[i] = max(st[2*i],st[2*i+1]); //*
    }
  }
  ll query(int a, int b, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return 0; //*
    if( a <= x && y <= b ) return st[k];
    int mid = (x+y)/2;
    ll p = query(a, b, 2*k, x, mid);
    ll q = query(a, b, 2*k+1, mid+1, y);
    return max(p, q); //*
  }
  // Over [a, b]
  inline ll query(int a, int b){ 
    return query(a, b, 1, 0, N-1);
  }
  void update(int a, int b, ll v, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return ;
    if( a <= x && y <= b ){
      st[k] = v; //*
      if( x != y ){
	d[2*k] = v;
	d[2*k+1] = v;
      }
    }else{
      int mid = (x+y)/2;
      update(a, b, v, 2*k, x, mid);
      update(a, b, v, 2*k+1, mid+1, y);
      st[k] = max(st[2*k], st[2*k+1]);//*
    }
  }
  // Over [a, b]
  inline void update(int a, int b, ll v){
    return update(a, b, v, 1, 0, N-1);
  }
  inline void apply(int k, int x, int y){//*
    if( x != y ){
      d[2*k] = d[k];
      d[2*k+1] = d[k];
    }
    st[k] = d[k];
    d[k] = 0;
  }
  inline void print(){
    return ;
    cerr << "N = " << N;
    rep(i, 1, 2*N-1){
      if( i - (i&-i) == 0 ) cout << endl;
      cout << st[i] << "(" << d[i] << ") ";
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
  rep(i, 0, n){
    int a;
    cin >> a;
    st.st[st.N+i] = a;
  }
  st.build();

  int m;
  cin >> m;
  rep(i, 0, m){
    int w, h;
    cin >> w >> h;

    ll ans = st.query(0, w-1); // Query is over [0, w-1]
    cout << ans << endl;
    st.update(0, w-1, h+ans);
  }
  
  return 0;
}

// AC
/*
  Lazy ST. Update: Assignment, Query:Max
  For every range [0, w-1] get the max value M (the height of where the box will land)
  Assign to that range M+h (the height of the box)
 */
