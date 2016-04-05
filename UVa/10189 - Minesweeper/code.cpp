#include <cstdio>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

vvc board;

bool isValid(int x, int y){
  return (0 <= x && 0 <= y && x < board.size() && y < board[x].size() );
}

void solve(){
  int offset[] = {-1, -1, 0, +1, +1, +1, 0, -1};
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board[i].size(); j++){
      if( board[i][j] != '*' ){
	int c = 0;
	for(int k = 0; k < 8; k++){
	  int x = i + offset[k], y = j + offset[(k + 6) % 8];
	  if( isValid(x, y) && board[x][y] == '*' ) c++;
	}
	board[i][j] = '0' + c;
      }
    }
  }
}

void print(int field){
  printf("Field #%d:\n", field);
  for(int i = 0; i < board.size(); i++){
    for(int j = 0; j < board[i].size(); j++){
      printf("%c", board[i][j]);
    }
    if( i != board.size() - 1) printf("\n");
  }
}

void init(int n, int m){
  board = vvc(n, vc(m));
}

int main(){
  bool flag = false;
  int n, m, id = 1;
  
  while( scanf("%d %d ", &n, &m) == 2 && n != 0 && m != 0 ){
    if( flag ) printf("\n");
    flag = true;
    init(n, m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	char c;
	scanf("%c ", &c);
	board[i][j] = c;
      }
    }
    solve();
    print(id++);
    printf("\n");
  }
}
