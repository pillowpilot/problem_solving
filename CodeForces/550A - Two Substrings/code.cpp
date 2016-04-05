#include <iostream>
#include <string>

using namespace std;

bool solve(const string& s){
  bool f = false;
  //Look for AB...BA
  int i = 0;
  while( i < s.size() - 1 && !(s[i] == 'A' && s[i+1] == 'B') )i++;
  if( i < s.size() - 1 ){
    int j = i + 2;
    while( j < s.size() - 1 && !(s[j] == 'B' && s[j+1] == 'A') )j++;
    if( j < s.size() - 1 ) f = true;
  }
  if( f == true ) return true;
  //Look for BA..AB
  i = 0;
  while( i < s.size() - 1 && !(s[i] == 'B' && s[i+1] == 'A') )i++;
  if( i < s.size() - 1 ){
    int j = i + 2;
    while( j < s.size() - 1 && !(s[j] == 'A' && s[j+1] == 'B') )j++;
    if( j < s.size() - 1 ) f = true;
  }

  return f;
}

int main(){
  string s;

  cin >> s;

  if( solve(s) ) cout << "YES";
  else cout << "NO";
  return 0;
}
