#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi board;

void init(){
  board = vvi(100, vi(100, 0));
}

void insertRectangle(int a, int b, int x, int y){
  a--; b--; x--; y--;

  // ERROR: Los recorridos deben de ser inclusivos. i <= x && j <= y
  for(int i = a; i < x; i++){
    for(int j = b; j < y; j++){
      board[i][j]++;
    }
  }
}

int count(){
  int c = 0;
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      c += board[i][j];
    }
  }
  return c;
}

int main(){
  int n, a, b, x, y, r;
  
  init();
  scanf("%d", &n);
  while( n-- > 0 ){
    scanf("%d %d %d %d", &a, &b, &x, &y);
    insertRectangle(a, b, x, y);
  }
  r = count();
  printf("%d", r);
  return 0;
}
