#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vb visited;
vi gr;
vvi g;
int maxB;

void dfs(int r, int depth){
  //printf("> [%d] %d %d\n", r, depth, gr[r]);
  maxB = max(maxB, depth*gr[r]);
  for(int n: g[r]){
    dfs(n, depth+1);
  }
  visited[r] = true;
}

int main(){
  int n, m;
  scanf(" %d %d ", &n, &m);
  g = vvi(n, vi());
  gr = vi(n);
  visited = vb(n, false);
  maxB = -1;
  while( m-- > 0 ){
    int a, b;
    scanf(" %d %d ", &a, &b);
    a--; b--;
    if( a > b ) swap(a, b);
    g[a].push_back(b);
    gr[a]++;
    gr[b]++;
  }
  /*
  for(int i = 0; i < g.size(); i++){
    printf("%d: ", i);
    for(int j = 0; j < g[i].size(); j++){
      printf("%d ", g[i][j]);
    }
    printf("\n");
  }
  */
  for(int v = 0; v < g.size(); v++){
    if( !visited[v] ){
      dfs(v, 1);
    }
  }
  printf("%d\n", maxB);
  return 0;
}
  

// Hacked
