#include <bits/stdc++.h>
#define debug(x) //cout << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<int> prefix(const string s){
  const int n = s.size();
  vector<int> v(n);
  v[0] = 0;
  int k = 0;
  for(int i=1; i<n; i++){
    while( k > 0 && s[k]!=s[i] )
      k = v[k-1]; // To iterate though prefix/suffix
    if( s[k]==s[i] )
      k++;
    v[i] = k;
  }
  return v;
}

ostream& operator<<(ostream& os, const vector<int> v){
  os << "[";
  if( !v.empty() ){
    auto iter = v.begin();
    os << *iter;
    iter++;
    while( iter != v.end() ){
      os << ", " << *iter;
      iter++;
    }
  }
  return os << "]";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  ll l;
  while( cin >> l >> s && l != -1 ){
    vi ps = prefix(s);
    debug(ps);

    ll x = ps.back();
    debug(x);
    debug(l-s.size());

    if( l < s.size() ){
      cout << 0 << "\n";
    }else{
      ll k = (l-x)/(s.size()-x);
      cout << k << "\n";
    }

    debug(endl);
  }
  
  return 0;
}

// AC
/*
  Trivial use of Prefix Function and simple math.
  Notice that the string s could appear more times if
  we use the longest border (prefix that is also a suffix).
  That is the last value of the prefix function.
  
  l-x is the original available space minus the last occurrence of the border.
  s.size()-x is the length of the string without intersection.

  ans = floor((l-x)/(s-x))
 */
