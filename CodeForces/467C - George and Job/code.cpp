#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, k;
vi data;
vi fast;
vvi dp;

inline int g(int a, int b){
  int ans = 0;
  for(int i = a; i <= b; i++){
    
    assert(0<=i);
    assert(i<data.size());
    
    ans += data[i];
  }
  cout << "sum " << a << " to " << b << ": " << ans << endl;
  return ans;
  //return fast[b] - fast[a-1];
}

int f(int m, int b){
  assert(0<=m);
  assert(0<=b);
  assert(m<dp.size());
  assert(b<dp[m].size());
  
  if( dp[m][b] != -1 ) return dp[m][b];

  if( m == 1 ){
    int ans = 0;
    for(int y = 0; y <= n-b-k; y++){
      int a = g(b+y, b+y+k-1);
      ans = max(ans, a);
    }
    dp[m][b] = ans;
    return ans;
  }else{
    int ans = 0;
    for(int y = 0; y < (n-b)-(m-1)*k; y++){
      int a = g(b+y, b+y+k-1) + f(m-1, b+y+k+1);
      ans = max(ans, a);
    }
    dp[m][b] = ans;
    return ans;
  }
}

void printdp(){
  for(int i = 0; i < dp.size(); i++){
    for(int j = 0; j < dp[i].size(); j++){
      cout << setw(3) << dp[i][j] << ' ';
    }
    cout << endl;
  }
}

void printdata(){
  for(int i = 0; i < data.size(); i++){
    cout << setw(3) << data[i] << ' ';
  }
  cout << endl;

  for(int i = 0; i < fast.size(); i++){
    cout << setw(3) << fast[i] << ' ';
  }
  cout << endl;
  
}

int main(){
  int m;
  cin >> n >> m >> k;
  dp.resize(m+1);
  fill(begin(dp), end(dp), vi(n+1, -1));
  
  while( n-- ){
    int a; cin >> a;
    data.push_back(a);
  }
  n = data.size();

  fast.push_back(data[0]);
  for(int i = 1; i < n; i++){
    fast.push_back( data[i] + fast[i-1] );
  }

  printdata();

  int ans = f(m, 0);
  cout << ans << endl;

  printdp();
  
  return 0;
}
