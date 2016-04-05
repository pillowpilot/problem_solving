#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

const char FREE = '_';
const char ATKD = '-';

vvc board;
char input[555];

void printBoard(){
  printf("~~~~~~~~~~~~~~~\n");
  for( int i = 0; i < board.size(); i++ ){
    for( int j = 0; j < board[i].size(); j++ ){
      printf("%c ", board[i][j]);
    }
    printf("\n");
  }
  printf("~~~~~~~~~~~~~~~\n");
}

bool isValid(int i, int j){
  return 0 <= i && 0 <= j && i < board.size() && j < board[i].size();
}

void advancer(int row, int col, int direction){
  int data[] = {-1, 0, +1, +1, +1, 0, -1, -1, -1, 0};
  int a = data[direction], b = data[direction+2];

  int offset = 1;
  int i = row + a*offset;
  int j = col + b*offset;
  while( isValid(i, j) && ( board[i][j] == FREE || board[i][j] == ATKD) ){
    board[i][j] = ATKD;
    offset++;
    i = row + a*offset;
    j = col + b*offset;
  }
}

void pawn(int row, int col){
  if( board[row][col] == 'p' ){
    if( isValid(row + 1, col - 1) && board[row + 1][col - 1] == FREE) board[row + 1][col - 1] = ATKD;
    if( isValid(row + 1, col + 1) && board[row + 1][col + 1] == FREE) board[row + 1][col + 1] = ATKD;
  }else{
    if( isValid(row - 1, col - 1) && board[row - 1][col - 1] == FREE) board[row - 1][col - 1] = ATKD;
    if( isValid(row - 1, col + 1) && board[row - 1][col + 1] == FREE) board[row - 1][col + 1] = ATKD;
  }
}

void knight(int row, int col){
  int offset[] = {-2, -2, -1, +1, +2, +2, +1, -1, -2, -2};
  for( int i = 0; i < 8; i++ ){
    if( isValid(row + offset[i], col + offset[i + 2]) &&
	board[row + offset[i]][col + offset[i + 2]] == FREE) board[row + offset[i]][col + offset[i + 2]] = ATKD;
  }
}

void bishop(int row, int col){
  advancer(row, col, 0);
  advancer(row, col, 2);
  advancer(row, col, 4);
  advancer(row, col, 6);
}

void rook(int row, int col){
  advancer(row, col, 1);
  advancer(row, col, 3);
  advancer(row, col, 5);
  advancer(row, col, 7);
}

void queen(int row, int col){
  bishop(row, col);
  rook(row, col);
}

void king(int row, int col){
  int offset[] = {-1, -1, -1, +0, +1, +1, +1, +0, -1, -1};
  for(int i = 0; i < 8; i++){
    if( isValid(row + offset[i], col + offset[i + 2] ) &&
	board[row + offset[i]][col + offset[i+2]] == FREE ) board[row + offset[i]][col + offset[i+2]] = ATKD;
  }
}

void process(){
  int i = 0, row = 0, col = 0;
  while( input[i] != '\0' ){
    char c = input[i];
    if( c == '/' ){
      row++;
      col = 0;
    }else if( '0' <= c && c <= '9' ){
      col += c - '0';
    }else{
      board[row][col] = c;
      col++;
    }
    i++;
  }
}

int solve(){
  for( int row = 0; row < board.size(); row++ ){
    for( int col = 0; col < board[row].size(); col++ ){
      switch( board[row][col] ){
      case 'P':
      case 'p':
	pawn(row, col);
	break;
      case 'n':
      case 'N':
	knight(row, col);
	break;
      case 'b':
      case 'B':
	bishop(row, col);
	break;
      case 'r':
      case 'R':
	rook(row, col);
	break;
      case 'q':
      case 'Q':
	queen(row, col);
	break;
      case 'k':
      case 'K':
	king(row, col);
	break;
      }
    }
  }

  int counter = 0;
  for( int row = 0; row < board.size(); row++ ){
    for( int col = 0; col < board[row].size(); col++ ){
      if( board[row][col] == FREE ) counter++;
    }
  }
  return counter;
}

int main(){
  while( scanf("%[^\n]\n", input) == 1 ){
    board = vvc(8, vc(8, FREE));

    process();

    //printf("%s\n", input);
    //printBoard();

    int r = solve();
    //printBoard();
    printf("%d\n", r);
    
  }
  return 0;
}


// Fácil, pero mu~y tedio~so...
// AC
