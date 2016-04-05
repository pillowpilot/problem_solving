#include <cstdio>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi memo;
vi s;

void printMemo(){
  for( int i = 0; i < memo.size(); i++ ){
    for( int j = 0; j < memo[i].size(); j++ ){
      printf("%4d", memo[i][j]);
    }
    printf("\n");
  }
}

int f(int a, int b){
  if( b - a == 1 ){
    if( memo[a][b] == -1 ) memo[a][b] = 0;
    return memo[a][b];
  }else{
    int cost, lower, higher, minimum, sum;
    
    cost = s[b] - s[a];
    minimum = numeric_limits<int>::max();
    for( int i = 1; i < b - a; i++ ){
      if( memo[a][a + i] == -1 ){
	memo[a][a + i] = f(a, a + i);
      }
      lower = memo[a][a + i];

      if( memo[a + i][b] == -1 ){
	memo[a + i][b] = f(a + i, b);
      }
      higher = memo[a + i][b];

      sum = lower + higher + cost;
      if( sum < minimum ){
	minimum = sum;
      }
    }
    memo[a][b] = minimum;
    return memo[a][b];
  }
}

void init(int s_size){
  s.clear();
  s.push_back( 0 );
  memo.clear();
  memo = vvi( s_size + 5, vi( s_size + 5, -1 ) );
}

int main(){
  int l, c;

  s.reserve( 50 + 5 );
  scanf("%d", &l);
  while( l != 0 ){
    scanf("%d", &c);
    init(c);
    while( c-- > 0 ){
      int a;
      scanf("%d", &a);
      s.push_back( a );
    }
    s.push_back(l);

    printf("The minimum cutting is %d.\n", f(0, s.size() - 1));

    scanf("%d", &l);
  }
}
