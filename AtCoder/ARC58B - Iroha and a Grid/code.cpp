#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull m = (ull) 1e9+7;
ull dp[(ull)2e5];

ull pow(ull b, ull e){
  if(e==0) return 1;
  ull p = 1;
  if( e % 2 == 1 ){
    p = b % m;
    e--;
  }
  ull t = pow(b, e/2);
  p *= (t*t)%m;
  p %= m;
  return p;
}

ull fac(ull n){
  if( dp[n] != 0 ) return dp[n];
  if( n == 0 ) return 1;
  ull f = ((n%m)*fac(n-1)) % m;
  dp[n] = f;
  return f;
}

ull bc(ull n, ull k){
  ull nf = fac(n);
  ull kf = fac(k);
  ull nkf = fac(n-k);

  ull kfi = pow(kf, m-2);
  ull nkfi = pow(nkf, m-2);

  ull coef = (((nf * kfi)%m)*nkfi)%m;
  return coef;
}

int main(){
  dp[(ull)2e5] = {0};
  ull h, w, a, b;

  cin >> h >> w >> a >> b;

  ull limit = min(h-a, w-b);

  ull sum=0;
  for(int i=1; i<=limit; i++){
    ull t1 = bc(h+b-a-1, h-a-i);
    ull t2 = bc(w+a-b-1, w-b-i);
    ull pr = (t1*t2)%m;
    sum += pr;
    sum %= m;
  }


  cout << sum << endl;
  return 0;
}

// AC
