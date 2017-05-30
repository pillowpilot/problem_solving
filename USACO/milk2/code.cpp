/*
  ID: carlos.16
  PROG: milk2
  LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)
#define all(x) (x).begin(), (x).end()

using namespace std;

struct event{
  int t, d; // d of delta
  event(int t, int d): t(t), d(d)
  {}
  bool operator<(const event& o){
    return (t<o.t)||(t==o.t&&d<o.d);
  }
  void print(){
    if( d > 0 )
      cout << '+';
    else
      cout << '-';
    cout << t;
  }
};

int main(){
  ifstream input("milk2.in");
  ofstream output("milk2.out");

  int n;
  input >> n;
  vector<event> ee;
  rep(i, 1, n){
    int a, b;
    input >> a >> b;
    event ea(a, +1);
    event eb(b, -1);
    ee.push_back(ea);
    ee.push_back(eb);
  }
  sort(all(ee));

  // if e1.t == e2.t and e1.d != e2.d, then remove then
  vector<event>::iterator iter = ee.begin();
  while( iter != ee.end() ){
    if( iter->t == (iter+1)->t && iter->d != (iter+1)->d ){
      ee.erase(iter, iter+2);
      iter = ee.begin();
    }else
      iter++;
  }

  int max_idle = 0;
  int farmers = 0;
  rep(i, 0, ee.size()-1){
    int d = ee[i].d;
    if( farmers+d == 0 ){
      if( i != ee.size()-1 ){
	max_idle = max(max_idle, ee[i+1].t-ee[i].t);
      }
    }
    farmers += d;
  }

  vector<event> ee2;
  farmers = 0;
  rep(i, 0, ee.size()-1){ // Assume that no pair of farmers get in and out at the same time!
    int d = ee[i].d;
    if( farmers+d == 0 ){
      event e(ee[i].t, -1);
      ee2.push_back(e);
    }
    if( farmers == 0 && farmers+d > 0 ){
      event e(ee[i].t, +1);
      ee2.push_back(e);
    }
    farmers += d;
  }

  int max_noidle = 0;
  rep(i, 0, ee2.size()-1){
    int d = ee2[i].d;
    if( d == 1 )
      if( i != ee2.size()-1)
	max_noidle = max(max_noidle, ee2[i+1].t-ee2[i].t);
  }

  output << max_noidle << " " << max_idle << endl;
  //cout << max_noidle << " " << max_idle << endl;
  
  return 0;
}

// AC
