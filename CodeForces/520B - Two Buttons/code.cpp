#include <cstdio>
#include <queue>
#include <functional>
#include <limits>
#include <map>

#define INF std::numeric_limits<int>::max()

using namespace std;

typedef pair<int, int> ii;
typedef map<int, int> mii;

mii distances;
mii marks;

void dijkstra(int start, int target){
  priority_queue<ii, vector<ii>, greater<ii> > q;

  distances[start] = 0;
  marks[start] = 1;

  q.push( make_pair(0, start) );
  while( !q.empty() && q.top().second != target ){
    int v = q.top().second;
    q.pop();

    printf("%d\n", v);

    marks[v] = 1;

    if( marks.find(2*v) == marks.end() && ( distances.find(2*v) == distances.end() || distances[v] + 1 < distances[2*v] ) ){
      distances[2*v] = distances[v] + 1;
      q.push( make_pair( distances[2*v], 2*v ) );
    }

    if( marks.find(v-1) == marks.end() && ( distances.find(v-1) == distances.end() || distances[v] + 1 < distances[v-1] ) ){
      distances[v-1] = distances[v] + 1;
      q.push( make_pair( distances[v-1], v-1 ) );
    }
    
  }
}

int main(){
  int n, m;

  scanf("%d %d", &n, &m);

  distances = mii();
  marks = mii();
  
  dijkstra(n, m);
  
  printf("%d\n", distances[m]);

  return 0;
}
