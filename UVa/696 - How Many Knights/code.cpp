#include <cstdio>
#include <cmath>

int f(int x, int y){
  return (int) ceil( ((double)x)/((double)y) );
}
int g(int x, int y){
  return (int) floor( ((double)x)/((double)y) );
}
void swap(int& a, int& b){
  int c = a;
  a = b;
  b = c;
}
int case2(int n){
  int r = 4 * g(n, 4);
  switch( n % 4 ){
  case 0:
    r += 0;
    break;
  case 1:
    r += 2;
    break;
  default:
    r += 4;
    break;
  }
  return r;
}

int main(){
  int row, col;

  while( scanf("%d %d", &row, &col) == 2 && !(row == 0 && col == 0) ){
    bool swaped = false;
    int r;
    if( col < row ){
      swap( row, col ); // Now, row <= col
      swaped = true;
    }
    
    if( row == 0 ) r = 0;
    else if( row == 1 ) r = col;
    else if( row == 2 ) r = case2(col);
    else r = f(row, 2)*f(col, 2) + g(row, 2)*g(col, 2); // (row*col - 1) / 2..??
    
    if( swaped == true ) swap( row, col );
    printf("%d knights may be placed on a %d row %d column board.\n", r, row, col);
  }
  return 0;
}

// AC
