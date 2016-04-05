#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
  int u, v, w;
} edata;
typedef vector<int> vi;

struct SortByWeight{
  bool operator()(const edata& a, const edata& b){
    return a.w > b.w;
  }
};

vi parent;
priority_queue<edata, vector<edata>, SortByWeight> es;

void initGraph(int v){
  parent.clear();
  parent.reserve(v);
  for(int i = 0; i < v; i++){
    parent.push_back(i);
  }
  while( !es.empty() ){
    es.pop();
  }
}

void addEdge(int u, int v, int w){
  edata edge;
  edge.u = u;
  edge.v = v;
  edge.w = w;
  es.push(edge);
}

int find(int i){
  if( parent[i] == i ) return i;
  else{
    int setID = find( parent[i] );
    parent[i] = setID;
    return setID;
  }
}

void unionSet(int i, int j){
  parent[ find(i) ] = find(j);
}

int kruskal(){
  int cost = 0;
  int sets = parent.size();
  while( !es.empty() && sets > 1){
    edata e = es.top();
    es.pop();
    int setA = find(e.u);
    int setB = find(e.v);
    if( setA != setB ){
      unionSet(setA, setB);
      cost += e.w;
      sets--;
    }
  }
  return cost;
}

int main(){
  int m, n, u, v, w, totalCost;
  scanf("%d %d", &m, &n);
  while( !(m == 0 && n == 0) ){
    initGraph(m);
    int cost, totalCost = 0;
    while( n-- > 0 ){
      scanf("%d %d %d", &u, &v, &w);
      totalCost += w;
      addEdge(u, v, w);
    }
    cost = kruskal();
    printf("%d\n", totalCost - cost);
    scanf("%d %d", &m, &n);
  }
}
