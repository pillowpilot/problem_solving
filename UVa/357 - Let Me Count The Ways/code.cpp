#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const int coins[] = {1, 5, 10, 25, 50};
const int counter  = 5;
vvll dp;

ll f(int n, int m){
  ll& memo = dp[n][m];
  if( memo != -1 )
    return memo;

  if( m == 0 )
    memo = 1;
  else if( n == 0 )
    memo = 1;
  else{
    memo = 0;
    memo += (coins[m] <= n)?f(n-coins[m], m):0;
    memo += f(n, m-1);
  }
  //printf("%ld %ld > %ld\n", n, m, memo);
  
  return memo;
}

int main(){
  int n;
  dp.resize(30001); fill(begin(dp), end(dp), vll(counter+1, -1));
  while( cin >> n ){
    if( n == 0 ){
      cout << "There is only 1 way to produce 0 cents change.\n";
    }else{
      ll ans = f(n, counter-1);
      if( ans == 1 )
	cout << "There is only 1 way to produce " << n << " cents change.\n";
      else
	cout << "There are " <<  ans << " ways to produce " << n << " cents change.\n";
    }
  }

  flush(cout);
  return 0;
}

// AC
