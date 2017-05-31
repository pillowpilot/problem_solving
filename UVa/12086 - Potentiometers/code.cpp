#include <iostream>
#include <vector>
#include <cassert>
#include <string>

#define debug(x) //cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

struct BIT{
  vll ft; // 1-based
  // Use add to init
  BIT(int n): ft(n+1, 0) {}
  inline int lob(int k){ return k&-k; }
  void add(int k, ll v){
    assert(1<=k);
    while( k < ft.size() ){
      ft[k] += v;
      k += lob(k);
    }
  }
  ll sum(int k){
    ll s = 0;
    while( k ){
      s += ft[k];
      k -= lob(k);
    }
    return s;
  }
  ll sum(int a, int b){ // [a, b]
    assert(1<=a && a<=b);
    return sum(b)-sum(a-1);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int casec = 0;
  int n;
  cin >> n;
  while( n != 0 ){
    if( casec > 0 )
      cout << "\n";
    casec++;
    BIT ft(n);
    rep(i, 1, n){
      int v;
      cin >> v;
      ft.add(i, v);
    }
    cout << "Case " << casec << ":" << endl;
    string qt;
    cin >> qt;
    while( qt != "END" ){
      int a, b;
      cin >> a >> b; // already 1-based
      if( qt == "S" ){
	ft.add(a, b-ft.sum(a, a));
      }else{
	cout << ft.sum(a, b) << endl;
      }
      cin >> qt;
    }
    cin >> n;
  }
  return 0;
}

// AC
/*
  Tipical RSQ. Use BIT or ST.
 */
