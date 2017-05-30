/*
  ID: carlos.16
  PROG: milk3
  LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

#define debug(x) cout << #x << " = " << x << endl;
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

typedef long long ll;
typedef map<ll, bool> mllb;

int A, B, C;

struct state{
  vector<int> caps;
  state(const state& s){
    int a = s.caps[0];
    int b = s.caps[1];
    int c = s.caps[2];
    caps = {a, b, c};
  }
  state(){
    caps = {0, 0, 0};
  }
  ll id(){
    return caps[0]*100*100 + caps[1]*100 + caps[2];
  }
  int max(int b){ // Max cap of bucket a
    int maxCap;
    if( b == 0 ) maxCap = A;
    if( b == 1 ) maxCap = B;
    if( b == 2 ) maxCap = C;
    return maxCap;
  }
  bool arePourable(int a, int b){ // From a to b
    int maxCap = max(b);
    return caps[a] != 0 && caps[b] < maxCap;
  }
  void pour(int a, int b){ // From a to b
    int x = max(b) - caps[b];
    //debug(x);
    int y = min(x, caps[a]);
    //debug(y);
    caps[a] -= y;
    caps[b] += y;
  }
  bool valid(){
    return caps[0] == 0;
  }
  void print(){
    cout << caps[0] << "/" << A << ", " << caps[1] << "/" << B << ", " << caps[2] << "/" << C << endl;
  }
};

mllb visited;
vector<int> ans;
void dfs(state s){
  //s.print();
  if( s.valid() ){
    ans.push_back(s.caps[2]);
  }
  visited[s.id()] = true;
  vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {1, 2}, {2, 1}, {0, 2}, {2, 0}};
  for(pair<int, int> move: moves){
    int a = move.first;
    int b = move.second;
    if( s.arePourable(a, b) ){
      state n(s);
      n.pour(a, b);
      if( visited.find(n.id()) == visited.end() ) dfs(n);
    }
  }
}


int main(){
  ifstream input("milk3.in");
  ofstream output("milk3.out");

  input >> A >> B >> C;

  state s;
  s.caps[2] = C;

  dfs(s);

  sort(all(ans));
  rep(i, 0, ans.size()-2){
    cout << ans[i] << " ";
    output << ans[i] << " ";
  }
  cout << ans[ans.size()-1] << endl;
  output << ans[ans.size()-1] << endl;
    
  return 0;
}

// AC
/*
  Notice that we can build a directed graph from this problem. Every node is a state of the buckets. 
  There are at most 20*20*20 possible states/nodes and 20^3^2 possible edges (~64M). So we can build the graph explicitly.
  On the other hand, we just need to remember which states we already visited and this is possible using a set/map (lg n).
  Notice that every state/node can only have up to, 6 out going edges. O(1).
  Finally, lets n := #achivable states (hard? to calculate) <= 20^3 and O(n lg n).
 */
