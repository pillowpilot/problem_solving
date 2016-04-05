#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <limits>

using namespace std;

typedef struct{
  string word;
  list<int> adj;
} vdata;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vdata> vv;
typedef map<string, int> msi;

vv g;
msi mapper;
vvi dist;

void initGraph(){
  g.clear();
  mapper.clear();
  dist.clear();
}

//O(lg V)
void addVertex(string& a){
  msi::iterator iter = mapper.find(a);
  if( iter == mapper.end() ){
    mapper[a] = g.size();
    g.push_back( {a, list<int>()} );
  }
}

bool distance(string& a, string& b){
  if( a.length() != b.length() ) return false;
  else{
    int diferences = 0;
    for(int i = 0; i < a.length(); i++){
      if( a[i] != b[i] ) diferences++;
    }
    return (diferences <= 1);
  }
}

void calculateEdges(){
  vv::iterator iter = g.begin();
  while( iter != g.end() ){
    vv::iterator iiter = g.begin();
    while( iiter != g.end() ){
      if( iter != iiter ){
	bool d = distance( iter->word, iiter->word );
	if( d == true ){
	  iter->adj.push_back( iiter - g.begin());
	  iiter->adj.push_back( iter - g.begin());
	}
      }
      iiter++;
    }
    iter++;
  }
}

void print(){
  vv::const_iterator iter = g.begin();
  while( iter != g.end() ){
    printf("[%s]: ", iter->word.data());
    list<int>::const_iterator iiter = iter->adj.begin();
    while( iiter != iter->adj.end() ){
      printf("%s ", g[*iiter].word.data());
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

void printDistances(){
  vvi::const_iterator iter = dist.begin();
  while( iter != dist.end() ){
    vi::const_iterator iiter = iter->begin();
    while( iiter != iter->end() ){
      if( *iiter == numeric_limits<int>::max() ) printf("inf ");
      else printf("%5d ", *iiter);
      iiter++;
    }
    printf("\n");
    iter++;
  }
}

void calculateDistances(){
  //Init distances in Infinity
  dist = vvi( g.size(), vi( g.size(), 1e4 ) );
  //Init d[u][u]=0 and d[u][v]=w[u][v]=1
  vv::iterator iter = g.begin();
  while( iter != g.end() ){
    int u = iter - g.begin();
    dist[u][u] = 0;
    list<int>::const_iterator iiter = g[u].adj.begin();
    while( iiter != g[u].adj.end() ){
      dist[u][*iiter] = 1;
      iiter++;
    }
    iter++;
  }
  //printDistances();
  //Optimize distances to optimal
  for(int k = 0; k < g.size(); k++){
    for(int u = 0; u < g.size(); u++){
      for(int v = 0; v < g.size(); v++){
	if( dist[u][v] > dist[u][k] + dist[k][v] ){
	  dist[u][v] = dist[u][k] + dist[k][v];
	}
      }
    }
  }
}

int main(){
  int cases;
  string w, a, b;
  char x[12], y[12];
  scanf("%d ", &cases); //Read cases and skip blank line
  if( cases != 0 ) g.reserve(205); //Reserve memory only once.
  while( cases-- > 0 ){
    initGraph();
    cin >> w;
    while( w != "*" ){
      addVertex(w);
      cin >> w;
    }
    calculateEdges();
    //print();
    calculateDistances();
    //printDistances();
    getline(cin, w);
    getline(cin, w);
    while( w.length() != 0 ){
      sscanf(w.data(), "%11s %11s", x, y);
      a = x; b = y;
      int u = mapper[a];
      int v = mapper[b];
      printf("%s %s %d\n", x, y, dist[u][v]);
      getline(cin, w);
    }
    if( cases != 0 ) printf("\n");
  }
  return 0;
}
