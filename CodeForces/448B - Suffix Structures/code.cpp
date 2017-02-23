#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define debug(x)       { cerr << #x << " = " << x << endl; }

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool constructible(const string& s, const string& t){
  int n = 'z'-'a'+1;
  
  vi cc(n);
  for(char c: s)
    cc[c-'a']++;
  
  for(char c: t)
    cc[c-'a']--;

  int i = 0;
  while( i < cc.size() && cc[i] >= 0 )
    i++;
  
  return i == cc.size();
}

bool eq(const string& s, const string& t){
  string a(s), b(t);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return a == b;
}


vvi dp(111, vi(111));

bool constructible_auto(const string& s, const string& t, int i, int j){
  if( dp[i][j] != 0 )
    return dp[i][j] == 1;
  
  if( t.size() == j )
    return true;
  
  if( s.size() == i && j < t.size())
    return false;
  
  for(int k = i; k < s.size(); k++){
    if( s[k] == t[j] ){
      //cerr << k << " and " << j << " matched!" << endl;
      if( constructible_auto(s, t, k+1, j+1) ){
	dp[i][j] = 1;
	return true;
      }
    }
  }

  dp[i][j] = -1;
  return false;
}

int main(){
  string s, t;
  cin >> s >> t;

  if( !constructible(s, t) )
    cout << "need tree" << endl;
  else if( eq(s, t) )
    cout << "array" << endl;
  else if( constructible_auto(s, t, 0, 0) )
    cout << "automaton" << endl;
  else
    cout << "both" << endl;
  
    
  return 0;
}

// AC
// t is constructible from s iff no exist c in t such that c in s
// t is constructible with a s array iff t is a permutation of s
// t is constructible with automaton iff
// dp[i, j] = exist k such that dp[k, j+1] and s[k] = t[j] and i <= k
// dp[|s|, j] = j == |t|
// only |s||t| possible states
