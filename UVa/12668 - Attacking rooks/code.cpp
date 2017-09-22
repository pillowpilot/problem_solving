#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a;i<b;i++)
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi m;
vvi maprow, mapcol;
vvi w;

void print(const vvi v){
  return ;
  rep(i, 0, v.size()){
    rep(j, 0, v[i].size()){
      cout << fixed << setw(2) << v[i][j];
    }
    cout << endl;    
  }
  cout << endl;
}

void fillMapping(){
  const int n = m.size();

  int mapping = 0;
  rep(i, 0, n){
    rep(j, 0, n){
      if( m[i][j] == 0 ) maprow[i][j] = mapping;	
      else mapping++;
    }
    mapping++;
  }
  w.resize(mapping);

  mapping = 0;
  rep(j, 0, n){
    rep(i, 0, n){
      if( m[i][j] == 0 ) mapcol[i][j] = mapping;
      else mapping++;
    }
    mapping++;
  }
  fill(all(w), vi(mapping, 0));
  
  print(m);
  print(maprow);
  print(mapcol);
  print(w);
}

void buildGraph(){
  const int n = m.size();

  rep(i, 0, n){
    rep(j, 0, n){
      if( m[i][j] == 0 ){
	int idrow = maprow[i][j];
	int idcol = mapcol[i][j];
	w[idrow][idcol] = 1;
      }
    }
  }
  print(w);
}

/*
  Maximum Bipartite Matching

  O(|V||E|) -- usually much faster (in MIT and Stanford nb)
  
  Left column of nodes are rows
  Right column of nodes are columns

  Input: vvi weights[n][m] := 1 if edge. 0 otherwise
  Output: int cardinality:= cardinality
  vi mr[n] := assignment of rows, -1 if no assignment
  vi mc[m] := assignement of cols, -1 if no assignment
 */

bool FindMatch(int i, const vvi &w, vi &mr, vi &mc, vi &seen) {
  const int n = w.size();
  const int m = w[0].size();  
  for (int j = 0; j < m; j++) {    
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const vvi &w, vi &mr, vi &mc) {
  const int n = w.size();
  const int m = w[0].size();
  mr.assign(n, -1);
  mc.assign(m, -1); 
  int ct = 0;
  for (int i = 0; i < n; i++) {
    vi seen(m);
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n;
  while( cin >> n ){
    m.assign(n, vi(n, 0));
    maprow.assign(n, vi(n, 0));
    mapcol.assign(n, vi(n, 0));
    
    rep(i, 0, n){
      string row;
      cin >> row;
      rep(j, 0, n){
	if( row[j] == 'X' )
	  m[i][j] = 1;
      }
    }
    fillMapping();
    buildGraph();

    vi mr, mc;
    int ans = BipartiteMatching(w, mr, mc);

    cout << ans << "\n";
  }  
  
  return 0;
}

// AC
/*
  Clasical Maximum Bipartite Matching. Kuhn's Algorithm. O(|V||E|)
  Build a bipartite graph where the left set is the set of all
  horizontal segments (an empty row->one segment, a row divided by one pawn->two segments, ...)
  Right set is analogous.
  There is an edge between two vertices iff we can place a rook in the corresponding intersection.
 */
