#include <cstdio>
#include <cmath>

using namespace std;

int f( int x ){
  return (int) ceil( ((double)x) / 2 );
}
int g( int x ){
  return (int) floor( ((double)x) / 2 );
}
int min( int a, int b ){
  return (a < b)?a:b;
}

int main(){
  int n;

  scanf("%d", &n);
  while( n-- > 0 ){
    char p; int row, col, r;
    scanf(" %c %d %d ", &p, &row, &col);
    switch( p ){
    case 'r': // Rook
      r = min( row, col );
      break;
    case 'k': // Knight
      r = f( col ) * f( row ) + g( col ) * g( row );
      break;
    case 'Q': // Queen
      r = min( row, col );
      break;
    case 'K': // King
      r = f( row ) * f( col );
      break;
    }
    printf("%d\n", r);
  }
  return 0;
}

// AC
