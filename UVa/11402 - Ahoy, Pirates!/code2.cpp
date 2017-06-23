#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#define debug(x) //cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a)i=a;i<=b;i++)

using namespace std;

typedef vector<int> vi;

struct segmenttree{
  int N;
  vi st;
  vi lazy;
  segmenttree(int n){
    N = 1;
    while( N <= n )
      N <<= 1;
    st.assign(2*N, 0);
    lazy.assign(2*N, 0);
  }
  void build(){
    for(int i = N-1; i > 0; i--){
      st[i] = st[2*i] + st[2*i+1];
    }
  }
  void add(int a, int b, int k, int x, int y, int op){
    debug(a);
    debug(b);
    debug(k);
    debug(x);
    debug(y);
    debug("");
    if(b<x||y<a) return ;
    apply(k, x, y);
    if(a<=x&&y<=b){
      lazy[k] = op;
      apply(k, x, y);
      return ;
    }
    int d = (x+y)/2;    
    add(a, b, 2*k, x, d, op);
    add(a, b, 2*k+1, d+1, y, op);
    st[k] = st[2*k] + st[2*k+1];
  }
  int sum(int a, int b, int k, int x, int y){
    debug(a);
    debug(b);
    debug(k);
    debug(x);
    debug(y);
    debug("");

    if(b<x||y<a) return 0;
    apply(k, x, y);
    if(a<=x&&y<=b) return st[k];    
    int d = (x+y)/2;
    return sum(a, b, 2*k, x, d)+sum(a, b, 2*k+1, d+1, y);
  }
  void apply(int k, int x, int y){
    if( x != y ){      
      // Extend to childs
      if( lazy[k] == 1 ) lazy[2*k] = lazy[2*k+1] = 1; // to Bucanneer
      if( lazy[k] == 2 ) lazy[2*k] = lazy[2*k+1] = 2; // to Barbary
      if( lazy[k] == 3 ){ // Invert

	if( lazy[2*k] == 0 ) lazy[2*k] = 3;
	else if( lazy[2*k] == 1 ) lazy[2*k] = 2;
	else if( lazy[2*k] == 2 ) lazy[2*k] = 1;
	else if( lazy[2*k] == 3 ) lazy[2*k] = 0;

	if( lazy[2*k+1] == 0 ) lazy[2*k+1] = 3;
	else if( lazy[2*k+1] == 1 ) lazy[2*k+1] = 2;
	else if( lazy[2*k+1] == 2 ) lazy[2*k+1] = 1;
	else if( lazy[2*k+1] == 3 ) lazy[2*k+1] = 0;
      }     
    }

    // Apply to this node
    if( lazy[k] == 1 ) st[k] = y-x+1; // to Bucanneer
    if( lazy[k] == 2 ) st[k] = 0; // to Barbary
    if( lazy[k] == 3 ) st[k] = (y-x+1)-st[k]; // Invert
    
    lazy[k] = 0;
  }
  void print(){
    return ;
    rep(i, 1, st.size()-1){
      if( i-(i&-i) == 0 )
	cout << "\n";
      cout << "(" << fixed << setw(2) << i << ")";
	cout << "[" << st[i] << " | " << lazy[i] << "] ";
    }
    cout << "\n";
  }
};

int main(){
  int testc;
  cin >> testc;
  while( testc-- ){
    int m;
    cin >> m;
    string data;
    rep(i, 1, m){
      int t;
      string s;
      cin >> t >> s;
      rep(j, 1, t){
	data += s;
      }
      debug(t);
      debug(s);
    }
    debug(data);

    segmenttree st(data.size());
    rep(i, 0, data.size()-1){
      st.st[st.N+i] = data[i]-'0';
    }
    st.build();
    st.print();
    debug(st.N);

    int qid = 1;
    int q;
    cin >> q;
    rep(i, 1, q){
      int a, b;
      string qt;
      cin >> qt >> a >> b;      
      debug(qt);
      int op;
      if(qt == "F"){
	op = 1;
      }else if(qt == "E"){
	op = 2;
      }else if(qt == "I"){
	op = 3;
      }else if(qt == "S"){
	op = 0;
      }

      if( op != 0 )
	st.add(a, b, 1, 0, st.N-1, op);
      else{
	st.print();
	int ans = st.sum(a, b, 1, 0, st.N-1);
	cout << "Q" << qid << ": " << ans << "\n";
	st.print();
	qid++;
      }

      rep(ff, 1, 3){
	cout << endl;
      }
    }
  }
  return 0;
}
