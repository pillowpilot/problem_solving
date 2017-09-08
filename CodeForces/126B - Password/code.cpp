#include <bits/stdc++.h>
#define debug(x) //cout << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;
typedef vector<int> vi;

vector<int> prefix(const string s){
  const int n = s.size();
  vector<int> v(n);
  v[0] = 0;
  int k = 0;
  for(int i=1; i<n; i++){
    while( k > 0 && s[k]!=s[i] )
      k = v[k-1];
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
  cin >> s;

  vi ps = prefix(s);
  vi found(ps.size());

  rep(i, 1, ps.size()-1){
    found[ ps[i] ]++;
  }

  debug(s);
  debug(ps);
  debug(found);

  int k = ps.back();
  debug(k);
  while( k != 0 && found[k] == 0 ){
    k = ps[k-1];
    debug(k);
    //cout << s.substr(0, k) << endl;
  }
  
  //return 0;
  
  if( k == 0 ){
    cout << "Just a legend" << endl;
  }else{
    cout << s.substr(0, k) << endl;
  }
  
  return 0;
}

// AC
/*
  Trivial aplication of prefix function.
  For every prefix that is also a suffix of the entire string S.
  Check if is present in S[1..|S|-2].
  Because the prefix function domain is n <= |S| and because
  the middle occurence will have a prefix value equal to the
  prefix and suffix occurence, we can check in O(1) storing
  isFound information.
 */
