#include <cstdio>
#include <vector>

#define NOCOLOR 0
#define COLORA 1
#define COLORB 2

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vvb graph; // Edges
vvb visited; // Visited Edges
vi color; // Colors

bool dfs( int node, int c ){
  if( color[node] != NOCOLOR ){
    if( color[node] != c ) return false;
  }
  color[node] = c;
  
  for( int i = 0; i < graph.size(); i++ ){
    if( graph[node][i] == true && !visited[node][i] ){
      visited[node][i] =  visited[i][node] = true;
      
      if( dfs(i, (c == COLORA)?COLORB:COLORA ) == false ) return false;
    }
  }
  return true;
}

int main(){
  int n;

  while( scanf("%d", &n ) == 1 && n != 0 ){
    graph = vvb( n, vb( n, false ) );
    visited = vvb( n, vb( n, false ) );
    color = vi( n, NOCOLOR );
    
    int l;
    scanf("%d", &l);
    while( l-- > 0 ){
      int a, b;
      scanf("%d %d", &a, &b);
      graph[a][b] = graph[b][a] = true;
    }
    
    printf("%s\n", (dfs(0, COLORA) == true)?"BICOLORABLE.":"NOT BICOLORABLE.");
  }
  return 0;
}

// AC: DFS over a stringly connected graph, keeping record of traversed edges.
