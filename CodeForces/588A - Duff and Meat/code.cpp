#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi aa;
vi pp;
vi dp;

int main(){
  int n;

  aa = vi();
  pp = vi();

  cin >> n;
  while( n-- > 0 ){
    int a, p;
    cin >> a >> p;
    aa.push_back(a);
    pp.push_back(p);
  }

  dp = vi(aa.size());
  dp[0] = aa[0] * pp[0];

  int m = pp[0];
  for( int i = 1; i < dp.size(); i++ ){
    m = min( m, pp[i] );
    dp[i] = dp[i-1] + aa[i] * m;
  }

  /*  for( int i = 0; i < dp.size(); i++ ) cout << dp[i] << endl;
  cout << endl;
  */

  cout << dp[dp.size()-1] << endl;
  
  return 0;
}

// AC
