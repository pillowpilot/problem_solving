#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi deads;
int d;

void loadDeads(int x, int y, int rats){
  for( int i = x - d; i <= x + d; i++ ){
    for( int j = y - d; j <= y + d; j++ ){
      if( 0 <= i && 0 <= j && i < deads.size() && j < deads[i].size() ){
	deads[i][j] += rats;
      }
    }
  }
}

void solve(){
  int x, y, maxDeads = -1;

  for( int i = 0; i < deads.size(); i++ ){
    for( int j = 0; j < deads[i].size(); j++ ){
      //printf("%3d ", deads[i][j]);
      if( maxDeads < deads[i][j] ){
	maxDeads = deads[i][j];
	x = i;
	y = j;
      }
    }
    //printf("\n");
  }

  printf("%d %d %d\n", x, y, maxDeads);
}

void init(){
  deads.clear();
  deads = vvi( 1025 + 5, vi( 1025 + 5, 0 ) );
}

int main(){
  int cases, ratsPop;
  scanf("%d", &cases);
  while( cases-- > 0 ){
    init();
    scanf("%d %d", &d, &ratsPop);
    while( ratsPop-- > 0 ){
      int x, y, rats;
      scanf("%d %d %d", &x, &y, &rats);
      loadDeads(x, y, rats);
    }
    solve();
  }
  return 0;
}
