#include <cstdio>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector< vc > vvc;

int main(){
  vvc b = vvc( 8, vc(8));
  for( int i = 0; i < 8; i++ ){
    for( int j = 0; j < 8; j++ ){
      char c;
      scanf("%c ", &c);
      b[i][j] = c;
    }
  }
  int minA, minB;
  minA = minB = 9999;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if( b[i][j] == 'W' ){
	int k = i-1;
	while( k >= 0 && b[k][j] == '.') k--;
	if( k < 0 ){
	  minA = min( minA, i );
	  //printf("%d %d: %d\n", i, j, i);
	}
      }else if( b[i][j] == 'B' ){
	int k = i+1;
	while( k < 8  && b[k][j] == '.') k++;
	if( k == 8 ){
	  minB = min( minB, 8 - (i+1) );
	  //printf("%d %d: %d\n", i, j, 8-(i+1));
	}
      }
    }
  }
  if( minA == minB || minA < minB ) printf("A\n");
  else printf("B\n");
  
  return 0;
}

// AC
