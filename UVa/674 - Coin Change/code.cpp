#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int coin[] = {1, 5, 10, 25, 50};
int counter = 5;
vvll dp;

ll coinchange(int n, int i){
  ll& memo = dp[n][i];
  if( memo != -1 ) return memo;

  if( n == 0 || i == 0 )
    memo = 1;
  else{
    ll include = 0;
    if( coin[i] <= n ) include = coinchange(n-coin[i], i);
    ll exclude = coinchange(n, i-1);
    memo = include + exclude;
  }

  return memo;
}

int main(){
  dp.resize(10000);
  fill( begin(dp), end(dp), vll(counter, -1) );

  int n;
  while( cin >> n ){
    cout << coinchange(n, counter-1) << '\n';
  }
  flush(cout);
  return 0;
}

// AC
