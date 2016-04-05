#include <cstdio>
#include <vector>
#include <limits>

#define INF 500

using namespace std;

struct Edge{
  int cap, flow;
  Edge(){ cap = flow = 0; }
  Edge(int cap, int flow):cap(cap), flow(flow) {}
};

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<Edge> ve;
typedef vector<ve> vve;

vi path;
vb marks;
vve adj;

void pm(){
  for( int i = 0; i < adj.size(); i++ ){
    for( int j = 0; j < adj[i].size(); j++ ){
      printf(" %3d:%3d |", adj[i][j].cap, adj[i][j].flow);
    }
    printf("\n");
  }
}

bool findPath(int source, int sink){
  marks[source] = true;
  if( source == sink ){
    path.push_back(source);
    marks[source] = false;
    return true;
  }else{
    int i = 0;
    bool pathFound = false;
    while( !pathFound && i < adj[source].size() ){
      if( adj[source][i].cap != 0 && marks[i] == false && adj[source][i].cap - adj[source][i].flow > 0 ) pathFound = findPath(i, sink);
      i++;
    }
    if( pathFound == true ){
      path.push_back(source);
    }
    marks[source] = false;
    return pathFound;
  }
}

int calculateFlow(){
  int flow = INF;
  for(int i = path.size() - 1; i > 0; i-- ){
    int u = path[i], v = path[i-1];
    flow = min( flow, adj[u][v].cap - adj[u][v].flow );
  }
  return flow;
}

void applyFlow(int flow){
  for(int i = path.size(); i > 0; i-- ){
    int u = path[i], v = path[i-1];
    adj[u][v].flow += flow;
    adj[v][u].flow -= flow;
  }
}

void pp(){
  if( path.size() != 0 ){
    printf("Camino: ");
    for(int i = 0; i < path.size(); i++){
      printf("%d ", path[i]);
    }
    printf("\n");
  }else{
    printf("Sin camino\n");
  }
}

int ff(int source, int sink){
  path = vi();
  marks = vb(adj.size(), false);
  findPath(source, sink);
  while( path.size() != 0 ){
    int flow = calculateFlow();
    printf("Flow: %d\n", flow);
    applyFlow( flow );

    path = vi();
    marks = vb(adj.size(), false);
    findPath(source, sink);
  }

  int maxFlow = 0;
  for(int i = 0; i < adj[0].size(); i++ ){
    maxFlow += adj[0][i].flow;
  }
  return maxFlow;
}

int main(){
  int n, m, b, d;


  while( scanf("%d ", &n) == 1 ){
    
    adj = vve( 2*n+3, ve( 2*n+3 ) );
    
    for(int i = 1; i <= n; i++){
      int c;
      scanf("%d ", &c);
      adj[2*i][2*i+1] = Edge(c, 0);
      adj[2*i+1][2*i] = Edge(c, c);
    }

    scanf("%d ", &m);
    for(int i = 0; i < m; i++ ){
      int a, b, c;
      scanf("%d %d %d ", &a, &b, &c);
      adj[2*a+1][2*b] = Edge(c, 0);
      adj[2*b+1][2*a] = Edge(c, c);
    }

    scanf("%d %d ", &b, &d);
    for(int i = 0; i < b; i++ ){
      int v;
      scanf("%d ", &v);
      adj[0][2*v] = Edge(INF, 0);
      adj[2*v][0] = Edge(INF, INF);
    }
    for(int i = 0; i < d; i++ ){
      int v;
      scanf("%d ", &v);
      adj[2*v+1][2*n+2] = Edge(INF, 0);
      adj[2*n+2][2*v+1] = Edge(INF, INF);
    }

    int maxFlow = 0;
    maxFlow = ff(0, 2*n+2);

    printf("%d\n", maxFlow);
  }
  
  return 0;
}
