#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
vvi g;

int solve(){
  int m = -99999, n = v.size();

  for( int i = 0; i < n; i++ ){
    g[i][i] = (v[i] == 1)?-1:+1;
    if( g[i][i] > m ) m = g[i][i];
    for( int j = i + 1; j < n; j++ ){
      g[i][j] = g[i][j-1];
      g[i][j] += (v[j] == 0)?+1:-1;
      if( g[i][j] > m ) m = g[i][j];
    }
  }
  return m;
}

void init(int n){
  v = vi();
  g = vvi(n, vi(n));
}

int main(){
  int n, r = 0;

  scanf("%d", &n);
  init(n);
  while( n-- > 0 ){
    int a;
    scanf("%d", &a);
    v.push_back(a);
    r += (a == 1)?1:0;
  }

  r += solve();
  printf("%d", r);
  return 0;
}
