#include <iostream>
#include <vector>

using namespace std;

int d(int n){
  int i = 2, sum = 1;
  while( i*i <= n ){
    if( n % i == 0 )
      sum += i + n / i;
    i++;
  }
  return sum;
}

int main(){
  const int limit = 1e4;
  vector<int> dp(limit, 0);

  for(int i = 0; i <= limit; i++)
    dp[i] = d(i);

  int sum = 0;
  for(int i = 1; i < limit; i++){
    if( dp[ dp[i] ] == i && dp[i] != i )
      sum += i + dp[i];
  }

  cout << sum / 2 << endl; // Double sum!
  return 0;
}

// AC
