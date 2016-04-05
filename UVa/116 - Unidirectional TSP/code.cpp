#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int n, m;
vvb marks;
vvi f, g, paths;

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

    f[i][j] = min( a, min( b, c ) );
    f[i][j] += g[i][j];
    marks[i][j] = true;
    
    return f[i][j];
  }
}

bool pr(int i, int j, vi& p){
  if( j == 0 ){
    p.push_back( i + 1 );
    paths.push_back( p );
    p.pop_back();
  }else{
    vi options = vi({(i == 0  )?n-1:i-1, i, (i == n-1)?0  :i+1});
    for( int index = 0; index < 3; index++ ){
      if( f[ options[index] ][ j-1 ] == f[i][j] - g[i][j] ){
	p.push_back( i + 1 );
	pr( options[index], j - 1, p );
	p.pop_back();
      }
    }
  }
}

void pmi(const vvi& v){
  for( int i = 0; i < v.size(); i++ ){
    for( int j = 0; j < v[i].size(); j++ ){
      printf("%2d ", v[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
void pmb(const vvb& v){
  for( int i = 0; i < v.size(); i++ ){
    for( int j = 0; j < v[i].size(); j++ ){
      printf("%c ", (v[i][j] == true)?'T':'F');
    }
    printf("\n");
  }
  printf("\n");
}


int main(){
  int r;
  
  while( scanf("%d %d ", &n, &m) == 2 ){
    f = vvi( n, vi(m));
    g = vvi( n, vi(m));
    marks = vvb( n, vb(m, false));
    paths = vvi();
    r = numeric_limits<int>::max();
    
    for( int i = 0; i < n; i++ ){
      for( int j = 0; j < m; j++ ){
	int a;
	scanf("%d ", &a);
	g[i][j] = a;
      }
    }
    
    for( int i = 0; i < n; i++ ){
      dp(i, m-1);
    }

    for( int i = 0; i < n; i++ ){
      r = min( r, f[i][m-1] );
    }

    for( int i = 0; i < n; i++ ){
      if( f[i][m-1] == r ){
	vi p = vi();
	pr( i, m-1, p);
      }
    }

    sort( paths.begin(), paths.end() );
    
    bool space = false;
    for( int i = paths[0].size() - 1; i >= 0; i-- ){
      if( space == true ) printf(" ");
      space = true;
      printf("%d", paths[0][i]);
    }
    
    printf("\n%d\n", r);
  
  }
  return 0;
}

// TLE
