#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){
  ll n, k;
  cin >> n >> k;

  ll sqrtn = sqrt(n);
  vll dd;
  rep(i, 1, sqrtn+1){
    if( n%i==0 )
      dd.push_back(i);
  }

  int i = dd.size()-1;
  if( sqrtn*sqrtn == n )
    i--;
  while( i>=0 ){
    dd.push_back(n/dd[i]);
    i--;
  }

  rep(i, 0, dd.size()){
    //cout << dd[i] << " ";
  }
  //cout << endl;

  if( dd.size() < k )
    cout << -1 << endl;
  else
    cout << dd[k-1] << endl;
  
  return 0;
}

// AC
/*
  Notice that O(sqrt(n)) is acceptable!
  Trivially list all divisors in O(sqrt(n)) and print the k-th, if possible.
 */
