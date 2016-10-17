#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vvi h;
vvb visited;

inline bool isValid(int x, int y){
  return 0 <= x && 0 <= y && x < h.size() && y < h[x].size();
}

void ff(int id, int x, int y){
  const int off[] = {-1, 0, 1, 0, -1, 0, 1};
  visited[x][y] = true;
  for(int i = 0; i < 4; i++){
    int a = x + off[i];
    int b = y + off[i+1];
    if( isValid(a, b) && !visited[a][b] && h[a][b] == id )
      ff(id, a, b);
  }
}

int lateral(){
  int faces = 0;
  for(int i=1; i < h.size(); i++){
    int a, b;
    a = b = 0;
    for(int j=0; j < h[i].size(); j++){
      int x = h[i-1][j];
      int y = h[i][j];

      if( x < y ){ // exists block
	if( !(y <= a || b <= x) ) { // same face
	  a = x; b = y;
	}else{
	  faces++;
	  a = x; b = y;
	}
      }else{
	a = b = 0;
      }
    }
  }
  return faces + 1;
}

void rotate(){
  const int r = h.size();
  const int c = h[0].size();
  
  vvi rm(c);
  fill(begin(rm), end(rm), vi(r));
  for(int i=0; i < r; i++){
    for(int j =0;j < c; j++){
      rm[c-j-1][i] = h[i][j];
    }
  }
  h = rm; // copy assignment
}

int main(){
  int r, c;
  while( cin >> r >> c ){
    h.resize(r); fill(begin(h), end(h), vi(c));
    visited.resize(r); fill(begin(visited), end(visited), vb(c, false));
    
    for(int i=0; i < r; i++){
      for(int j =0;j < c; j++){
	int x;
	cin >> x;
	h[i][j] = x;
      }
    }


    int faces = 1; // down;
    for(int i=0; i < r; i++){
      for(int j =0;j < c; j++){
	if( !visited[i][j] ){
	  faces++;
	  ff(h[i][j], i, j);
	}
      }
    }

    for(int i =0; i < 4;  i++){
      faces += lateral();
      rotate();
    }

    cout << faces << endl;
  }
  return 0;
}
// AC
