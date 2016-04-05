#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k;
vvi dp;
vi grades; // If grades[v] == 1, then <v is leaf>.
vvi g;
vi parent;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << '[';

  if( v.size() > 0 ){
    auto iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  
  os << ']';
}

template <typename T>
ostream& operator<<(ostream& os, const vector< vector<T> > m){
  os << '[';

  if( m.size() > 0 ){
    auto iter = m.begin();
    os << *iter;
    iter++;
    while( iter != m.end() ){
      os << ", \n" << *iter;
      iter++;
    }
  }
  
  os << ']';
}


void dfs(int v){
  for(int n: g[v]){
    if( parent[n] == -1 ){
      parent[n] = v;
      dfs(n);
    }
  }
}

void makeTree(){
  for(int i = 0; i < g.size(); i++) g[i].clear();
  for(int v = 0; v < parent.size(); v++){
    if( parent[v] != v ) g[ parent[v] ].push_back(v); // Do not create loop in the root.
  }
}

int f(int v, int lvl){
  if( dp[v][lvl] != -1 ) return dp[v][lvl];
  int returnValue;
  if( lvl == 0 ) returnValue = 1;
  else if( grades[v] == 1 && v != 0 ) returnValue = 0;
  else{
    returnValue = 0;
    for(int child: g[v]){
      returnValue += f(child, lvl-1);
    }
  }
  dp[v][lvl] = returnValue;
  return returnValue;
}

// O(nk) because of memoization in f
void fillDP(){
  for(int v = 0; v < g.size(); v++){
    for(int lvl = 0; lvl <= k; lvl++){
      f(v, lvl);
    }
  }
}


int main(){
  scanf("%d %d", &n, &k);
  dp = vvi( n, vi(k+1, -1) );
  grades = vi(n, 0);
  g = vvi( n, vi() );
  parent = vi( n, -1 );

  while( n-- > 1 ){
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
    grades[a]++;
    grades[b]++;
  }
  n = g.size();

  parent[0] = 0;
  dfs(0); // Construct Tree with root at Node 0;
  makeTree();
  fillDP();
  cout << dp << endl;
  
  
  return 0;
}

