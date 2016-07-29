#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 100000;
int t, n, m;
ull bananas[N];
vi graph[N];
int visited[N];

ull dfs(int nd){
  visited[nd] = 1;
  ull cnt = bananas[nd];
  for(int i = 0; i < graph[nd].size(); i++){
    if( visited[graph[nd][i]] == false ){
      cnt += dfs(graph[nd][i]);
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> t;
  while( t-- > 0 ){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
      graph[i] = vi();
      visited[i] = 0;
    }

    while( m-- > 0 ){
      int x, y;
      cin >> x >> y;
      x--; y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }

    for(int i = 0; i < n; i++){
      ull x;
      cin >> x;
      bananas[i] = x;
    }

    ull max_p = 0;
    for(int i = 0 ; i < n; i++){
      if(visited[i] == 0){
	ull p = dfs(i);
	max_p = max(max_p, p);
      }
    }

    cout << max_p << endl;
  }
  
  return 0;
}

// AC
