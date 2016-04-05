#include <cstdio>
#include <vector>
#include <list>
#include <limits>

#define inf numeric_limits<unsigned int>::max()

using namespace std;

typedef unsigned int uint;
typedef vector<uint> vu;
typedef vector<vu> vvu;

vvu mi;
vector< vector<bool> > visited; 
list<uint> solution;
list< list<uint> > solutions;

void printSolution(){
  list<uint>::const_iterator iter = solution.begin();
  while( iter!=solution.end() ){
    printf("%u ", *iter + 1);
    iter++;
  }
  printf("\n");
}

void dfs(uint u){
  if( solution.size() == 9 ){
    printSolution();
  }

  vu::const_iterator iter = mi[u].begin();
  while( iter != mi[u].end() ){
    uint v = iter - mi[u].begin();
    if( mi[u][v] == 1 && visited[u][v] == false ){
      visited[u][v] = true;
      visited[v][u] = true;
      solution.push_back( v );
      dfs(v);
      solution.pop_back();
      visited[u][v] = false;
      visited[v][u] = false;
    }
    iter++;
  }
}

void bt(){
  visited = vector< vector<bool> >(5, vector<bool>(5, false));
  solutions.clear();

  for(uint index = 0; index < mi.size(); index++){
    solution.clear();
    solution.push_back(index);
    dfs(index);
  }
}

void initializeGraph(){
  mi.push_back( vector<uint>({0, 1, 1, 0, 1}) );
  mi.push_back( vector<uint>({1, 0, 1, 0, 1}) );
  mi.push_back( vector<uint>({1, 1, 0, 1, 1}) );
  mi.push_back( vector<uint>({0, 0, 1, 0, 1}) );
  mi.push_back( vector<uint>({1, 1, 1, 1, 0}) );
}

int main(){
  initializeGraph();
  bt();
  return 0;
}
