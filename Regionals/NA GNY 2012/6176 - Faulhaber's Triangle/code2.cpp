#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct frac{
  ll n, d;
  frac():n(0), d(1)
  {}
  frac(ll a, ll b)
  {
    ll g = __gcd(a, b);
    a/=g;
    b/=g;

    ll sgn;
    if(a*b<0)
      sgn = -1;
    else
      sgn = 1;
    a = llabs(a);
    b = llabs(b);

    n = sgn*a;
    d = b;
    
    /*
    if( b < 0 ){
      a *= -1;
      b *= -1;
    }
    n=a;
    d=b;
    */
  }
  frac operator+(frac f){
    return frac(n*f.d+f.n*d, f.d*d);
  }
  frac operator-(frac f){
    return frac(n*f.d-f.n*d, f.d*d);
  }
  frac operator*(frac f){
    return frac(f.n*n, f.d*d);
  }
  void print(){
    cout << n;
    if( d != 1 )
      cout << "/" << d;
  }
};

typedef vector<frac> vf;
typedef vector<vf> vvf;

vvf ff;
void prep(int n){
  ff = vvf(n, vf(n));

  ff[0][0] = frac(1, 1);
  for(int i = 1; i < n; i++){
    frac acc;
    for(int j = 1; j <=i; j++){
      ff[i][j] = frac(i, j+1)*ff[i-1][j-1];
      acc = acc+ff[i][j];
    }
    ff[i][0] = frac(1, 1)-acc;
  }

  /*for(int i = 0; i < n; i++){
    for(int j = 0; j <=i; j++){
    ff[i][j].print();
    cout << " ";
    }
    cout << endl;
    }*/
}

int main(){
  prep(444);

  int n;
  cin >> n;
  while( n-- ){
    int test, a, b;
    cin >> test >> a >> b;

    frac f = ff[a][b-1];

    cout << test << " ";
    f.print();
    cout << endl;
  }
      return 0;
}

// AC
/*
  An annoying RE raise with the commented code in constructor.
  
  Precalc the entire space and print queries in O(1)
 */
