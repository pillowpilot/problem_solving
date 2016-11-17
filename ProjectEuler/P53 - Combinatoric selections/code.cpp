#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define INTMAX (1<<31)

using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;
typedef vector<vull> vvull;

vvull dp;
ull cb(int n, int r){
  assert(r<=n);
  assert(0<=r);
  assert(0<=n);
  assert(n < dp.size());
  assert(r < dp[n].size());
  
  if( r == 0 ) return 1;
  if( n == r ) return 1;
  if( dp[n][r] != 0 ) return dp[n][r];

  ull a = cb(n-1, r);
  ull b = cb(n-1, r-1);
  ull ans = a + b;
  dp[n][r] = ans;
  return ans;
}

int main(){
  dp.resize(101);
  fill(begin(dp), end(dp), vull(101, 0));

  cb(100, 100);
  int ans = 0;
  for(int n = 0; n <= 100; n++){
    for(int r = 0; r <= n; r++){
      ull x = cb(n,r);
      if( x > 1000000 ) ans++;
    }
  }

  cout << ans << endl;
  return 0;
}

// AC ans = 4075

/*
  beware overflow!
  100C51=98913082887808032681188722800
 */
