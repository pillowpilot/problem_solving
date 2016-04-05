#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int len(long long n){ // Int is not enough!.
  if( n < dp.size() && dp[n] != 0 )
    return dp[n];

  int l = len( (n%2==0)?n/2:3*n+1 ) + 1;
  if( n < dp.size() ) dp[n] = l;
  return l;
}

int main(){
  const int limit = 1e6;
  int maxLength = 1;
  int maxN = 1;
  
  dp = vector<int>(limit+14, 0);
  dp[1] = 1;
  
  for(int i = 1; i <= limit; i++){
    int l = len(i);
    if( maxLength < l ){
      maxLength = l;
      maxN = i;
    }
  }
  cout << maxN << "(" << maxLength << ")" << endl;
}

// AC
