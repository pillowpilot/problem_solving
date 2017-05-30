#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define debug(a) cout << #a << " = " << a << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef long long ll;

struct fraction{
  ll n, d;
  fraction()
  {n = 0; d = 1;}
  fraction(ll n, ll d)
  {
    ll g = __gcd(n, d);
    n /= g;
    d /= g;

    ll s;
    if( n < 0 || d < 0 )
      s = -1;
    else
      s = 1;

    d = llabs(d);
    n = llabs(n);
    n *= s;

    this->n = n;
    this->d = d;
    assert(d!=0);
  }
  fraction operator+(fraction f){
    /*ll num = f.d*n+d*f.n;
    ll dem = f.d*d;
    fraction r(num, dem);
    */
    
    return fraction(f.d*n+d*f.n, f.d*d);
  }
  fraction operator-(fraction f){
    return fraction(f.d*n-d*f.n, f.d*d);
  }
  fraction operator*(fraction f){
    
    /*ll num = f.n*n;
    ll dem = f.d*d;
    fraction r(num, dem);*/
    return fraction(f.n*n, f.d*d);
  }
};

//typedef vector<fraction> vf;
//typedef vector<vf> vvf;

//vvf dp;

fraction dp[444][444];

void prec(int n){
  //dp = vvf(n+1, vf(n+1));

  dp[0][0] = fraction(1, 1);
  //rep(i, 0, n){
  for(int i = 0; i <= n; i++){
    fraction acc;
    //rep(j, 1, i){
    for(int j = 1; j <= i; j++){
      //assert(0<=i-1&&i-1<444);
      //assert(0<=j-1&&j-1<444);
      /*fraction up = dp[i-1][j-1];
      fraction c(i, j+1);
      fraction r = up*c;
      acc = acc+r;*/
      
      dp[i][j] = fraction(i, j+1)*dp[i-1][j-1];
      acc = acc + dp[i][j];
    }
    dp[i][0] = fraction(1, 1) - acc;
  }

  /*rep(i, 0, n){
    rep(j, 0, i){
      dp[i][j].print();
      cout << " ";
    }
    cout << endl;
    }*/
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  prec(410);

  int t;
  cin >> t;
  for(int cs=1; cs <=t; cs++){
    int ds, a, b;
    cin >> ds >> a >> b;
    b--;
    //assert(0<=a&&a<444);
    //assert(0<=b&&b<444); 
    fraction f = dp[a][b];

    cout << ds << " ";
    //f.print();
    if( f.d == 1 )
      cout << f.n;
    else
      cout << f.n << "/" << f.d;
    cout << endl;
  }
  
  return 0;
}

