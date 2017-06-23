#include <bits/stdc++.h>

#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(b) i=a; i<=b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

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
  inline void build(){
    for(int i = N-1; i >= 1; i--){
      st[i] = st[2*i]+ st[2*i+1];
    }
  }
  ll query(int a, int b, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return (1LL<<32); //*
    if( a <= x && y <= b ) return st[k];
    int mid = (x+y)/2;
    ll p = query(a, b, 2*k, x, mid);
    ll q = query(a, b, 2*k+1, mid+1, y);
    return min(p, q); //*
  }
  inline ll query(int a, int b){
    return query(a, b, 1, 0, N-1);
  }
  void update(int a, int b, ll v, int k, int x, int y){
    if( d[k] != 0 ) apply(k, x, y);
    if( y < a || b < x ) return ;
    if( a <= x && y <= b ){
      st[k] += v; //*
      if( x != y ){
	d[2*k] += v;
	d[2*k+1] += v;
      }
    }else{
      int mid = (x+y)/2;
      update(a, b, v, 2*k, x, mid);
      update(a, b, v, 2*k+1, mid+1, y);
      st[k] = min(st[2*k], st[2*k+1]);//*
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
  
  int n;
  int testid = 1;
  while( cin >> n ){
    cout << "Test " << testid << ":" << endl;;
    testid++;
    
    string s;
    cin >> s;

    debug(s);

    vll psum;
    psum.push_back((s[0]=='(')?1:-1);
    rep(i, 1, s.size()-1){
      ll p = psum.back();
      ll d = (s[i]=='(')?1:-1;
      psum.push_back(p+d);
    }

    rep(i, 0, psum.size()-1){
      //cout << psum[i] << " ";
    }
    //cout << endl;

    segtree st(n);
    rep(i, 0, psum.size()-1){
      st.update(i, i, psum[i]);
    }
    st.print();
    
    int m;
    cin >> m;
    rep(i, 1, m){
      int k;
      cin >> k;
      debug(k);
      if( k == 0 ){ // min query over all elems	
	ll mine = st.query(0, n-1);
	ll laste = st.query(n-1, n-1);
	debug(mine);
	debug(laste);
	if( mine >= 0 && laste == 0 ){
	  cout << "YES" << endl;
	}else{
	  cout << "NO" << endl;
	}	
      }else{ 
	debug(s);
	st.print();
	k--;
	if( s[k] == '(' ){
	  st.update(k, n-1, -2);
	  s[k] = ')';
	}else{
	  st.update(k, n-1, 2);
	  s[k] = '(';
	}
	debug(s);
	st.print();
      }
    }
  }
  return 0;
}

// AC
/*
  Apply segtree of range const update and range min query over the partial sum vector.
  ( == +1; ) == -1; psum[0] = s[0]; psum[i>0] = psum[i-1] + s[0];
  if s[i] toggles, then psum[i, end] += +/- 2 depending of s[i] (update query)
  s is a valid parenthesization iff psum[end] == 0 and min{psum[i]} >= 0
 */
