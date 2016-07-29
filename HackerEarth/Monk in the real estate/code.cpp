#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int N = (int) 1e5;
int t, m;
vi g[N];
int v[N];

int dfs(int nd){
  v[nd] = 1;
  int cnt = 1;
  for(int i = 0 ; i  < g[nd].size(); i++){
    int nbr = g[nd][i];
    if( v[nbr] == 0 ){
      cnt += dfs(nbr);
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  cin >> t;
  while( t-- > 0 ){
    cin >> m;

    for(int i = 0; i < N; i++){
      g[i] = vi();
      v[i] = 1; // Initialy all are 'visited'
    }

    int x, y;
    while( m-- > 0 ){
      cin >> x >> y;
      x--; y--;

      g[x].push_back(y);
      g[y].push_back(x);
      v[x] = 0; // Then we make 'available' the ones listed in the edges..
      v[y] = 0;
    }

    int cities = 0;
    for(int i = 0 ; i < N; i++){
      if( v[i] == 0 ){
	cities+=dfs(i);
      }
    }

    cout << cities << endl;
  }
  
  return 0;
}

// AC
