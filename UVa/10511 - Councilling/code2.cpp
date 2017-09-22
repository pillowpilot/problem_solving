#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define debug(x) //cout << #x << " = " << x << endl;
#define rep(i, a, b) for(int i=a;i<b;i++)

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
  Adjacency list implementation of FIFO push relabel maximum flow
  with the gap relabeling heuristic. O(|V|^3)
  
  PushRelabel is O(|V|^2*|E|),
  however using the FIFO selection rule is O(|V|^3).

  It solves random problems with 10000 vertices and 1000000 edges in a few
  seconds, though it is possible to construct test cases that
  achieve the worst-case.

  INPUT:
  - Build using directed edges with AddEdge
  - GetMaxFlow(u, v) runs algorithm with source u and target t

  OUTPUT:
  - maximum flow value
  - in/out flow with GetIn/OutFlow
  - To obtain the actual flow values, look at all edges with
  capacity > 0 (zero capacity edges are residual edges).
*/
struct Edge {
  // Added
  string name;
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
  friend ostream& operator<<(ostream& os, const Edge& e){
    return os << "(" << e.from << "->" << e.to << ") " << e.flow << "/" << e.cap << " [" << e.index << "]";
  }
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<ll> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  /*
    Add an directed edge (from, to) with capacity cap.
    Supports self-loops
   */
  void AddEdge(int from, int to, int cap, string name) {
    assert(0<=from&&0<=to);
    assert(from<G.size()&&to<G.size());
    
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    G[from].back().name = name;
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
    G[to].back().name = name;
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], ll(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  /*
    Get maxFlow from s to t.
   */
  ll GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    ll totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }

  ll GetOutFlow(int v) const {
    ll outflow = 0;
    rep(i, 0, G[v].size()){
      if(G[v][i].cap > 0 ){
	outflow += G[v][i].flow;
      }
    }
    return outflow;
  }

  ll GetInFlow(int v) const {    
    ll inflow = 0;
    rep(i, 0, G[v].size()){
      if(G[v][i].cap == 0){	
	inflow += G[G[v][i].to][G[v][i].index].flow;
      }
    }
    return inflow;
  }

  void print() const {
    rep(i, 0, G.size()){
      rep(j, 0, G[i].size()){
	Edge e = G[i][j];
	if( e.cap > 0 ){
	  cout << e.from << " " << e.to << " " << e.flow << "/" << e.cap <<  "\n";
	}
      }
    }
  }
};

struct input{
  string name;
  string party;
  vector<string> clubs;
  void read(string line){
    stringstream oss(line);
    oss >> name >> party;
    string club;
    while( oss >> club ){
      clubs.push_back(club);
    }
  }
};


int n, m, k;
inline int club(int x){ return 1+x; }
inline int person(int x){ return n+1+x; }
inline int party(int x){ return n+k+1+x; }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tests;
  cin >> tests;
  string line;
  getline(cin, line);
  getline(cin, line);
  rep(test_id, 0, tests){
    if( test_id > 0 )
      cout << "\n";
    vector<input> inputs;
    while( getline(cin, line) && line != "" ){
      input i;
      i.read(line);
      inputs.push_back(i);
      //cout << "DATA: " << line << endl;
      debug(line);
    }

    map<string, int> parties_id;
    map<string, int> clubs_id;
    map<int, string> id_clubs;

    rep(i, 0, inputs.size()){
      input a = inputs[i];
      if( parties_id.find(a.party) == parties_id.end()  ){
	parties_id[a.party] = parties_id.size()-1;
      }
      rep(j, 0, a.clubs.size()){
	if( clubs_id.find(a.clubs[j]) == clubs_id.end()){
	  clubs_id[a.clubs[j]] = clubs_id.size()-1;
	}
      }
    }
    for(auto iter:clubs_id){
      id_clubs[iter.second]=iter.first;
    }

    if(!true) {
      for(auto iter: parties_id)
	cout << iter.first << " : " << iter.second << endl;
      cout << endl;
      for(auto iter: clubs_id)
	cout << iter.first << " : " << iter.second << endl;
      cout << endl;
    }
    
    n = clubs_id.size();
    m = parties_id.size();
    k = inputs.size(); // #persons

    debug(n);
    debug(k);
    debug(m);

    PushRelabel g(n+k+m+2);
    // source = 0; clubs = [1, n]; persons = [n+1, n+k]; parties = [n+k+1, n+k+m]; target = n+k+m+1
    int source = 0;
    int target = n+k+m+1;

    rep(i, 0, n){
      g.AddEdge(source, club(i), 1, "");
    }
    rep(i, 0, k){
      string name = inputs[i].name;
      int party_id = parties_id[inputs[i].party];
      g.AddEdge(person(i), party(party_id), 1, name);
      rep(j, 0, inputs[i].clubs.size()){
	int club_id = clubs_id[inputs[i].clubs[j]];
	g.AddEdge(club(club_id), person(i), 1, name);
      }   
    }
    
    int max_members = (n%2==0)?(n/2)-1:n/2;
    rep(i, 0, m){
      g.AddEdge(party(i), target, max_members, "");
    }

    ll mf = g.GetMaxFlow(source, target);
    //g.print();

    debug(mf);
    debug(g.GetOutFlow(source));
    if( g.GetOutFlow(source) != n ){
      cout << "Impossible.\n";
    }else{
      vector<string> output;
      rep(i, 0, n){
	rep(j, 0, g.G[club(i)].size()){
	  Edge e = g.G[club(i)][j];
	  if( e.cap > 0 && e.flow > 0 ){
	    string club_name = id_clubs[i];
	    //cout << e.name << " " << club_name << "\n";	    
	    output.push_back(e.name+" "+club_name);
	  }
	}
      }
      sort(all(output));
      rep(i, 0, output.size()){
	cout << output[i] << "\n";
      }
    }

    debug("new testcase");
  } 

  return 0;
}

// AC
/*
  MaxFlow with incredibly annoying input.
  The graph consist in a source, 3 layers of nodes (clubs, persons and parties) and a target.

  Between the source and every club, add an edge of cap 1. This ensures that every club can 
  submit at most one member.

  There is an edge with cap 1 between a club node and a person node if that person belongs to that club.
  I believe that cap >1 is enough.

  Again, an edge with cap 1 between a person and a party if that person belongs to the party.

  An edge with cap x between every party and the target. x force the maximum amount of council
  members each party could have. Because every club MUST have a member in the council, n = #clubs = #council members. Therefore, x = if 2|n, then n/2-1, else (n-1)/2.

  Finally, check outflow of source. It must be equal to n = #clubs. To reconstruc the solution, check for every
  club an edge with cap > 0 and flow > 0. There must be only one. I store the names in the edges, but a 
  simple mapping should be enough.
 */
