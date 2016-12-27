#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef map<pii, int> mpiii;

const int INF = (int)1e9+7;
vi needed;
vvi cost;
vvi strengh;
//vvi dp;
mpiii dp;

int f(int lvl, int energy){
  assert(0 <= lvl);
  assert(lvl < needed.size());
  assert(lvl < cost.size());
  assert(lvl < strengh.size());
  assert(0 <= energy);
  
  //int& memo = dp[lvl][energy];
  //if( memo != -1 ) return memo;

  pii p = make_pair(lvl, energy);
  //mpiii::iterator iter = dp.find( p );
  if( dp.find(p) == dp.end() )
    dp[ p ] = -1;
  
  //int memo = dp[ p ];
  //if( memo != -1 ) return memo;
  if( dp[p] != -1 ) return dp[p];

  int include, exclude;
  include = exclude = INF;
  for(int i = 0; i < cost[lvl].size(); i++){
    int c = cost[lvl][i];
    int s = strengh[lvl][i];

    if( needed[lvl] <= s ){
      if( lvl == needed.size() - 1 ){ // last level
	include = min(include, c);
      }else{
	include = min(include, f(lvl+1, s - needed[lvl]) + c);
      }
    }
  }

  if( needed[lvl] <= energy ){
    if( lvl == needed.size() - 1){
      exclude = 0;
    }else{
      exclude = f(lvl+1, energy - needed[lvl]);
    }
  }
    
  dp[ p ] = min(include, exclude);
  return dp[ p ];
}

int main(){
  int n, m;
  while( cin >> n >> m){
    needed.clear();
    for(int i = 0; i < n; i++){
      int c; cin >> c;
      needed.push_back(c);
    }

    cost.resize(n+10); fill(begin(cost), end(cost), vi());
    strengh.resize(n+10); fill(begin(strengh), end(strengh), vi());
    int sum = 0;
    for(int i = 0; i < m; i++){
      int l, s, c; cin >> l >> s >> c;
      l--;
      strengh[l].push_back(s);
      cost[l].push_back(c);
      sum += s;
    }

    //dp.resize(n); fill(begin(dp), end(dp), vi(sum, -1) );
    dp.clear();
    int c = f(0, 0);
    if( c != INF )
      cout << c << endl;
    else
      cout << -1 << endl;
    
  }
  return 0;
}

// RE (maximum recursive calls)
// Bottom up probably will not work too. Use another aproach...
