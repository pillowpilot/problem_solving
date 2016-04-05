#include <iostream>
#include <string>

using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  string s, t;

  while( cin >> s >> t ){
    int indexS = 0, indexT = 0;

    while( indexS < s.size() && indexT < t.size() ){
      if( s[indexS] == t[indexT] ) indexS++;
      indexT++;
    }

    if( indexS == s.size() ) cout << "Yes\n";
    else cout << "No\n";
    
  }

  cout << flush;
  
  return 0;
}

// AC
