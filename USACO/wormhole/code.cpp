/*
  ID: carlos.16
  PROG: wormhole
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef vector<int> vi;

int n;
vi xs, ys, next, parner;

void buildNext(){
  rep(i, 0, n-1){
    rep(j, 0, n-1){
      if( ys[i] == ys[j] && xs[i] < xs[j] )
	if( next[i] == -1 )
	  next[i] = j;
	else{
	  int k = next[i];
	  if( xs[j] < xs[k] )
	    next[i] = j;
	}
    }
  }
  /*rep(i, 0, n-1){
    int x = xs[i];
    int y = ys[i];
    cout << "(" << x << ", " << y << ") -> ";
    if( next[i] != -1 ){
      int a = xs[next[i]];
      int b = ys[next[i]];
      cout << "(" << a << ", " << b << ")";
    }
    cout << endl;
  }*/
}

bool dfs(vector<bool>& visited, int w){
  if( visited[w] )
    return true;
  else{
    int p = next[parner[w]];
    if( p == -1 )
      return false;
    else{
      visited[w] = visited[parner[w]] = true;
      bool ans =  dfs(visited, next[parner[w]]);
      visited[w] = visited[parner[w]] = false;
      return ans;
    }
  }
}

void print(const vector<int>& v){
  rep(i, 0, v.size()-1){
    cout << v[i] << " ";
  }
  cout << endl;
}

bool cycle(){
  /*rep(i, 0, n-1){
    cout << i << " is with " << parner[i] << endl;
  }
  cout << endl;*/
  //print(parner);
  //  print(next);

  vector<bool> visited(n, false);
  rep(i, 0, n-1){
    //debug(i);
    fill(all(visited), false);
    int p = i;
    while( p != -1 && visited[p] == false ){
      //debug(p);
      visited[p] = true;
      p = next[parner[p]];
    }
    if( p != -1 ){
      /*cout << "from " << i << endl;
      rep(j, 0, n-1){
	cout << j << ":" << next[parner[j]] << " ";
      }
      cout << endl;*/
      return true;
    }
  }
  return false;
}

int bt(int w){
  //debug(w);
  if( w == n ){
    if( cycle() ) return 1;
    else return 0;
  }else{
    int ans = 0;
    
    int a;
    rep(i, 0, n-1){
      if( parner[i] == -1 ){
	a = i;
	break;
      }
    }

    rep(j, a+1, n-1){
      if( parner[j] == -1 ){
	parner[a] = j;
	parner[j] = a;
	ans += bt(w+2);
	parner[a] = parner[j] = -1;
      }
    }
    return ans;
  }
}

int main(){
  ifstream input("wormhole.in");
  ofstream output("wormhole.out");

  input >> n;
  rep(i, 1, n){
    int x, y;
    input >> x >> y;
    xs.pb(x);
    ys.pb(y);
    next.pb(-1);
    parner.pb(-1);
  }
  buildNext();

  int ans = bt(0);

  //cout << ans << endl;
  output << ans << endl;
  
  return 0;
}

// AC
/*
  Tricky BT. 
  BT to build every pairing ONLY once (associate every call of bt to a SINGLE node).
  Check cycles simulating and notice that going through a~b is not the same as going through b~a.
 */
