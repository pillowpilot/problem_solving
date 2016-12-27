#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi coins{1, 2, 5, 10, 20, 50, 100, 200};
vvi dp;

int coinchange(int n, int i){
  if( dp[n][i] != -1 ) return dp[n][i];

  if( i == 0 ) return 1;
  else{
    int include=0, exclude;
    if( coins[i] <= n ){
      include = coinchange(n-coins[i], i);
    }
    exclude = coinchange(n, i-1);
    dp[n][i] = include + exclude;
    return dp[n][i];
  }
}

int main(){

  dp.resize(201);
  fill( begin(dp), end(dp), vi(8, -1));
  cout << coinchange(200, 7) << endl;
  return 0;
}

// AC ans = 73682

/*
  classical dp problem
  decision: given a coin, do I include it or not..??
 */
