#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<char> vc;

int main(){
  string s;
  vc r;
  
  cin >> s;

  r.push_back(s[0]); // |s| >= 1
  for(int i = 1; i < s.size(); i++){
    r.push_back(s[i]);
    if( r[ r.size() - 1 ] == r[ r.size() - 2 ] ){
      r.pop_back();
      r.pop_back();
    }
  }

  for(char c: r) cout << c;
  cout << endl;
  
  return 0;
}

// AC
