#include <iostream>
#include <vector>

using namespace std;

vector< vector<long long> > dp; // Beware the overflow!!

long long f(int x, int y){
  if( dp[x][y] != 0 )
    return dp[x][y];
  
  if( x == 0 || y == 0 )
    return 1;
  else{
    dp[x][y] = f(x-1, y) + f(x, y-1);
    return dp[x][y];
  }
}

long long g(int n){
  return f(n, n);
}

int main(){
  const int maxSize = 20 + 3;
  dp = vector< vector<long long> >( maxSize, vector<long long>(maxSize, 0) );

  cout << g(20) << endl;
  
  return 0;
}

// AC
