#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n, d;
vi g[1010];
bool visited[1010];

int dfs(int nod){
  visited[nod] = true;
  int cnt = 1;
  for(int i = 0 ; i < g[nod].size();i++){
    if( visited[g[nod][i]] == false ){
      cnt += dfs(g[nod][i]);
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> d;

  for(int i = 0 ; i < n ;i++){
    g[i]=vi();
  }
  
  while( d-- ){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
  }

  int mininv = 1001;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      visited[j] = false;
    }
    int mincr = dfs(i);
    if( mincr < mininv )
      mininv = mincr;
  }

  cout << mininv << endl;
  return 0;
}

// AC
