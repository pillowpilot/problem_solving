#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a)i=a;i<=b;i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll inf = 1LL<<62;

struct segmenttree{
  int N;
  vll st;
  vll lazy;
  segmenttree(int n){
    N = 1;
    if( n-(n&-n) == 0 )
      N = n;
    else
      while( N <= n ) N <<= 1;
    
    st.assign(2*N, inf);
    lazy.assign(2*N, 0);
  }
  ll minrange(int a, int b){
    return minrange(a, b, 1, 0, N-1);
  }
  ll minrange(int a, int b, int k, int x, int y){
    if( y < a || b < x ) return inf;
    if( lazy[k] != 0 ) apply(k, x, y);
    if( a<=x&&y<=b ) return st[k];
    int d = (x+y)/2;
    return min(minrange(a, b, 2*k, x, d), minrange(a, b, 2*k+1, d+1, y));
  }
  void addrange(int a, int b, ll v){
    addrange(a, b, 1, 0, N-1, v);
  }
  void addrange(int a, int b, int k, int x, int y, ll v){
    if( y < a || b < x ) return;
    if( lazy[k] != 0 ) apply(k, x, y);
    if( a<=x&&y<=b ){
      lazy[k] = v;
      apply(k, x, y);
      return;
    }
    int d = (x+y)/2;
    addrange(a, b, 2*k, x, d, v);
    addrange(a, b, 2*k+1, d+1, y, v);
    st[k] = min(st[2*k], st[2*k+1]);
  }
  void apply(int k, int x, int y){
    if( x != y ){
      lazy[2*k] += lazy[k];
      lazy[2*k+1] += lazy[k];
    }
    st[k] += lazy[k];
    lazy[k]=0;
  }
  void build(){
    for(int i=N-1; i > 0; i--){
      st[i] = min(st[2*i], st[2*i+1]);      
    }
  }
  void print(){
    return ;
    rep(i, 1, st.size()-1){
      if( i - (i&-i) == 0 )
	cout << endl;
      cout << "[" << st[i] << " | " << lazy[i] << "] ";
    }
    cout << endl;
  }
};

int spacecount(const string& s){
  int c = 0;
  rep(i, 0, s.size()-1){
    if( s[i] == ' ' )
      c++;
  }
  return c;
}

int main(){
  int n;
  cin >> n;
  segmenttree st(n);
  rep(i, 0, n-1){
    int x;
    cin >> x;
    st.st[st.N+i] = x;
  }
  st.build();
  
  int q;
  cin >> q;

  string line;
  getline(cin, line);
  rep(i, 1, q){
    getline(cin, line);
    stringstream oss(line);
    //debug(line);
    if( spacecount(line) == 1 ){
      int a, b;
      oss >> a >> b;
      int ans;
      debug(a);
      debug(b);
      st.print();
      if( b < a ){
	debug(st.minrange(0, b));
	debug(st.minrange(a, n-1));
	ans = min(st.minrange(0, b), st.minrange(a, n-1));
      }else{
	ans = st.minrange(a, b);
      }
      cout << ans << " "  << a << " " << b << "\n";
    }else{
      int a, b, v;
      oss >> a >> b >> v;
      debug(a);
      debug(b);
      debug(v);
      st.print();
      if( b < a ){
	st.addrange(0, b, v);
	debug("*");
	st.print();
	st.addrange(a, n-1, v);
      }else
	st.addrange(a, b, v);
    }
  }
  return 0;
}
