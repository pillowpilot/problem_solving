#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int maxm = 150;
vvi memo(maxm, vi(8, -1));

int f(int n, int m){
  if( memo[n][m] != -1 ) return memo[n][m]; // base cases
  int ans;
  if( m == 0 ) ans = f(n-1, 4)+f(n-2, 0)+f(n-2, 6);
  if( m == 1 ) ans = f(n-1, 6);
  if( m == 2 ) ans = f(n-1, 5);
  if( m == 3 ) ans = f(n, 0)+f(n-1, 4);
  if( m == 4 ) ans = f(n-1, 3);
  if( m == 5 ) ans = f(n-1, 2);
  if( m == 6 ) ans = f(n, 0)+f(n-1, 1);
  memo[n][m] = ans;
  return ans;
}

void prep(){
  rep(i, 0, 8){
    memo[0][i] = memo[1][i] = 0;
  }
  memo[0][0] = memo[0][3] = memo[0][6] = 1;
  memo[1][1] = memo[1][4] = 1;
  memo[1][7] = 3;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  prep();
  int n;
  while( cin >> n  && n != -1 ){
    cout << f(n, 0) << endl;
  }
    
  return 0;
}

// AC
/*
  DP w/ bit mask
  Generalize the problem to tiling with dominos a 3xN rectangle with "teeth" coming out to the left.
  There are 7 diferent cofigurations.
  
  f(n, 2) and f(n, 5) are not used.
 */
