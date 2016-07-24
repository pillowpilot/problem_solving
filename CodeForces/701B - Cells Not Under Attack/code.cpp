#include <cstdio>

using namespace std;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  int b[n][n];
  for(int i = 0 ; i < n; i++)
    for(int j = 0; j < n; j++)
      b[i][j]=0;
  
  long free = (long)(n)*n;
  while( m-- > 0 ){
    int x, y;
    scanf("%d %d", &x, &y);
    x--; y--;
    int na=0;
    if( b[x][y] == 0 ){
      na++;
      b[x][y] = 1;
    }
    

    int i = 1;
    while( x+i < n ){
      if( b[x+i][y] == 0 ){
	b[x+i][y] = 1;
	na++;
      }
      i++;
    }

    i = 1;
    while( x-i >=0 ){
      if( b[x-i][y] == 0 ){
	b[x-i][y] = 1;
	na++;
      }
      i++;
    }

    i = 1;
    while( y+i < n ){
      if( b[x][y+i] == 0 ){
	b[x][y+i] = 1;
	na++;
      }
      i++;
    }

    i = 1;
    while( y-i >=0 ){
      if( b[x][y-i] == 0 ){
	b[x][y-i] = 1;
	na++;
      }
      i++;
    }

    printf(">> %ld >>%d\n", free, na);
    free -= na;
    printf("%ld \n", free); // Make sure
  }
  printf("\n");
  return 0;
}
// 1e10 needed of memory. 
