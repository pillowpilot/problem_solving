#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vvvi dp;
vb isPrime;
vi prime;

void eratosthenes(){
  isPrime.resize(1213);
  fill(begin(isPrime), end(isPrime), true);
  isPrime[0] = isPrime[1] = false;

  for(int i = 2; i < isPrime.size(); i++){
    if( isPrime[i] ){
      prime.push_back(i);
      int j = i*i;
      while( j < isPrime.size() ){
	isPrime[j] = false;
	j += i;
      }
    }
  }
}

int f(int n, int k, int i){
  int& memo = dp[n][k][i];
  if( memo != -1 )
    return memo;

  if( k == 0 && n == 0 ){
    memo = 1;
  }else if( k == 0 ){
    memo = 0;
  }else{
    int include, exclude;
    include = exclude = 0;
    if( i < prime.size() && prime[i] <= n )
      include = f(n-prime[i], k-1, i+1);
    if( i < prime.size() )
      exclude = f(n, k, i+1);

    memo = include + exclude;
  }
  
  return memo;
}

int main(){
  eratosthenes();

  int n, k;
  while( cin >> n >> k && n != 0 ){
    int pc = prime.size();
    dp.resize(n+1);
    fill( begin(dp), end(dp), vvi(k+1, vi(pc+1, -1)) );

    int ans = f(n, k, 0);

    cout << ans << endl;
  }
  return 0;
}

// AC
