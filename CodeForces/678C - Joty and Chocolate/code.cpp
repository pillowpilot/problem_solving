#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull a, ull b){
  if( a < b ){
    swap(a, b);
  }
  if(b==0) return a;
  return gcd(b, a%b);
}

ull lcm(ull a, ull b){
  return a/gcd(a, b)*b;
}

int main(){
  ull n, a, b, p, q;

  cin >> n >> a >> b >> p >> q;
  
  ull C = n/lcm(a,b);
  ull A = n/a - C;
  ull B = n/b - C;

  ull ans = A*p + B*q + C*max(p, q);

  cout << ans << endl;
  return 0;
}

// AC
