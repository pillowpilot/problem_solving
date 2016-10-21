#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

vi value;
vi depth;
vvb solution;
vb finalSolution;
vvi dp;
int w;

int knapsack(int air, int i){
  int& memo = dp[air][i];
  const int airNeeded = 3*w*depth[i];
  if( memo != -1 )
    return memo;

  int include, exclude;
  if( i == 0 ){
    include = (airNeeded <= air)?value[i]:-1;
    exclude = 0;
  }else{
    include = (airNeeded <= air)?value[i]+knapsack(air-airNeeded, i-1):-1;
    exclude = knapsack(air, i-1);
  }

  if( include > exclude ){
      solution[air][i] = true;
  }

  memo = max(include, exclude);
  return memo;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  bool first = true;
  int t;
  while( cin >> t >> w ){
    
    if( !first ){
      cout << '\n';
    }
    first = false;
    
    int ta;
    cin >> ta;

    value.clear(); depth.clear();
    for(int i = 0; i < ta; i++){
      int d, v;
      cin >> d >> v;
      depth.push_back(d);
      value.push_back(v);
    }

    solution.resize(t+1); fill( begin(solution), end(solution), vb(ta, false) );
    finalSolution.resize(ta); fill( begin(finalSolution), end(finalSolution), false );
    dp.resize(t+1); fill( begin(dp), end(dp), vi(ta, -1));

    int maxv = knapsack(t, ta - 1);
    cout << maxv << '\n';

    int solutionCounter = 0;
    for(int i = ta-1; i >= 0; i--){
      if( solution[t][i] ){
	solutionCounter++;
	t -= 3*w*depth[i];
	finalSolution[i] = true;
      }
    }

    cout << solutionCounter << '\n';
    
    for(int i = 0; i < finalSolution.size(); i++){
      if( finalSolution[i] )
	cout << depth[i] << ' ' << value[i] << '\n';
    }
  }

  flush(cout);
  return 0;
}

// AC
