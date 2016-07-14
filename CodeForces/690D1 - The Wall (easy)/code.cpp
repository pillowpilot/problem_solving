#include <iostream>
#include <string>

using namespace std;

int main(){
  int r, c;
  cin >> r >> c;

  string s;
  while( r-- > 1 )
    cin >> s;

  cin >> s;

  int cnt = 0;
  int i = 0;
  while( i < s.size() ){
    if( s[i] == 'B' ){
      cnt++;
      while( i < s.size() && s[i] == 'B' )
	i++;
    }else{
      while( i < s.size() && s[i] == '.' )
	i++;
    }
  }

  cout << cnt << endl;
  return 0;
}


// AC
