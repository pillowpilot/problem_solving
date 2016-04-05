#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi boxes;
vi dp;
vi chain;

void print(const vi& v){
  vi::const_iterator iter = v.begin();
  while( iter != v.end() ){
    printf("%d ", *iter);
    iter++;
  }
  printf("\n");
}

bool nest(const vi& a, const vi& b){
  int i = 0;
  while( i < a.size() && a[i] < b[i] ) i++;

  return ( i == a.size() );
}

void lis(){
  for( int i = 0; i < boxes.size(); i++ ){
    for( int j = 0; j < i; j++ ){
      if( dp[j] + 1 > dp[i] && nest(boxes[j], boxes[i]) ){
	dp[i] = dp[j] + 1;
	chain[i] = j;
      }
    }
  }
}

void printSolution(){
  int m = dp[0], top = 0;
  for( int i = 1; i < dp.size(); i++ ){
    if( m < dp[i] ){
      m = dp[i];
      top = i;
    }
  }

  printf("%d\n", m); //Length
  
}

void init(int k, int n){
  boxes = vvi();
  boxes.reserve( k );
  dp = vi(k, 1);
  chain = vi(k, -1);
}

int main(){
  int k, n;

  while( scanf("%d %d ", &k, &n) == 2 ){
    init(k, n);
    while( k-- > 0 ){
      vi box = vi();
      for( int i = 0; i < n; i++ ){
	int c;
	scanf("%d", &c);
	box.push_back(c);
      }
      sort( box.begin(), box.end() );
      boxes.push_back( box );
    }
    lis();
    
  }
  return 0;
}
