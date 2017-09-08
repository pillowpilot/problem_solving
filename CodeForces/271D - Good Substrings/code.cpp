#include <bits/stdc++.h>
#define forall(it, m) for(auto it=m.begin(); it != m.end(); ++it)
#define rep(i, a, b) for(int i=a;i<b; i++)
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

vector<bool> isBad('z'-'a'+1, false);

int gid(0);
struct trie{
  int id = gid++;
  int badChar = 0;
  map<char, trie> m;
  void add(const string& s, int p=0){
    if( p<s.size() ) m[s[p]].add(s, p+1);
  }
  void dfs(){
    // Do stuff
    forall(iter, m){
      char c = iter->first;
      if( isBad[c-'a'] )
	iter->second.badChar = badChar+1;
      else
	iter->second.badChar = badChar;
      iter->second.dfs();
    }
  }
  int dfs2(int k){
    if( badChar > k )
      return 0;
    int ans = 0;
    forall(iter, m){
      ans += iter->second.dfs2(k);
    }
    return ans+1;
  }
  void print()const{
    forall(iter, m){
      cout << id << ":[" << badChar << "] " <<
	iter->second.id << ":[" << iter->second.badChar << "] " <<
	iter->first << endl;
      iter->second.print();
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  string bb;
  int k;
  cin >> s >> bb >> k;

  rep(i, 0, bb.size()){
    if( bb[i] == '0' ) isBad[i] = true;
    else isBad[i] = false;
  }

  trie t;
  rep(i, 0, s.size()){
    t.add(s, i);
  }

  t.dfs();
  
  int ans = t.dfs2(k);
  //t.print();
  cout << ans-1 << endl;

  return 0;
}

// AC
/*
  First implementation of suffix tree (trie of suffixes).
  Build a trie of all suffixes in O(n^2)
  dfs+dp to calculate how many bad characters the substring from the root to the actual node.
  dfs to count how many nodes has badChar counter <= k
  substract one because the root is also counted (empty substr).
 */
