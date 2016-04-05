#include <cstdio>
#include <vector>
#include <queue>
#include <limits>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

vi distances;
vb marks;
vvi weights;

void dijkstra(int start, int target){
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q; //Pair<distance, vertexID>

  distances[start] = 0;
  marks[start] = true;
  q.push( make_pair( 0, start ) );

  while( !q.empty() ){
    //printf("At top <%d, %d>\n", q.top().first, q.top().second);
    int v = q.top().second;
    q.pop();
    marks[v] = true;

    for( int i = 0; i < weights[v].size(); i++ ){
      if( weights[v][i] != numeric_limits<int>::max() && marks[i] == false){
	distances[i] = min( distances[i], distances[v] + weights[v][i] );
	q.push( make_pair( distances[i], i ) );
      }
    }

  }
}

int main(){
  int N;

  scanf("%d ", &N);
  for( int css = 1; css <= N; css++ ){
    int n, m, s, t;

    scanf("%d %d %d %d ", &n, &m, &s, &t);
    weights = vvi( n, vi( n, numeric_limits<int>::max()));
    distances = vi( n, numeric_limits<int>::max());
    marks = vb( n, false);

    while( m-- > 0 ){
      int a, b, w;
      scanf("%d %d %d", &a, &b, &w);
      weights[a][b] = w;
      weights[b][a] = w;
    }
    
    dijkstra(s, t);

    printf("Case #%d: ", css);
    if( distances[t] == numeric_limits<int>::max() ){
      printf("unreachable\n");
    }else{
      printf("%d\n", distances[t]);
    }
  }
  return 0;
}
