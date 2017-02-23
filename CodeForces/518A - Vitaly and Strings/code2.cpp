#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
  string s, t;
  string nom = "No such string";
  cin >> s >> t;

  int i = s.size()-1;
  while( 0 <= i && s[i] == 'z' )
    i--;

  if( 0 <= i ){
    s[i] += 1; // next char
    for(int j = i+1; j < s.size(); j++)
      s[j] = 'a';
    if( s < t )
      cout << s << endl;
    else
      cout << nom << endl;
  }else{
    cout << nom << endl;
  }
  
  return 0;
}

// AC
