#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll coins;
vvll dp;

ll coinchange(int n, int i){
  ll& memo = dp[n][i];
  if( memo != -1 ) return memo;

  if( i == 0 ) memo = 1;
  else{
    ll include, exclude;
    ll value = coins[i];
    if( value <= n )
      include = coinchange(n-value, i);
    else
      include = 0;

    exclude = coinchange(n, i-1);

    memo = include + exclude;
  }
  
  return memo;
}

int main(){
  for(int i = 1; i <= 21; i++)
    coins.push_back(i*i*i);

  dp.resize(11137); fill(begin(dp), end(dp), vll(coins.size(), -1));
  
  int n;
  while( cin >> n ){
    cout << coinchange(n, coins.size()-1) << endl;
  }
  return 0;
}

// AC
