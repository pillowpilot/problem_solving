#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

#define debug(x) cout << (#x) << " = " << (x) << endl;
#define rep(i, a, b) for(__typeof(a) i = a; i <= b; i++)
#define repi(i, a, b) for(__typeof(a) i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define INF 1 << 30

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvl;
typedef vector<bool> vb;
typedef vector<int> vi;

/*
  Maximum Flow - Edmonds Karp
  O(V^3 E)
 */

struct edmondskarp{
  int n, s, t;
  vvl cap, residual;
  vi parent;

  edmondskarp(int n):
    n(n), cap(n, vll(n)), parent(n, -1), residual(n, vll(n))
  {}

  void addEdge(int from, int to, int cap){
    assert(0<=from && from < n);
    assert(0<=to && to < n);
    assert(0<=cap);
    
    this->cap[from][to] += cap; // If multiple edges between same vertices
  }

  bool findAugmentingPath(){
    vb visited(n, false);
    fill(all(parent), -1);

    queue<int> q;
    q.push(s);
    while( !q.empty() && !visited[t] ){ // Break if path found!
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

  ll addFlow(){ // Assume that there is a path
    int v;
    ll pflow = INF;
    
    v = t;
    while( v != s ){
      int p = parent[v];
      pflow = min(pflow, residual[p][v]);
      v = p;
    }

    v = t;
    while( v != s ){
      int p = parent[v];
      residual[v][p] += pflow;
      residual[p][v] -= pflow;
      v = p;
    }

    return pflow;
  }

  void initResidualGraph(){
    rep(i, 0, n-1){
      rep(j, 0, n-1){
   	residual[i][j] = cap[i][j];
      }
    }
    
  }

  ll getMaxFlow(int s, int t){
    this->s = s;
    this->t = t;
    initResidualGraph();
    ll maxflow = 0;
    while( findAugmentingPath() ){
      maxflow += addFlow();
    }
    return maxflow;
  }
};

int main(){
  int t;
  cin >> t;
  while( t-- ){
    int n;
    cin >> n;

    edmondskarp mf(n);
    rep(i, 1, n-1){
      int a;
      cin >> a;
      while( a-- ){
	int b;
	cin >> b;

	ll c = INF;
	if( i-1 == 0 || b-1 == n-1 )
	  c = 1; // If (source, x) or (x, target)
	mf.addEdge(i-1, b-1, c);
      }
    }

    ll ans = mf.getMaxFlow(0, n-1);
    cout << ans << endl;
  }
  return 0;
}

// AC
