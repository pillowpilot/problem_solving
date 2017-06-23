#include <bits/stdc++.h>

#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a; i<=b; i++)

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
  // Add elements in [st.N, st.N+n]
  inline void build(){
    for(int i = N-1; i >= 1; i--){
      st[i] = st[2*i]+st[2*i+1]; //*
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
      // d[k] will always be 0, because of first line in this method
      d[k] = v;
      apply(k, x, y);
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
    if( d[k] == 1 ){ // to Buccaneer
      st[k] = (y-x+1);
      if( x != y )
	d[2*k] = d[2*k+1] = 1;
    }else if( d[k] == 2 ){ // to Barbary
      st[k] = 0;
      if( x != y )
	d[2*k] = d[2*k+1] = 2;
    }else if( d[k] == 3 ){
      st[k] = (y-x+1) - st[k];
      if( x != y )
	rep(i, 0, 1){
	  int x = 2*k+i;
	  if( d[x] == 0 ) d[x] = 3;
	  else if( d[x] == 1 ) d[x] = 2;
	  else if( d[x] == 2 ) d[x] = 1;
	  else if( d[x] == 3 ) d[x] = 0;
	}
    }
    d[k] = 0;
  }
  inline void print(){
    //return ;
    cerr << "N = " << N;
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

  int tests;
  cin >> tests;
  rep(testid, 1, tests){
    cout << "Case " << testid << ":\n";
    string pirate_land;
    
    int m;
    cin >> m;
    rep(setid, 1, m){
      int t;
      string pirates;
      cin >> t >> pirates;

      rep(i, 1, t){
	pirate_land += pirates;
      }      
    }
    debug(pirate_land);

    segtree st(pirate_land.size());
    rep(i, 0, pirate_land.size()-1){
      st.st[st.N+i] = (pirate_land[i]=='1')?1:0;
    }
    st.build();
    //st.print();

    int squeryc = 1;
    int q;
    cin >> q;
    rep(query, 1, q){
      char qtype;
      int a, b;
      cin >> qtype >> a >> b;
      switch(qtype){
      case 'F':
	st.update(a, b, 1); // to Buccaneer
	break;
      case 'E':
	st.update(a, b, 2); // to Barbary
	break;
      case 'I':
	st.update(a, b, 3); // toggle affiliation
	break;
      case 'S':
	ll ans = st.query(a, b);
	cout << "Q" << squeryc << ": " << ans << "\n";
	squeryc++;
	break;
      }
    }    
  }
  
  return 0;
}
