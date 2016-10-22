#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

const ll limit = 2147483648;
vll v;

void prep(){
  ll x = 1;
  for(int a = 0; a <= 31; a++){
    ll y = 1;
    while( x*y <= limit ){

      v.push_back( x*y );
      
      y *= 3;
    }
    
    x *= 2;
  }

  sort( begin(v), end(v) );
}
  

int main(){
  prep();
  ll n;
  cin >> n;
  while( n != 0 ){

    auto iter = lower_bound( begin(v), end(v), n );
    cout << *iter << endl;
    
    cin >> n;
  }
  return 0;
}

// AC
