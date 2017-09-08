#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define debug(x) //cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void print(const vll v){
  return ;
  rep(i, 0, v.size()){
    cout << v[i] << " ";
  }
  cout << endl;
}

vll prefix(const vll v){
  int n = v.size();
  vll p(n);
  p[0] = 0;
  int k = 0;
  rep(i, 1, n){
    while( k > 0 && v[k] != v[i] )
      k = p[k-1];
    if( v[k] == v[i] )
      k++;
    p[i] = k;
  }
  return p;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, w;
  cin >> n >> w;

  int x;
  vll tv;
  cin >> x;
  rep(i, 1, n){
    int y;
    cin >> y;
    tv.push_back(y-x);
    x = y;
  }

  vll pv;
  cin >> x;
  rep(i, 1, w){
    int y;
    cin >> y;
    pv.push_back(y-x);
    x = y;
  }

  /*cout << "*" << endl;
  rep(i, 0, n-1){
    cout << tv[i] << " ";
  }
  cout << endl;

  rep(i, 0, w-1){
    cout << pv[i] << " ";
  }
  cout << endl;
  
  cout << "*" << endl;*/

  vll ppv;
  rep(i, 0, pv.size()){
    ppv.push_back(pv[i]);
  }
  ppv.push_back((ll)1LL<<60);
  rep(i, 0, tv.size()){
    ppv.push_back(tv[i]);
  }

  //cout << "**" << endl;
  vll pref = prefix(ppv);

  int ans = 0;
  rep(i, 0, pref.size()){
    if( pref[i] == w-1 )
      ans++;
  }

  cout << ans << endl;

  debug("Prefix");
  print(pref);
 
  
  return 0;
}

// AC
/*
  Pattern search in O(n). KMP/Prefix Function/Z Function/Rolling Hashing
  Notice that what matters are not the pattern (seq of w items) absolute values, 
  but their relative values. So [2 3 3 2 1] -> [1 0 -1 -1]. Apply the same transformation
  to the text (seq of n items) and search.

  With Prefix Function, build the string P#T where P is the pattern and T the text.
  Then look for every value equal to |p|.
 */
