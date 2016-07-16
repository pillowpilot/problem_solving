#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;
typedef map<ull, ull> muu;
typedef vector<ull> vu;

muu ww;
vu path1;
vu path2;

void buildPath(ull u, vu& p){
  p.push_back(u);
  if( u == 1 ) return;
  buildPath(u/2, p);
}

ull lca(ull u, ull v){
  path1 = vu();
  path2 = vu();
  
  buildPath(u, path1);
  buildPath(v, path2);

  reverse(path1.begin(), path1.end());
  reverse(path2.begin(), path2.end());
  
  int i=0;
  while( i < path1.size() && i < path2.size() && path1[i] == path2[i])
    i++;

  i--;
  return path1[i];
}

void update2(ull r, ull u, ull w){
  if(u==r) return;
  ww[u] += w;
  update2(r, u/2, w);
}

ull cost2(ull r, ull u){
  if(u==r) return 0;
  return ww[u] + cost2(r, u/2);
}

int main(){
  int q;
  cin >> q;

  while( q-->0){
    int type;
    cin >> type;
    if( type == 1 ){
      int u, v, w;
      cin >> u >> v >> w;

      ull r = lca(u, v);
      update2(r, u, w);
      update2(r, v, w);
    }else{
      int u, v;
      cin >> u >> v;

      ull r = lca(u, v);
      ull c = cost2(r, u) + cost2(r, v);
      cout << c << endl;
    }
  }
}
