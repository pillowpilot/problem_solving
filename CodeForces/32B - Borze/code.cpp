#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string s;
  cin >> s;

  int i = 0;
  while( i < s.size() ){
    if( s[i] == '.' ){
      cout << 0;
    }else{
      i++;
      if( s[i] == '.' )
	cout << 1;
      else
	cout << 2;
    }
    i++;
  }
  cout << endl;
  
  return 0;
}

// AC
