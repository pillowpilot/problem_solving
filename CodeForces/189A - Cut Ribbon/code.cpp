#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi dp;

int main(){
  int n, a, b, c;
  scanf("%d %d %d %d", &n, &a, &b, &c);
  dp = vi(n, 0);

  for( int i = 1; i < n; i++ ){
    if( i - a >= 0 ) dp[i] = max(dp[i], dp[i-a] + 1);
    if( i - b >= 0 ) dp[i] = max(dp[i], dp[i-b] + 1);
    if( i - c >= 0 ) dp[i] = max(dp[i], dp[i-c] + 1);
    printf("%d ", dp[i]);
  }
  
  printf("\n%d", dp[n-1]);
  return 0;
}
