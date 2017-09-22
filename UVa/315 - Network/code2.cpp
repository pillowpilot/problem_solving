#include <bits/stdc++.h>
#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vvi g;
vi parent;
vi discovery;
vi lowest;
vb isVisited;
vb isArticulation;
int gtime;

void dfs(int v){
  isVisited[v] = true;
  lowest[v] = discovery[v] = gtime++;
  rep(i, 0, g[v].size()){
    int n = g[v][i];
    if( !isVisited[n] ){
      parent[n] = v;
      dfs(n);
      if( discovery[v] <= lowest[n] ) isArticulation[v] = true;
      // TODO check bridge
      lowest[v] = min(lowest[v], lowest[n]);
    }else if(n != parent[v]){ // backedge and not direct cycle
      lowest[v] = min(lowest[v], discovery[n]);
    }
  }
}

int articulationPoints(){
  int n = g.size();
  parent.resize(n);
  discovery.resize(n);
  lowest.resize(n);
  isVisited.assign(n, false);
  isArticulation.assign(n, false);

  gtime = 0;

  rep(i, 0, n){
    if( !isVisited[i] ){
      parent[i] = -1;
      rootChildren = 0;
      dfs(i, i);
      int rootChildren = 0;
      rep(i, 0, n){
	if( parent[i] == i )
	  rootChildren++;
      }
      isArticulation[i] = (2 <= rootChildren);
    }
  }
  
  int ans = 0;
  rep(i, 0, n){
    if( isArticulation[i] )
      ans++;
  }
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  while( cin >> n && n != 0 ){
    g.assign(n, vi());
    int a;
    while( cin >> a && a != 0 ){
      a--;
      string line;
      getline(cin, line);
      stringstream oss(line);
      debug(line);

      int b;
      while( oss >> b ){
	b--;
	g[a].push_back(b);
	g[b].push_back(a);
      }

    }

    int ans = articulationPoints();
    cout << ans << "\n";
  }

  return 0;
}

// AC
/*
  Trivial aplication of articulation points. Extended DFS.
  Read the algorithm. For every non root node, check if an ancestor is reachable from a descendant.
  For the root, check if its out degree is > 1.
 */
