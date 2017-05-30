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

struct maxflow{
  int n, s, t;
  vvl cap, residual;
  vb visited;
  vi parent;

  maxflow(int n):
    n(n), cap(n, vll(n, 0)), visited(n, false), parent(n, -1), residual(n, vll(n, 0))
  {}

  void addEdge(int from, int to, int cap){
    assert(0<=from && from < n);
    assert(0<=to && to < n);
    assert(0<=cap);
    
    this->cap[from][to] += cap; // In case (from, to) has been already loaded!
  }

  bool augmentingPath(){
    fill(all(visited), false);
    fill(all(parent), -1);

    queue<int> q;
    q.push(s);
    while( !q.empty() && !visited[t] ){
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
    int v = t;
    ll pflow = INF;
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

  ll getmf(int s, int t){
    this->s = s;
    this->t = t;
    initResidualGraph();
    ll mf = 0;
    while( augmentingPath() ){
      ll deltaflow = addFlow();
      mf += deltaflow;
    }
    return mf;
  }

};

int main(){
  maxflow mf('z'-'A'+1);
  
  int n;
  cin >> n;

  while( n-- ){
    char a, b;
    int c;
    cin >> a >> b >> c;
    mf.addEdge(a-'A', b-'A', c);
  }

  ll ans = mf.getmf('A'-'A', 'Z'-'A');
  cout << ans << endl;
}

// AC

/*
  MAx flow. Multiple edges between same vertices!
 */
