/*
  ID: carlos.16
  PROG: ariprog
  LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>

#define debug(x) cout << #x << " = " << x << endl;
#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

int main(){
  ifstream input("ariprog.in");
  ofstream output("ariprog.out");

  int n, m;
  input >> n >> m;

  vector<bool> valid(2*m*m+1, false);
  rep(i, 0, m){
    rep(j, 0, m){
      int a = i*i+j*j;
      if( a < valid.size() ){
	valid[a] = true;
      }
      if( a >= valid.size() )
	break;
    }
  }
  


  // O(m)
  /*vector<int> squares;
  rep(i, 0, sqrt(2*m*m)){
    squares.push_back(i*i);
  }
  rep(i, 0, squares.size()-1){
    rep(j, 0, squares.size()-1){
      int a = squares[i]+squares[j];
      if( a < valid.size() ) valid[a] = true;
    }
    }*/
  // if valid[i], then i in bisquare set

  int getin = 0;

  set<pair<int, int>> ans;
  rep(a, 0, valid.size()-1){
    if( valid[a] == true ){ // Really important!
      getin++;
      rep(b, 1, valid.size()-1){
	if( a+(n-1)*b >= valid.size() )
	  break;
	//debug(a);
	//debug(b);
	int k = 0;
	int e = a;
	while( k < n && valid[e] == true ){
	  //debug(k);
	  k++;
	  e += b;
	}
	if( k == n )
	  ans.insert({b, a});
      }
    }
  }

  cout << "Only " << getin << " times of " << valid.size() << endl;

  if( ans.empty() ){
    cout << "NONE" << endl;
    output << "NONE" << endl;
  }else{
    set<pair<int, int>>::const_iterator iter = ans.begin();
    while( iter != ans.end() ){
      int a = iter->second;
      int b = iter->first;
      cout << a << " " << b << endl;
      output << a << " " << b << endl;
      iter++;
    }
  }
  
  return 0;
}

// AC
/*
  Simple BT. However notice the line marked as Really Important!
  a+kb=pp+qq for all k, including k=0. Then a=pp+qq.
  This reduce from 80k to ~14k for m=200.
 */
