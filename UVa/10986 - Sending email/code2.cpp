#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

int weights[20555][20555];
vvi adj;
vi distances;
vb marks;

void dijkstra(int start, int target ){
  priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
  
  distances[start] = 0;
  marks[start] = true;

  q.push( make_pair(0, start) );
  while( !q.empty()  ){
    int v = q.top().second;
    q.pop();

    marks[v] = true;
    vi::const_iterator iter = adj[v].begin();
    while( iter != adj[v].end() ){
      int n = *iter;
      if( marks[n] == false ){
	if( distances[v] + weights[v][n] < distances[n] ){
	  distances[n] = distances[v] + weights[v][n];
	  q.push( make_pair(distances[n], n) );
	}
      }
      iter++;
    }
    
  }
}

int main(){
  int N;

  scanf("%d ", &N);
  for( int css = 1; css <= N; css++ ){
    int n, m, s, t;
    
    scanf("%d %d %d %d ", &n, &m, &s, &t);
    
    //weights = vvi(n, vi( n, numeric_limits<int>::max() ) );
    adj = vvi( n, vi() );
    distances = vi( n, numeric_limits<int>::max() );
    marks = vb( n, false );

    while( m-- > 0 ){
      int a, b, w;

      scanf("%d %d %d ", &a, &b, &w);
      weights[a][b] = w;
      weights[b][a] = w;
      adj[a].push_back( b );
      adj[b].push_back( a );
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

// AC
