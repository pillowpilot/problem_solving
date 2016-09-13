#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  while( cin >> n ) {
    int a[n][n];
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	cin >> a[i][j];

    int dp[n][n];
    
    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++){
      dp[i][0] = dp[i-1][0] + a[i][0];
      dp[0][i] = dp[0][i-1] + a[0][i];
    }
    
    for(int i = 1; i < n; i++)
      for(int j = 1; j < n; j++)
	dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
    	
    int maxs = -9999999;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
	for(int x = i; x < n; x++)
	  for(int y = j; y < n; y++){
	    int s = dp[x][y];
	    if( i > 0 ) s -= dp[i-1][y];
	    if( j > 0 ) s -= dp[x][j-1];
	    if( i > 0 && j > 0 ) s += dp[i-1][j-1];
	    maxs = max(maxs, s);
	  }

    cout << maxs << endl;
  }      
  return 0;
}

// AC
