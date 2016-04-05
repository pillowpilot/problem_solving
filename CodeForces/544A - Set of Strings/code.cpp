#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;

vs ss;
vi is;

void solve(int k, const string& s){
  //Look for k different letters (start points of substrings)
  bitset<'z' - 'a' + 1> bs;
  is = vi();
  ss = vs();
  int i = 0;
  
  bs.reset();
  while( i < s.size() && is.size() < k ){
    if( !bs.test(s[i] - 'a') ){
      bs.set(s[i] - 'a');
      is.push_back(i);
    }
    i++;
  }
  is.push_back(s.size());
  
  
  if( is.size() == k + 1){ //If k starting points found
    for( i = 0; i < is.size() - 1; i++ ){
      int a = is[i], b = is[i+1];
      string t = "";
      while( a < b ){
	t += s[a++];
      }
      ss.push_back(t);
    }
  }
  
}

int main(){
  int k;
  string s;
  
  cin >> k >> s;

  solve(k, s);

  if( ss.size() != 0 ){
    cout << "YES" << endl;
    for( string s: ss ){
      cout << s << endl;
    }
  }else{
    cout << "NO" << endl;
  }

  return 0;
}
