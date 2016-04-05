#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <string>

using namespace std;

typedef struct{
  bool visited;
  char id;
  list<int> adj;
} vdata;
typedef vector<vdata> vv;

vv g;

int mapper(char c){
  return c - 'A';
}

void initGraph(char m){
  int maxID = mapper(m);
  g.clear();
  g = vv(maxID + 1);
  vv::iterator iter = g.begin();
  while(iter!=g.end()){
    iter->visited = false;
    iter++;
  }
}

void addEdge(char a, char b){
  int u = mapper(a), v = mapper(b);
  g[u].id = a;
  g[v].id = b;
  g[u].adj.push_back( v );
  g[v].adj.push_back( u );
}

void print(){
  vv::const_iterator iter = g.begin();
  while( iter != g.end() ){
    printf("[%ld]: ", iter - g.begin());
    list<int>::const_iterator iiter = iter->adj.begin();
    while( iiter != iter->adj.end() ){
      printf("%d ", *iiter);
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

void dfs(int s){
  list<int>::const_iterator iter = g[s].adj.begin();
  while(iter!=g[s].adj.end()){
    if( g[*iter].visited == false ){
      g[*iter].visited = true;
      dfs( *iter );
    }
    iter++;
  }
}

int cc(){
  int comps = 0;
  vv::iterator iter = g.begin();
  while( iter != g.end() ){
    if( iter->visited == false ){
      comps++;
      dfs(iter - g.begin());
    }
    iter++;
  }
  return comps;
}

int main(){
  int cases;
  char a, b;
  string line;
  getline(cin, line);
  sscanf(line.data(), "%d", &cases);
  getline(cin, line); // Read empty line
  while( cases-- > 0 ){
    getline(cin, line); // Read max node id
    sscanf(line.data(), "%c", &a);
    initGraph(a);
    getline(cin, line);
    while( line.length() != 0 ){
      sscanf(line.data(), "%c%c", &a, &b);
      addEdge(a, b);
      getline(cin, line);
    }
    //print();
    printf("%d\n", cc());
    if( cases > 0 ) printf("\n");
  }
}
