#include <iostream>
#include <vector>
#include <string>
#include <cassert>

#define debug(x) cerr << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

struct BIT{
  vll ft; // 1-based
  // Use add to init
  BIT(int n): ft(n+1, 0) {} //*
  inline int lob(int k){ return k&-k; }
  void add(int k, ll v){
    assert(1<=k);
    while( k < ft.size() ){
      ft[k] += v; //*
      k += lob(k);
    }
  }
  ll sum(int k){
    ll s = 0;
    while( k ){
      s += ft[k]; //*
      k -= lob(k);
    }
    return s;
  }
  ll sum(int a, int b){ // [a, b]
    assert(1<=a && a<=b);
    return sum(b)-sum(a-1); //*
  }
};


int main(){
  int n, k;
  while( cin >> n >> k ){
    BIT pos(n);
    BIT neg(n);
    BIT zer(n);
    rep(i, 1, n){
      int v; cin >> v;
      if( v == 0 ) zer.add(i, 1);
      if( v > 0 ) pos.add(i, 1);
      if( v < 0 ) neg.add(i, 1);
    }
    rep(i, 1, k){
      int a, b;
      string qt;
      cin >> qt >> a >> b;
      if( qt == "C" ){
	zer.add(a, 0-zer.sum(a, a));
	pos.add(a, 0-pos.sum(a, a));
	neg.add(a, 0-neg.sum(a, a));
      
	if( b == 0 ) zer.add(a, 1);
	if( b > 0 ) pos.add(a, 1);
	if( b < 0 ) neg.add(a, 1);
      }else{
	ll zeroc = zer.sum(a, b);
	if( zeroc == 0 ){
	  ll negc = neg.sum(a, b);
	  if( negc%2 != 0 )
	    cout << "-";
	  else
	    cout << "+";
	}else{
	  cout << "0";
	}
      }
    }
    cout << endl;
  }
  return 0;
}

// AC
/*
  Multiple use of BIT. Reduce the problem to count positives, negatives and zeros in a range.
  
  Notice that BIT pos is not necesary.
 */

