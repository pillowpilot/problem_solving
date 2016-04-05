#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

struct edge{
  int a, b;
  ull cost;
  edge(int a, int b, ull cost):a(a), b(b), cost(cost){}
  bool operator<(const edge& e) const{
    return cost > e.cost;
  }
};

struct vertex{
  vector<edge> ee;
  vertex(){
    ee = vector<edge>();
    ee.reserve(555);
  }
};

map<string, int> mapper;
vector<int> parents;
vector<vertex> vv;
vector<bool> visited;

int findSet( int v ){
  if( parents[v] = 999 ){
    return v;
  }else{
    int parent = findSet( parents[v] );
    parents[v] = parent;
    return parent;
  }
}

void unionSet( int a, int b ){
  int pa = findSet( a ), pb = findSet( b );
  parents[pa] = pb;
}

ull dfs(int source){
  ull maxCost = 0;
  vertex v = vv[source];
  visited[source] = true;
  vector<edge>::const_iterator iter = v.ee.begin();
  while( iter != v.ee.end() ){
    if( visited[iter->b] == false ){
      ull cost = dfs( iter->b );
      if( cost > maxCost ) maxCost = cost;
    }
    iter++;
  }
  return maxCost;
}

int main(){
  int s, c;

  cin >> s >> c;
  while( s != 0 && c != 0 ){
    cout << "Leido " << s << " " << c << endl;

    vector<edge> ee = vector<edge>();
    ee.reserve( 80000 );
    mapper = map<string, int>();
    
    while( s-- > 0 ){
      string name;
      cin >> name;
      mapper[name] = mapper.size() + 1;
      cout << name << " mapeado a " << mapper.size() << endl;
    }
    while( c-- > 0 ){
      string a, b;
      ull c;
      cin >> a >> b >> c;
      ee.push_back( edge( mapper[a], mapper[b], c ) );
      cout << a << ", " << b << ": " << c << endl;
    }

    //Kruskal
    sort( ee.begin(), ee.end() );
    parents = vector<int>( mapper.size(), 999 );
    vv = vector<vertex>( mapper.size() );
    while( ee.size() > 0 ){
      edge e = ee.back();
      
      if( findSet( e.a ) != findSet( e.b ) ){
	unionSet( e.a, e.b );
	vv[e.a].ee.push_back( edge(e.a, e.b, e.cost) );
	vv[e.b].ee.push_back( edge(e.b, e.a, e.cost) );
      }

      ee.pop_back();
    }

    //DFS
    visited = vector<bool>(mapper.size(), false);
    string home;
    cin >> home;
    ull minCost = dfs(mapper[home]);
    cout << minCost << endl;

    cin >> s >> c;
  }
  return 0;
}
// Unsolved...
