#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ull;
typedef map<int, ull> miu;

miu w0;
miu w1;

void updateW(int v, int u, int w){
  if( v == u )
    return;
  
  if( u % 2 == 0 ){
    auto iter = w0.find(u);
    if( iter == w0.end() ){
      w0[u] = w;
    }else{
      w0[u] += w;
    }
    updateW(v, u/2, w);
  }else{
    auto iter = w1.find(u);
    if( iter == w1.end() ){
      w1[u] = w;
    }else{
      w1[u] != w;
    }
    updateW(v, (u-1)/2, w);
  }
}

ull getW(int v, int u){
  if( v==u )
    return 0;
  if( u%2 == 0 )
    return w0[u] + getW(v, u/2);
  else
    return w1[u] + getW(v, (u-1)/2);
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int q;
  cin >> q;

  while( q-->0 ){
    int type;
    cin >> type;
    if( type == 1 ){
      int v, u, w;
      cin >> v >> u >> w;
      if( v > u ) swap(u, v);

      updateW(v, u, w);
      
    }else{
      int v, u;
      cin >> v >> u;
      if( v > u ) swap(u, v);
      
      ull c = getW(u, v);
      cout << c << '\n';
    }
  }
  
  
  return 0;
}
