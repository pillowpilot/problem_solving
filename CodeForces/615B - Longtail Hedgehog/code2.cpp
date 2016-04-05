#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi g;
vi dp;

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  g = vvi(n);
  dp = vi(n, 1);
  while(m-->0){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int v = 0; v < g.size(); v++){
    for(int u: g[v]){
      if( u < v ){
	dp[v] = max(dp[v], dp[u] + 1);
      }
    }
  }
  unsigned long long maxB = 0;
  for(int i = 0; i < dp.size(); i++){
    maxB = max(maxB, (unsigned long long) (g[i].size())*dp[i]);
    // g[i].size() must be converted to ull.. or ll...
  }

  cout << maxB << endl;
  
  return 0;
}

// AC
