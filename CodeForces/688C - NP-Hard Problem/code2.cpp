#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;


/* Check if the graph is bipartite by BFS and print colors
 */
int main(){
  int n, m;

  cin >> n >> m;

  vi g[n];
  int status[n] = {0};
  
  while(m-->0){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bool isPossible = true;
  for(int i = 0; i < n && isPossible; i++){
    if( g[i].size() >= 1 && status[i] == 0 ){ // Ignore lonely vertex XD
      queue<int> q;
      q.push(i);
      status[i] = 1;
      while( !q.empty() && isPossible ){
	int v = q.front();
	q.pop();

	int n_status = (status[v]==1)?2:1;
	for(int u: g[v]){
	  if( status[u] == 0 ){
	    status[u] = n_status;
	    q.push(u);
	  }else if( status[u] != n_status )
	    isPossible = false;
	}
      }
    }
  }

  if( !isPossible ){
    cout << "-1" << endl;
  }else{
    vi set1, set2;

    for(int i = 0; i < n; i++){
      if( status[i] == 1 )
	set1.push_back(i);
      else if( status[i] == 2 )
	set2.push_back(i);
    }

    cout << set1.size() << '\n';
    for(int v: set1)
      cout << v + 1 << ' ';
    cout << '\n';

    cout << set2.size() << '\n';
    for(int v: set2)
      cout << v + 1<< ' ';
    cout << '\n';
  }
  return 0;
}

// AC
