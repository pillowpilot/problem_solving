#include <cstdio>
#include <vector>

#define INTACT '.'
#define CRACKED 'X'
#define VISITED 2

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

bool path;
int r2, c2, in; //in == INTACT NEIGHBOR
vvc field;

bool isValid(int x, int y){
  return ( 0 <= x && 0 <= y && x < field.size() && y < field[x].size() );
}

void dfs(int a, int b){
  if( a == r2 && b == c2 ){
    path = true;
  }else{
    int move = 0;
    int offset[] = {0, 1, 0, -1, 0, 1, 0, -1};
    while( move < 4 && !path){
      int c = a + offset[move], d = b + offset[move+3];
      if( isValid(c, d) && field[c][d] == INTACT ){
	field[c][d] += VISITED;
	dfs(c, d);
      }
      move++;
    }
  }
}

void countIN(int a, int b){
  int move = 0;
  int offset[] = {0, 1, 0, -1, 0, 1, 0, -1};
  while( move < 4 ){
    int c = a + offset[move], d = b + offset[move+3];
    if( isValid(c, d) && field[c][d] == INTACT ) in++;
    move++;
  }
}

void init(int n, int m){
  field = vvc(n, vc(m, ' '));
  in = 0;
  path = false;
}

int main(){
  char originalState;
  int n, m, r1, c1;
  
  scanf("%d %d ", &n, &m);
  init(n, m);
  for( int i = 0; i < n; i++ ){
    for( int j = 0; j < m; j++ ){
      char c;
      scanf("%c ", &c);
      field[i][j] = c;
    }
  }
  scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
  r1--; c1--; r2--; c2--;

  originalState = field[r2][c2];
  field[r2][c2] = INTACT;

  countIN(r2, c2);
  dfs(r1, c1);
  
  field[r2][c2] = originalState;

  if( !( r1 == r2 && c1 == c2 ) ){
    if( path ){
      if( originalState == CRACKED ){
	printf("YES");
      }else if( in >= 2 ){
	printf("YES");
      }else{
	printf("NO");
      }
    }else{
      printf("NO");
    }
  }else{
    bool found = false;
    int move = 0;
    int offset[] = {0, 1, 0, -1, 0, 1, 0, -1};
    while( move < 4 ){
      int c = r1 + offset[move], d = c1 + offset[move+3];
	if( isValid(c, d) && field[c][d] == INTACT ){
	  found = true;
	}
	move++;
    }
    printf("%s", (found)?"YES":"NO");
  }
  printf("\n");
  return 0;
}
