#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a)i=a;i<=b; i++)

using namespace std;

typedef vector<int> vi;
struct unionfind{
  vi parent, size;
  unionfind(int n){
    rep(i, 0, n-1){
      parent.push_back(i);
      size.push_back(1);
    }
  }
  int find(int v){
    while( parent[v] != v ) v = parent[v];
    return v;
  }
  void unite(int v, int u){
    v = find(v);
    u = find(u);
    if(size[v]>size[u]) swap(v, u);
    size[u]+=size[v];
    parent[v] = u;
  }
  bool test(int v, int u){
    return find(v)==find(u);
  }
};

int main(){
  int testc;
  cin >> testc;
  while( testc-- ){
    int n;
    cin >> n;
    unionfind pcs(n);

    int succ, unsucc;
    succ = unsucc = 0;

    string line;
    getline(cin, line);
    while( getline(cin, line) && line != "" ){
      stringstream oss(line);
      int a, b;
      string qt;
      oss >> qt >> a >> b;
      a--; b--;
      if( qt == "c" ){
	pcs.unite(a, b);
      }else{
	if( pcs.test(a, b) )
	  succ++;
	else
	  unsucc++;
      }      
    }
    cout << succ << "," << unsucc << "\n";
    if( testc > 0 )
      cout << "\n"; 
  }
  return 0;
}

// AC
/*
  Trivial UnionSet.
  Annoying presentation.
 */
