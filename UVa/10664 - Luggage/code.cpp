#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi items;
vvi dp;

int knapsack(int w, int i){
  int& memo = dp[w][i];
  if( memo != -1 ) return memo;

  int include, exclude;
  if( i == 0 ){
    include = (items[i]<=w)?items[i]:0;
    exclude = 0;
  }else{
    include = (items[i]<=w)?items[i]+knapsack(w-items[i], i-1):0;
    exclude = knapsack(w, i-1);
  }

  memo = max(include, exclude);
  return memo;
}

int main(){
  int n;
  string line;
  getline(cin, line);
  stringstream scin(line);
  scin >> n;
  while( n-- ){
    getline(cin, line);
    stringstream scin(line); // clean and load

    items.clear();
    int item; int sum = 0;
    while( scin >> item ){
      sum += item;
      items.push_back(item);
    }

    dp.resize(sum/2+1); fill( begin(dp), end(dp), vi(items.size(), -1));
    int a = knapsack(sum/2, items.size()-1);
    int b = sum - a;
    int dif = abs(a-b);

    if( dif == 0 )
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  flush(cout);
  return 0;
}

// AC
