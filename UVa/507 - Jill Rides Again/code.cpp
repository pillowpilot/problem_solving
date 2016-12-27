#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll v;
vll dp;
vll lower_bounds;
ll upper_bound;

ll maxRangeSum(){
  dp[0] = v[0];
  lower_bounds[0] = 0;
  for(int i = 1; i < dp.size(); i++){
    ll extend = dp[i-1] + v[i];
    ll newone = v[i];
    if( extend < newone ){
      dp[i] = newone;
      lower_bounds[i] = i;
    }else
  }

  ll ans = dp[0];
  for(int i = 1; i < dp.size(); i++){
    ans = max( ans, dp[i] );
  }

  return ans;
}

int main(){
  int tests; cin >> tests;
  for(int test = 1; test <= tests; test++){
    int stops; cin >> stops;
    
    stops--;
    v.clear();
    while( stops-- ){
      int x; cin >> x;
      v.push_back(x);
    }
    dp.resize( v.size() );
    ll ans = maxRangeSum();

    if( ans < 0 )
      cout << "Route " << test << " has no nice parts" << endl;
    else
      cout << "The nicest part of route " << test << " is between stops " << lower_bound << " and " << upper_bound << "" << endl;
  }
  return 0;
}
