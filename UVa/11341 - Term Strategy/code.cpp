#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll MINF = (ll) -1e6;

vvll l;
vvll dp;
vll mh;

ll f(int h, int i){
  ll& memo = dp[h][i];
  if(memo != -1) return memo;

  if( h < mh[i] )
    memo = MINF;
  else{
    int j = mh[i];
    memo = MINF;
    while( j <= h ){
      ll option;
      
      if( i == l.size() - 1 )
	option = l[i][j-1];
      else
	option = l[i][j-1] + f(h-j, i+1);
      
      if( memo < option ){
	memo = option;
      }
      j++;
    }
  }
  //printf("f(%d, %d) = %d\n", h, i, memo);
  
  return memo;
}

int main(){
  int t;  cin >> t;
  while( t-- ){
    ll n, m; cin >> n >> m;

    l.resize(n); fill(begin(l), end(l), vll(m, -1));
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
	ll c; cin >> c;
	l[i][j] = c;
      }
    }

    dp.resize(m+1); fill(begin(dp), end(dp), vll(n, -1));
    mh.resize(n);
    for(int i = 0; i < n; i++){
      int j = 0;
      while( j < l[i].size() && l[i][j] < 5 )
	j++;
      if( j == l[i].size() ){
	mh[i] = 2*m; // impossible to approve
      }else{
	mh[i] = j + 1;
      }
    }

    double avg = (double)f(m, 0) / n;
    if( avg < 0 )
      cout << "Peter, you shouldn't have played billiard that much.\n";
    //printf("Peter, you shouldn't have played billiard that much.\n");
    else{
      avg = round(avg);
      cout << "Maximal possible average mark - " << fixed << setprecision(2) << avg << ".\n";
    }
    //printf("Maximal possible average mark - %.2lf.\n", avg);
  }
  flush(cout);
  return 0;
}

