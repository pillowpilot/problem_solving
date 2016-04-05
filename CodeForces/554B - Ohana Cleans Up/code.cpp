#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;

vs ss;

int solve(){
  vi c = vi(ss.size(), 0);

  for( int i = 0; i < ss.size(); i++ ){
    for( int j = 0; j < ss.size(); j++ ){
      if( ss[i].compare(ss[j]) == 0 ){
	c[i]++;
      }
    }
  }

  int m = c[0];
  for(int i: c){
    m = max(m, i);
  }

  return m;
}

int main(){
  int n;
  
  cin >> n;
  
  ss = vs();
  ss.reserve(n);

  while( n-- > 0 ){
    string s;
    cin >> s;
    ss.push_back(s);
  }

  cout << solve();
}
