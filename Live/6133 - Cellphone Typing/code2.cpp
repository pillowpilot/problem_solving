#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cassert>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

template <typename T>
ostream& operator<<(ostream&, const vector<T>& v);
template <typename T>
ostream& operator<<(ostream& os, const vector<vector<T>>& m);

vvi g;
vc data;

void insert(const string& str, int i, int node){
  if( i == str.size() ){
    data.push_back( '$' ); // End of a word
    g.push_back( vi() );
    g[node].push_back( data.size() - 1 ); 
  }else{
    int n = 0;
    while( n < g[node].size() && data[ g[node][n] ] != str[i] )
      n++;

    if( n < g[node].size() && data[ g[node][n] ] == str[i] ){
      insert( str, i+1, g[node][n] );
    }else{
      data.push_back( str[i] );
      g.push_back( vi() );
      g[node].push_back( data.size() - 1 );
      insert( str, i+1, data.size() - 1 );
    }
  }
}

int dfs(int node, int cumsum){
  int ans = 0;
  if( data[node] == '#' ){
    for(int i = 0; i < g[node].size(); i++){
      ans += dfs( g[node][i], 1 );
    }
  }else{
    if( g[node].size() == 0 ){ // leaf
      ans = cumsum;
    }else if( g[node].size() == 1 ){
      ans = dfs( g[node][0] , cumsum);
    }else{
      for(int i = 0; i < g[node].size(); i++){
	if( data[ g[node][i] ] == '$' ){
	  ans += dfs( g[node][i], cumsum );
	}else{
	  ans += dfs( g[node][i], cumsum+1 );
	}
      }
    }
  }

  return ans;
}

int main(){
  
  int n;
  while( cin >> n ){
    g.clear();
    data.clear();
    
    g.push_back( vi() ); // empty root
    data.push_back( '#' ); 
        
    for(int i = 0; i < n; i++){
      string s;
      cin >> s;
      insert(s, 0, 0);
    }

    int ans = dfs(0, 0);
    //cout << ans << endl;
    double avg = (double) ans / n;
    cout << fixed;
    cout << setprecision(2) << avg << endl;
  }
  
  return 0;
}

// AC

/*
  trie + dfs with a corner case
 */
