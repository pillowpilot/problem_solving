#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s, t;
  cin >> s >> t;

  int dif[2];

  if( s.size() != t.size() ){
    cout << "NO" << endl;
  }else{
    bool possible = true;
    int d = 0;
    int i = 0;
    while( i < s.size() && possible){
      if( s[i] != t[i] ){
	if( d < 2 ){
	  dif[d] = i;
	  d++;
	}else{
	  possible = false;
	}
      }
      i++;
    }
    if( !possible ){
      cout << "NO" << endl;
    }else{
      if( s[ dif[0] ] == t[ dif[1] ] &&
	  s[ dif[1] ] == t[ dif[0] ] )
	cout << "YES" << endl;
      else
	cout << "NO" << endl;
    }
    
  }
  
  return 0;
}

// AC
