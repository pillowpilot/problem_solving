#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

ll n, k;
vll data;
vll decomposition;

inline int toIndex(int i){
  return i * (int)(sqrt(n));
}
inline int toDeco(int i){
  return i / (int)(sqrt(n));
}

void change(int i, int v){
  data[i] = v;

  int a = toIndex(toDeco(i));
  int b = toIndex(toDeco(i)+1);

  decomposition[ toDeco(a) ] = 1;
  for(int k = a; k < b; k++)
    decomposition[ toDeco(k) ] *= data[k];
}

ll product(int i, int j){
  ll p = 1;

  int a = toIndex( toDeco(i) + 1 );
  int b = toIndex( toDeco(j) );

  if( b < a || a == b ){ // same block or adjacent
    for(int k = i; k <= j; k++)
      p *= data[k];
  }else{
    for(int k = i; k < a; k++) p *= data[k];
    for(int k = b; k <= j; k++) p *= data[k];

    a = toDeco(i)+1;
    b = toDeco(j);

    for(int k = a; k < b; k++)
      p *= decomposition[k];
  }
  
  return p;
}

int main(){
  while( cin >> n >> k ){
    data.clear();
    decomposition.resize( sqrt(n) + 2 ); fill( begin(decomposition), end(decomposition), 1);
    
    for(int i = 0; i < n; i++){
      ll x; cin >> x;
      if( 0 < x ) x = 1;
      if( x < 0 ) x = -1;
      
      data.push_back(x);
      decomposition[ toDeco(i) ] *= x;
    }
    
    while( k-- ){
      char c; cin >> c;
      if( c == 'P' ){
	ll i, j; cin >> i >> j;
	ll ans = product(i-1, j-1);
        if( ans == 0  ) cout << 0;
	if( ans == -1 ) cout << '-';
	if( ans == 1  ) cout << '+';
      }else{
	ll p, v; cin >> p >> v;
	if( v < 0 ) v = -1;
	if( 0 < v ) v = 1;	
	change(p-1, v);
      }
    }

    cout << endl;
    
  }
  return 0;
}

// AC
