#include <cstdio>
#include <vector>

#define CLEAR 0
#define BLOCK 1

using namespace std;

typedef struct{
  int x, y;
} Rook;
typedef vector<Rook> vr;
typedef vector<int> vi;
typedef vector<vi> vvi;

vr rooks;
vvi board;
unsigned long int maxRooks;

bool blocked(int x, int y){
  return (board[x][y] == BLOCK);
}

bool atacked(int x, int y){
  bool atacked = false;
  vr::const_iterator rook = rooks.begin();
  while( rook != rooks.end() && !atacked){
    if( rook->x == x ){
      atacked = true;
      for( int i = min( rook->y, y ); i <= max( rook->y, y ); i++ ){
	if( blocked(x, i) ) atacked = false;
      }
    }else if( rook->y == y ){
      atacked = true;
      for( int i = min( rook->x, x ); i <= max( rook->x, x ); i++ ){
	if( blocked(i, y) ) atacked = false;
      }
    }
    rook++;
  }
  return atacked;
}

void bt(int k){
  int n = board.size();
  if( k == n*n ){
    if( rooks.size() > maxRooks ) maxRooks = rooks.size();
  }else{
    for( int i = k; i < n * n; i++ ){
      if( !blocked(int( i / n ), i % n ) && !atacked( int( i / n ), i % n ) ){
	Rook rook = {int( i / n), i % n};
	rooks.push_back( rook );
	if( rooks.size() > maxRooks ) maxRooks = rooks.size();
	bt( i + 1 );
	rooks.pop_back();
      }
    }
  }
}

void init(int d){
  maxRooks = 0;
  rooks.clear();
  board = vvi( d, vi( d, CLEAR ) );
}

int main(){
  int d;
  
  while( scanf("%d ", &d) == 1 && d != 0 ){
    init(d);
    for( int i = 0; i < d; i++ ){
      for( int j = 0; j < d; j++ ){
	char c;
	scanf("%c", &c);
	if( c == 'X' ) board[i][j] = BLOCK;
      }
      scanf("%*c");
    }
    
    bt(0);

    printf("%ld\n", maxRooks);
  }
}
