/*
  ID: carlos.16
  PROG: gift1
  LANG: C++
*/
#include <fstream>
#include <string>
#include <map>
#include <vector>

#define rep(i, a, b) for(__typeof(a) i=a; i<=b; i++)

using namespace std;

int main(){
  ifstream input("gift1.in");
  ofstream output("gift1.out");

  int np;
  input >> np;

  map<string, int> ans;
  vector<string> order;
  rep(i, 1, np){
    string name;
    input >> name;
    order.push_back(name);
    ans[name] = 0;
  }
  rep(i, 1, np){
    string name;
    int ng;
    int money;
    input >> name >> money >> ng;
    if( money != 0 ) ans[name] += -money + (money - (money/ng)*ng);
    rep(j, 1, ng){
      string f;
      input >> f;
      ans[f] += money/ng;
    }
  }
  rep(i, 1, np){
    output << order[i-1] << " " << ans[order[i-1]] << endl;
  }
  
  return 0;
}

// AC
