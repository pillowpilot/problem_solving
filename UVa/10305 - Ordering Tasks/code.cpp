#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj;

void init(int n){
  adj = vvi( n, vi( n, 0 ) );
}

int main(){
  int n, m;
  while( scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0 ){
    init(n);
    while( m-- > 0 ){
      int i, j;
      scanf("%d %d", &i, &j);
      adj[i][j] = 1;
    }
    
  }
  return 0;
}
