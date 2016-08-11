#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;
  int x[n];
  int dp[n];
  for(int i = 0; i < n; i++){
    cin >> x[i];
  }
  sort(x, x+n);

  int q;
  cin >> q;

  while( q-- ){
    int m;
    cin >> m;

    ull ub = upper_bound(x, x+n, m) - x;
    cout << ub << '\n';
  }
  
  
  return 0;
}

// AC
