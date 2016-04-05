#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll gcd(int a, int b){
  if( a < b ) swap(a, b);
  if( b == 0 ) return a;
  else return gcd(b, a%b);
}

bool lovely(int a){
  int d = 2;
  while( d*d <= a ){
    if( a % d == 0 ){
      //cout << d << "x" << a/d << "=" << a << endl;
      //cout << "gcd(" << d << ", " << a/d << ")=" << gcd(d, a/d) << endl;
      if( gcd(d, a/d) != 1 ) return false;
    }
    d++;
  }
  return true;
}

int main(){
  ll n;
  vll dd = vll();
  
  cin >> n;

  dd.push_back(1);
  dd.push_back(n);

  int d = 2;
  while( d*d <= n ){
    if( n % d == 0 ){
      dd.push_back(d);
      dd.push_back(n/d);
    }
    d++;
  }
  sort(dd.begin(), dd.end());

  /*  for(int i = 0; i < dd.size(); i++ ){
    cout << dd[i] << ' ';
  }
  cout << endl;*/

  int i = dd.size() - 1;
  while( !lovely(dd[i]) )i--;

  cout << dd[i] << endl;
  
  return 0;
}
