#include <cstdio>
#include <vector>

using namespace std;

bool isValid(const vector< vector< int > > &m, int x, int y){
  return ( 0 <= x && 0 <= y && x < m.size() && y < m[x].size() );
}

void visitFrom(vector< vector< int > > &map, int a, int b){
  int x, y, d[] = {-1, -1, +0, +1, +1, +1, +0, -1};
  
  map[a][b] = 1;
  for(int i = 0; i < 8; i++){
    x = a + d[i];
    y = b + d[(i+2) % 8];
    if( isValid(map, x, y) && map[x][y] == -1 ){
      visitFrom(map, x, y);
    }
  }
}

int main(){
  char c;
  int m, n, d;
  vector< vector< int > > map;

  map.reserve(100*100);
  scanf("%d %d", &m, &n);
  while(m != 0){
    d = 0;
    map.clear();
    map.resize(m);
    fill(map.begin(), map.end(), vector< int > (n, 0));

    for(int i = 0; i < map.size(); i++){
      for(int j = 0; j < map[i].size(); j++){
	do{
	  scanf("%c", &c);
	}while(c != '@' && c != '*');
	if(c == '@'){
	  map[i][j] = -1;
	}
      }
    }

    for(int i = 0; i < map.size(); i++){
      for(int j = 0; j < map[i].size(); j++){
	if( map[i][j] == -1 ){
	  d++;
	  visitFrom(map, i, j);
	}
      }
    }
    
    /*for(int i = 0; i < map.size(); i++){
      for(int j = 0; j < map[i].size(); j++){
	printf("%d", map[i][j]);
      }
      printf("\n");
    }*/

    printf("%d\n", d);

    scanf("%d %d", &m, &n);
  }
  return 0;
}
