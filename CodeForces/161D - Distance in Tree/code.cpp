#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k;

vvi c;
vvi g;
vi depth;

void bfs(int r){
  c = vvi( k, vi(n, 0) );
  
  queue q();
  q.push(r);
  depth[r] = 0;

  while( !q.empty() ){
    int v = q.top();
    q.pop();

    for(int n: g[v]){
      if( depth[n] == -1 && depth[v] + 1 <= k){
	q.push(n);
	depth[n] = depth[v] + 1;
      }
    }
  }
}

ll f(int r){

  dfs(r);
  

  // Destruir las aristas entre r y sus hijos al llamar recursivamente...
}

int main(){
  cin >> n >> k;
  
  g = vvi( n, vi() );
  depth = vi( n, -1 );

  while( n-- > 0 ){
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  
  return 0;
}


// Incomplete...
