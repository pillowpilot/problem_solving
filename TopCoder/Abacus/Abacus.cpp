#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<string> vs;

ostream& operator<<(ostream& os, const vs s){
  os << '{';
  if(s.size() != 0){
    vs::const_iterator iter = begin(s);
    os << *iter;
    iter++;
    while( iter != end(s) ){
      os << ", " << *iter;
      iter++;
    }
  }
  return os << '}';
}

class Abacus{
public:
  vs add(vs original, int val){
    int o = 0;
    for(string t: original){
      o *= 10;
      int i = 11 - (find(begin(t), end(t), '-') - begin(t) + 2);
      o += i;
    }

    o += val;
    o %= 1000000;

    vs ans;
    while( o != 0 ){
      int d = o % 10;
      o /= 10;
      string s;
      for(int i = 0; i < 12-d-3; i++)
	s.push_back('o');
      s += "---";
      while( s.size() != 12 )
	s.push_back('o');

      ans.push_back(s);
    }
    reverse(begin(ans), end(ans));
    return ans;
  }
};

int main(){
  Abacus a;
  cout << a.add({"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}, 5) << endl;
  
  return 0;
}

// AC
