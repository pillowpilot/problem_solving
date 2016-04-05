#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

string s;
vi dp;

void preprocess();

int main(){
  int m;
  cin >> s >> m;
  preprocess();
  while( m-- > 0 ){
    int l, r;
    cin >> l >> r;
    cout << dp[r-1] - dp[l-1] << '\n';
  }
  cout << flush;
  return 0;
}

void preprocess(){
  int i = 0;

  dp = vi();
  dp.reserve(10101);
  dp.push_back(0);
  while( s[i+1] != '\0' ){
    if( s[i] == s[i+1] ) dp.push_back( dp.back() + 1 );
    else dp.push_back( dp.back() );
    i++;
  }
  dp.push_back( dp.back() );
}

// AC
