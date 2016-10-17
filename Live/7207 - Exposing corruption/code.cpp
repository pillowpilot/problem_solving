#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vi wdsp;
vi wppp;
vvi gdsp;
vvi gppp;
vi visiteddsp;
vi visitedppp;
vpii tuplasdsp;
vpii tuplasppp;
vvi dp; // dp[ |tuplas| ][ money ]

template <typename P, typename Q>
ostream& operator<<(ostream& os, const pair<P, Q>& p){
  return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
  os << "[";

  if( v.size() != 0 ){
    typename vector<T>::const_iterator iter = begin(v);
    os << *iter;
    iter++;
    while( iter != end(v) ){
      os << ", " << *iter;
      iter++;
    }
  }

  os << "]";
  return os;
}

void dfsppp(int v, int& a, int& b, int& w);
void dfsdsp(int v, int& a, int& b, int& w);

void dfsdsp(int v, int& a, int& b, int& w){
  visiteddsp[v] = 1;
  a++;
  w += wdsp[v];
  for(int i = 0; i < gdsp[v].size(); i++){
    int n = gdsp[v][i];
    if( visitedppp[n] == 0 ){
      dfsppp(n, a, b, w);
    }
  }
}

void dfsppp(int v, int& a, int& b, int& w){
  visitedppp[v] = 1;
  b++;
  w += wppp[v];
  for(int i = 0; i < gppp[v].size(); i++){
    int n = gppp[v][i];
    if( visiteddsp[n] == 0 ){
      dfsdsp(n, a, b, w);
    }
  }
}

int knapsack(int i, int m, const vpii& ws){
  const int members = ws[i].first;
  const int cost = ws[i].second;

  //printf(">> %d %d - %d %d\n", i, m, members, cost);

  if( i == -1 )
    return 0;
  
  if( dp[i][m] != -1 ){
    //printf(">> %d %d - %d %d > %d\n", i, m, members, cost, dp[i][m]);
    return dp[i].at(m);
  }
  
  if(m < cost){
    dp[i][m] =  knapsack(i-1, m, ws);
  }else{
    int ignore = knapsack(i-1, m, ws);
    int add = knapsack(i-1, m - cost, ws) + members;
    dp[i][m] = max(ignore, add);
  }

  //printf(">> %d %d - %d %d > %d\n", i, m, members, cost, dp[i][m]);
  return dp[i][m];
}

int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0); cout.tie(0);

  int d, p, r, b;

  while( cin >> d >> p >> r >> b ){
    wdsp.clear();
    wppp.clear();
    
    gdsp.clear(); gdsp.resize(d);
    gppp.clear(); gppp.resize(p);

    visiteddsp.clear(); visiteddsp.resize(d);
    visitedppp.clear(); visitedppp.resize(p);

    tuplasdsp.clear();
    tuplasppp.clear();

    while( d-- ){
      int x;
      cin >> x;
      wdsp.push_back( x );
    }
    while( p-- ){
      int x;
      cin >> x;
      wppp.push_back( x );
    }

    //cout << wdsp << endl;
    //cout << wppp << endl;

    while( r-- ){
      int x, y;
      cin >> x >> y;
      x--; y--;
      gdsp[x].push_back(y);
      gppp[y].push_back(x);
    }
      
    for(int i = 0; i < gdsp.size(); i++){
      if( visiteddsp[i] == 0 ){
	int a, b, w;
	a = b = w = 0;
	dfsdsp(i, a, b, w);
	//cout << ">>" << w << endl;
	tuplasdsp.push_back( make_pair((b-a), w) );
	tuplasppp.push_back( make_pair((a-b), w) );
      }
    }
    for(int i = 0; i < gppp.size(); i++){
      if( visitedppp[i] == 0 ){
	int a, b, w;
	a = b = w = 0;
	dfsppp(i, a, b, w);
	//cout << ">>" << w << endl;
	tuplasdsp.push_back( make_pair((b-a), w) );
	tuplasppp.push_back( make_pair((a-b), w) );
      }
    }

    //cout << tuplasdsp << endl;
    //cout << tuplasppp << endl;

    dp.clear();
    dp.resize(tuplasdsp.size());
    for(vi& v: dp){
      v.resize(b+1);
      fill(begin(v), end(v), -1);
    }
    int ansdsp = wdsp.size() + knapsack(tuplasdsp.size() - 1, b, tuplasdsp);

    //cout << dp << endl;

    dp.clear();
    dp.resize(tuplasppp.size());
    for(vi& v: dp){
      v.resize(b+1);
      fill(begin(v), end(v), -1);
    }
    //cout << dp << endl;
    int ansppp = wppp.size() + knapsack(tuplasppp.size() - 1, b, tuplasppp);
    //    cout << dp << endl;

    cout << ansdsp << " " << ansppp << endl;    
    //cout << "-----" << endl;
  }
  
  
  return 0;
}

// AC
