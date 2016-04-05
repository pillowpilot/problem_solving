#include <cstdio>
#include <vector>
#include <limits>

#define INF numeric_limits<int>::max()

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int n, m;
vvi f, g;
vvb marks;

int dp(int i, int j){
  if( marks[i][j] == true ){
    return f[i][j];
  }
  if( j == 0 ){
    f[i][j] = g[i][j];
    marks[i][j] = true;    
    return f[i][j];
  }else{
    int a, b, c;
    a = dp( (i == 0  )?n-1:i-1, j - 1 );
    b = dp(                  i, j - 1 );
    c = dp( (i == n-1)?0  :i+1, j - 1 );

    f[i][j] = min( a, min( b, c ) ) + g[i][j];
    marks[i][j] = true;
    return f[i][j];
  }
}

int main(){
  int r;
  
  while( scanf("%d %d ", &n, &m) == 2 ){
    r = INF;
    f = vvi(n, vi(m));
    g = vvi(n, vi(m));
    marks = vvb(n, vb(m, false));
    
    for( int i = 0; i < n; i++ ){
      for( int j = 0; j < m; j++ ){
	int a;
	scanf("%d ", &a);
	g[i][j] = a;
      }
    }

    for( int i = 0; i < n; i++ ){
      r = min( r, dp(i, m - 1) );
    }

    printf("%d\n", r);
    
  }
  return 0;
}

// Unfinished
