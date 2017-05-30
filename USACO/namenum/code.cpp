/*
  ID: carlos.16
  PROG: namenum
  LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

#define rep(i, a, b) for(__typeof(a) i=a; i <= b; i++)

using namespace std;

set<string> acc;
vector<string> keyp;
string serial;

set<string> ans;
string name;
void bt(int p){
  if( p == serial.size() ){
    if( acc.find(name) != acc.end() )
      ans.insert(name);
  }else{
    int n = serial[p]-'0';
    rep(i, 0, keyp[n].size()-1){
      char c = keyp[n][i];
      name.push_back(c);
      bt(p+1);
      name.pop_back();
    }
  }
}

int main(){
  ifstream input("namenum.in");
  ofstream output("namenum.out");
  ifstream dict("dict.txt");

  {
    string line;
    while( dict >> line ){
      acc.insert(line);
    }
  }
  keyp.push_back(""); 
  keyp.push_back("");
  keyp.push_back("ABC"); 
  keyp.push_back("DEF");
  keyp.push_back("GHI"); 
  keyp.push_back("JKL");
  keyp.push_back("MNO"); 
  keyp.push_back("PRS");
  keyp.push_back("TUV"); 
  keyp.push_back("WXY");
  
  input >> serial;

  bt(0);

  if( ans.empty() ){
    //cout << "NONE" << endl;
    output << "NONE" << endl;
  }else{
    set<string>::iterator iter = ans.begin();
    while( ans.end() != iter ){
      //cout << *iter << endl;
      output << *iter << endl;
      iter++;
    }
  }
  
  return 0;
}

// AC

/*
  A faster approach would be the corresponding serial for every entry in dict.txt in O(1)
  comparing to the input. O(D) where D := #entries
 */
