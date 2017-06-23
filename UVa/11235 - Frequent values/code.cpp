#include <vector>
#include <iostream>

#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a)i=a; i<=b; i++)
#define repi(i, a, b) for(__typeof(a)i=a; i>=b; i--)

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpi;

ostream& operator<<(ostream& os, const pii p){
  return os << "(" << p.first << ", " << p.second << ")";
}

struct segmenttree{
  int N;
  vpi st;
  segmenttree(int n){
    N = 1;
    while( N < n )
      N <<= 1;

    st.assign(2*N, {0, 0});
    debug(N);
  }
  void buildTree(){
    repi(i, N-1, 1){
      pii lc = st[2*i];
      pii rc = st[2*i+1];
      if( lc.second == rc.second ){
	st[i] = {lc.first+rc.first, lc.second};
      }else if( lc.first > rc.first ){
	st[i] = lc;
      }else{
	st[i] = rc;
      }      
    }
  }
  pii sum(int a, int b){
    a += N; b += N;
    pii sum = {0, 0};
    while( a <= b ){
      if(a%2==1){
	if( sum.second == st[a].second ) sum.first += st[a].first;
	else if( sum.first < st[a].first ) sum = st[a];
	a--;
      }
      if(b%2==0){
	if( sum.second == st[b].second ) sum.first += st[b].first;
	else if( sum.first < st[b].first ) sum = st[b];
	b--;
      }      
      a <<= 1; b <<= 1;
    }
    return sum;
  }
  void printTree(){
    rep(i, 1, st.size()-1){
      if( i - (i&-i) == 0 )
	cout << endl;
      cout << st[i] << " ";
    }
    cout << endl;
  }
  
};

int main(){
  int n;
  while( cin >> n && n != 0 ){
    debug(n);
    int q;
    cin >> q;

    segmenttree st(n);
    rep(i, 0, n-1){
      int a;
      cin >> a;
      st.st[st.N+i] = {1, a};
    }
    st.buildTree();
    st.printTree();

    cout << st.sum(0, n) << endl;
    cout << st.sum(1, n-1) << endl;
    cout << st.sum(1, 1) << endl;
    cout << st.sum(1, 3) << endl;
    
  }
  return 0;
}
