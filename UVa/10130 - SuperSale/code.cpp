#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi w;
vi p;
vvi dp;

int knapsack(int weight, int item){
  int& memo = dp[weight][item];
  if( memo != -1 ) return memo;

  int include, exclude;
  if( item == w.size() - 1){
    include = (w[item]<=weight)?p[item]:0;
    exclude = 0;
  }else{
    include = (w[item]<=weight)?p[item]+knapsack(weight-w[item], item+1):0;
    exclude = knapsack(weight, item+1);
  }

  return memo = max(include, exclude);
}

int main(){
  int tests;
  cin >> tests;
  while( tests-- ){
    int n;
    cin >> n;

    w.clear();
    p.clear();
    while( n-- ){
      int a, b;
      cin >> a >> b;
      p.push_back(a);
      w.push_back(b);
    }
    n = p.size();

    int g;
    cin >> g;

    int ans = 0;
    while( g-- ){
      int maxw;
      cin >> maxw;

      dp.resize(maxw+1); fill( begin(dp), end(dp), vi(n+1, -1));
      ans += knapsack(maxw, 0);
    }

    cout << ans << endl;
  }
  return 0;
}

// AC
