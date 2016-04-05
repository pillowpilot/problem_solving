#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned ll ull;
typedef vector<ll> vll;

vll a, b;

int main(){
  int n, m;

  cin >> n;
  a = vll(n);
  for(int i = 0; i < n; i++){
    ll x;
    cin >> x;
    a[i] = x;
  }

  cin >> m;
  b = vll(m);
  for(int i = 0; i < m; i++){
    ll x;
    cin >> x;
    b[i] = x;
  }

  int x1, y1, x2, y2, x3, y3;

  ll m1, m2, m3;
  m1 = m2 = m3 = -1e9;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      ll swapValue = (a[i]>b[j])?a[i]-b[j]:b[j]-a[i];
      if( m1 <= swapValue ){
	m1 = swapValue;
	x1 = i;
	y1 = j;
      }else{
	if( m2 <= swapValue ){
	  m2 = swapValue;
	  x2 = i;
	  y2 = j;
	}else{
	  if( m3 <= swapValue ){
	    m3 = swapValue;
	    x3 = i;
	    y3 = j;
	  }
	}
      }
    }
  }
  
  
  return 0;
}
