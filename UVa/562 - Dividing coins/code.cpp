#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi coins;
vvi dp;

int knapsack(int availableWeight, int consideringItem){
  const int itemWeight = coins[consideringItem];
  const int itemValue = coins[consideringItem];
  
  int& memo = dp[availableWeight][consideringItem];  
  if( memo != -1 )
    return memo;

  int include, exclude, ans;
  if( consideringItem == 0 ){ // last element
    include = (itemWeight <= availableWeight)?itemValue:0;
    exclude = 0; // No more value can be added
  }else{
    include = (itemWeight <= availableWeight)?knapsack(availableWeight - itemWeight, consideringItem-1) + itemValue:0;
    exclude = knapsack(availableWeight, consideringItem-1);
  }
  ans = max(include, exclude);
  memo = ans;
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  coins.reserve(100);
  
  int n;
  cin >> n;
  while( n-- ){
    int m;
    cin >> m;

    coins.clear();
    while( m-- ){
      int a;
      cin >> a;
      coins.push_back(a);
    }

    int sum = 0;
    for(const auto& c: coins){
      sum += c;
    }

    dp.resize(sum+1); fill(begin(dp), end(dp), vi(coins.size(), -1));
    int maxv = knapsack(sum/2, coins.size()-1);

    int unfairness = sum - maxv*2;
    cout << unfairness << endl;
  }
  
  return 0;
}

// AC
