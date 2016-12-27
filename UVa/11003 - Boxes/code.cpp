#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi ww;
vi mm;
vvi dp;

int knapsack(int w, int i){
  int& memo = dp[w][i];
  if( memo != -1 ) return memo;

  int include, exclude;
  if( i == ww.size() - 1  ){
    include = (ww[i]<= w)?1:0;
    exclude = 0;
  }else{
    if( ww[i] <= w ){
      int new_max_weight = min(w-ww[i], mm[i]);
      include = knapsack(new_max_weight, i+1) + 1;
    }else
      include = 0;

    exclude = knapsack(w, i+1);
  }

  memo = max(include, exclude);
  return memo;
}


int main(){
  int n;
  cin >> n;
  while( n != 0 ){
    ww.clear();
    mm.clear();
    
    int sum = 0;
    while( n-- ){
      int w, m;
      cin >> w >> m;
      sum += w;
      ww.push_back(w);
      mm.push_back(m);
    }

    dp.resize(sum+2); fill( begin(dp), end(dp), vi(ww.size(), -1));
    cout << knapsack(sum+1, 0) << endl;

    cin >> n;
  }
    
  return 0;
}
