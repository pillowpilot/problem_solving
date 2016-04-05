#include <cstdio>
#include <vector>
#include <limits>

#define MINF std::numeric_limits<int>::min()

using namespace std;

typedef vector<int> vi;

int a, b, c;
vi dp;

void solve(){
  vi v = {a, b, c};

  for( int i = 1; i < dp.size(); i++ ){
    for( int j = 0; j < v.size(); j++ ){
      int k = v[j];
      if( i == k ) dp[i] = max(dp[i], 1);
      if( i >  k ) dp[i] = max(dp[i], dp[i - k] + 1);
    }
    //printf("(%d) %d ", i, dp[i]);
  }
  //printf("\n");
}

int main(){
  int n;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  dp = vi(n+1, MINF);

  solve();
  printf("%d", dp.back());
}
