#include <iostream>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef long long ll;

//vb t;

int main(){
  std::ios_base::sync_with_stdio(false);
  ll n;

  cin >> n;

  //t = vb( 1e6 );
  while( n > 0 ){
    //t.clear();

    ll x = 2, d = 2;
    while( x*x < n && n % (x*x) != 0 ){
      x++;
      if( n % d != 0 ) d++;
    }

    if( n % (x*x) == 0 ){
      //      cout << n << " Not lovely " << x*x << endl;
      while( n % d != 0 ) d++;
      n /= d;
    }else break;
  }

  cout << n << endl;
  
  return 0;
}
