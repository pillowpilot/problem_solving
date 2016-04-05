#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct{
  int vertexID;
  bool visited;
}edge;

typedef struct{
  int depth;
  list<edge> adj;
}vertex;

void initGraph(map< int, vertex > &vs, int n);
void addEdge(map< int, vertex > &vs, int a, int b);
void printGraph(const map< int, vertex > &vs);

int dfs(map<int, vertex> &vs, int depth, int source){
  if( vs[source].depth == 0 ){
    vs[source].depth = depth;
  }

  list<edge>::const_iterator iter = vs[source].adj.begin();
  while(iter != vs[source].adj.end() ){
    int neighborDepth = vs[iter->vertexID].depth;
    if( neighborDepth == 0 ){
      dfs(vs, depth + 1, iter->vertexID);
    }else{
      return min(depth, neighborDepth);
    }
    iter++;
  }
}

void f(map< int, vertex > &vs){
  int depth = 0, source = 1;
  stack<int> s;

  s.push(source);
  while( !s.empty() ){
    int vertex = s.top();
    s.pop();

    if(vs[vertex].depth == 0){
      vs[vertex].depth = depth++;
    }
    printf("%2d ", vertex);

    list<edge>::iterator fowardEdge = vs[vertex].adj.begin();
    while( fowardEdge != vs[vertex].adj.end() ){
      if( !fowardEdge->visited ){
	fowardEdge->visited = true;
	list<edge>::iterator returnEdge = vs[fowardEdge->vertexID].adj.begin();
	while( returnEdge != vs[fowardEdge->vertexID].adj.end() ){
	  if( returnEdge->vertexID == vertex ) returnEdge->visited = true;
	  returnEdge++;
	}
	s.push(fowardEdge->vertexID);
      }
      fowardEdge++;
    }
  }
  cout << endl;
}

int main(){
  int n, a, b;
  string line;
  stringstream ss;
  map< int, vertex > vs;

  cin >> n;
  while( n != 0 ){
    initGraph(vs, n);
    
    cout << "Leido n:" << n << endl;
    cin >> a;
    while( a != 0 ){
      getline(cin, line);
      ss.clear();
      ss.str(line);

      while( ss >> b ){
	cout << a << " conectado a " << b << endl;
	addEdge(vs, a, b);
	addEdge(vs, b, a);
	
      }

      cin >> a;
    }

    printGraph(vs);cout << endl;

    //f(vs);
    dfs(vs, 1, 1); cout << endl;

    printGraph(vs);

    cin >> n;
  }

  return 0;
}

void initGraph(map< int, vertex > &vs, int n){
  vs.clear();
  while(n-- > 0){
    vs[n + 1] = {0, list<edge>()};
  }
}

void addEdge(map< int, vertex > &vs, int a, int b){
  vs[a].adj.push_back( {b, false} );
}

void printGraph(const map< int, vertex > &vs){
  map< int, vertex >::const_iterator iter = vs.begin();
  while( iter != vs.end() ){
    printf("(%2d, %2d)->", iter->first, iter->second.depth);
    list<edge>::const_iterator iiter = iter->second.adj.begin();
    while( iiter != iter->second.adj.end() ){
      printf("[%2d, %c] ", iiter->vertexID, (iiter->visited)?'T':'F');
      iiter++;
    }
    printf("\n");
    iter++;
  }
}
