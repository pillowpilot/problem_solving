#include <cstdio>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;

vvb graph;
vvb visited;
vi  depth;
vi  minDepth;

int dfs( int node, int d ){
  if( depth[node] == -1 ){
    depth[node] = minDepth[node] = d;
  }

  for( int i = 0; i < graph[node].size(); i++ ){
    if( graph[node][i] == true ){
      visited[node][i] = visited[i][node] = true;
      int md = dfs( i, d + 1 );
      minDepth[node] = min( minDepth[node], md );

      
    }
  }
}

int main(){
  int n;

  while( scanf("%d", &n) == 1 ){
    graph = vvb(n, vb( n, false) );
    visited = vvb(n, vb( n, false) );
    depth = vi( n, -1 );
    minDepth = vi( n, -1 );
    
    while( n-- > 0 ){
      int a, l;
      scanf("%d (%d)", &a, &l);
      while( l-- > 0 ){
	int b;
	scanf("%d", &b);

	graph[a][b] = graph[b][a] = true;
      }
    }

    solve();
  }
  return 0;
}

// Unfinished...
