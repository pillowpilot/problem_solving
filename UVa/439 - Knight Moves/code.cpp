#include <cstdio>
#include <vector>
#include <list>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi board;

bool isValid(int x, int y){
  return 0 <= x && 0 <= y && x < board.size() && y < board[x].size();
}

int bfs(int a[2], int b[2]){
  int offset[] = {-2, -1, +1, +2, +2, +1, -1, -2, -2, -1, +1};
  list<int> q1 = list<int>();
  list<int> q2 = list<int>();

  board[ a[0] ][ a[1] ] = 0;

  q1.push_back( a[0] );
  q2.push_back( a[1] );

  while( q1.size() > 0 ){
    int n = q1.front(), m = q2.front();
    q1.pop_front(); q2.pop_front();

    for( int move = 0; move < 8; move++ ){
      int x = n + offset[move], y = m + offset[move + 2];
      if( isValid(x, y) == true && board[x][y] == numeric_limits<int>::max()){
	board[x][y] = board[n][m] + 1;
	q1.push_back( x );
	q2.push_back( y );
      }
    }
  }

  /*for( int i = 0; i < 8; i++ ){
    for( int j = 0; j < 8; j++ ){
      printf("%2d ", (board[i][j] == numeric_limits<int>::max())?999:board[i][j]);
    }
    printf("\n");
  }*/
  
  return board[ b[0] ][ b[1] ];
}


int main(){
  char as[10], bs[10];
  int a[2], b[2];

  while( scanf(" %9s %9s ", as, bs) == 2 ){
    board = vvi( 8, vi( 8, numeric_limits<int>::max()) );

    a[0] = as[0] - 'a';
    a[1] = as[1] - '1';
    b[0] = bs[0] - 'a';
    b[1] = bs[1] - '1';

    printf("To get from %s to %s takes %d knight moves.\n", as, bs, bfs(a, b));
    
  }
  return 0;
}
