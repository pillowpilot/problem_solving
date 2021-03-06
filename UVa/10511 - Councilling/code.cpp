#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <set>

#define INF 1 << 31
#define pb push_back
#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<int> vi;
typedef unordered_map<string, int> usi;

struct edmondskarp{
  int n, s, t;
  vvl cap, residual;
  vi parent;

  edmondskarp(int n):
    n(n), cap(n, vll(n)), residual(n, vll(n)), parent(n)
  {}

  bool findpath(){
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    while( !q.empty() ){
      int v = q.front(); q.pop();

      visited[v] = true;
      rep(i, 0, n-1){
	if( !visited[i] && residual[v][i] > 0 ){
	  parent[i] = v;
	  q.push(i);
	}
      }
    }

    return visited[t];
  }

  ll apply(){
    ll pflow = INF;
    
    int v = t;
    while( v != s ){
      int p = parent[v];
      pflow = min(pflow, residual[p][v]);
      v = p;
    }

    v = t;
    while( v != s ){
      int p = parent[v];
      residual[p][v] -= pflow;
      residual[v][p] += pflow;
      v = p;
    }

    return pflow;
  }

  ll get(int s, int t){
    this->s = s;
    this->t = t;

    rep(i, 0, n-1){
      rep(j, 0, n-1){
	residual[i][j] = cap[i][j];
      }
    }

    ll flow = 0;
    while( findpath() ){
      flow += apply();
    }

    return flow;
  }
};

int main(){
  string line;
  getline(cin, line);
  istringstream oss(line);

  getline(cin, line);
  int t;
  oss >> t;
  while( t-- ){
    vector<string> data;
    set<string> clubs;
    set<string> parties;
    map<string, int> mapping;
    
    while( getline(cin, line) && line != "" ){
      data.pb(line);
    }

    rep(i, 0, data.size()-1){
      oss.clear();
      oss.str(data[i]);

      string w;
      oss >> w >> w;
      clubs.insert(w);
      while( oss >> w ){
	parties.insert(w);
      }
    }

    {
      auto iter = clubs.begin();
      while( iter != clubs.end() ){
	cout << "club: " << *iter << endl;
	iter++;
      }
    }

    {
      auto iter = parties.begin();
      while( iter != parties.end() ){
	cout << "party: " << *iter << endl;
	iter++;
      }
    }
    
    //edmondskarp ek(clubs.size()+parties.size()+2);
    
    {
      auto iter = parties.begin();
      while( iter != parties.end() ){
	cout << *iter << " : " << distance(parties.begin(), iter) << endl;
	iter++;
      }
    }
  }
  
  return 0;
}
