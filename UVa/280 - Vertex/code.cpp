#include <cstdio>
#include <vector>
#include <limits>

#define INF 10000

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi weights;
vvi paths;

void fw(){
  int n = weights.size();

  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < n; j++ ){
      paths[i][j] = weights[i][j];
    }
  }

  for( int k = 0; k < n; k++ ){
    for( int i = 0; i < n; i++ ){
      for( int j = 0; j < n; j++ ){
	paths[i][j] = min( paths[i][j], paths[i][k] + paths[k][j] );
      }
    }
  }
}

int main(){
  int n, i, j, q;

  while( scanf("%d", &n) == 1 && n != 0 ){
    weights = vvi( n, vi( n, INF ) );
    paths = vvi( n, vi( n, INF ) );
    while( scanf("%d", &i) == 1 && i != 0 ){
      i--;
      while( scanf("%d", &j) == 1 && j != 0 ){
	j--;
	weights[i][j] = 1;
      }
    }
    /*for(int i = 0; i < n; i++ ){
      for(int j = 0; j < n; j++ ){
	printf("%7d ", weights[i][j]);
      }
      printf("\n");
      }*/
    fw();
    /*printf("---\n");
    for(int i = 0; i < n; i++ ){
      for(int j = 0; j < n; j++ ){
	printf("%7d ", paths[i][j]);
      }
      printf("\n");
      }*/
    scanf("%d", &q);
    while( q-- > 0 ){
      vi targets = vi();
      int origin;
      scanf("%d", &origin);
      origin--;
      for( int i = 0; i < paths[origin].size(); i++ ){
	if( paths[origin][i] == INF ){
	  targets.push_back( i + 1);
	}
      }
      printf("%lu", targets.size());
      for( int i = 0; i < targets.size(); i++ ){
	printf(" %d", targets[i]);
      }
      printf("\n");
    }
  }
  return 0;
}

// AC
