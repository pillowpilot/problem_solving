#include <iostream>
#include <vector>

#define rep(i, a, b) for(__typeof(a) i=a;i<=b;i++)

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
    if( v == u ) return ;
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
  rep(test, 1, testc){
    int n, m;
    cin >> n >> m;
    unionfind uf(n);
    rep(i, 1, m){
      int a, b;
      cin >> a >> b;
      a--; b--;
      uf.unite(a, b);
    }

    int ans = 0;
    rep(i, 0, uf.size.size()-1){
      ans = max(ans, uf.size[i]);
    }
    cout << ans << endl;
  }
  return 0;
}

// AC
