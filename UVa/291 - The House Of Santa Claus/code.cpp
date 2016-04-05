#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

typedef unsigned int uint;
typedef vector< uint > vu;
typedef vector< bool > vb;
typedef vector< vb > vvb;
typedef list< uint > lu;
typedef list< lu > llu;

vvb mi;
vvb visited;
lu solution;
llu solutions;

void processEdgeEarly(uint u, uint v){
  visited[u][v] = true;
  visited[v][u] = true;
  solution.push_back( v );
}

void processEdgeLate(uint u, uint v){
  visited[u][v] = false;
  visited[v][u] = false;
  solution.pop_back();
}

void dfs(uint u){
  if( solution.size() == 9 ){
    solutions.push_back( solution );
  }

  vb::iterator iter = mi[u].begin();
  while( iter != mi[u].end() ){
    uint v = iter - mi[u].begin();
    if( mi[u][v] == true && visited[u][v] == false ){
      processEdgeEarly(u, v);
      dfs(v);
      processEdgeLate(u, v);
    }
    iter++;
  }
}

void solve(){
  solutions.clear();
  visited = vvb( 5, vb(5, false) );
  solution.clear();
  solution.push_back(0);
  dfs(0);
}

void initGraph(){
  mi.reserve( 5 );
  mi.push_back( vb({false, true, true, false, true}) );
  mi.push_back( vb({true, false, true, false, true}) );
  mi.push_back( vb({true, true, false, true, true}) );
  mi.push_back( vb({false, false, true, false, true}) );
  mi.push_back( vb({true, true, true, true, false}) );
}

void sortSolutions(){
  vu ss;
  uint a;
  ss.reserve(100);
  llu::const_iterator s = solutions.begin();
  while( s != solutions.end()){
    a = 0;
    lu::const_iterator u = s->begin();
    while( u != s->end() ){
      a = a*10 + *u + 1;
      u++;
    }
    ss.push_back( a );
    s++;
  }

  sort(ss.begin(), ss.end());
  
  vu::const_iterator sol = ss.begin();
  while( sol != ss.end() ){
    printf("%u", *sol);
    printf("\n");
    sol++;
  }
}

int main(){
  initGraph();
  solve();
  sortSolutions();
  return 0;
}
