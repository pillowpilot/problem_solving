#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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
  while( testc-- ){
    unordered_map<string, int> namemap;
    unionfind net(100100);
    int f;
    cin >> f;
    rep(i, 1, f){
      string a, b;
      cin >> a >> b;
      int ida, idb;
      if( namemap.find(a) == namemap.end() ) namemap[a] = namemap.size();
      if( namemap.find(b) == namemap.end() ) namemap[b] = namemap.size();
      ida = namemap[a];
      idb = namemap[b];

      net.unite(ida, idb);

      int ans = net.size[net.find(ida)];
      cout << ans << "\n";
    }
  }
  return 0;
}

//AC
/*
  Trivial UnionSet.
  Map string to int with unordered_map (hash table) or map.
 */
