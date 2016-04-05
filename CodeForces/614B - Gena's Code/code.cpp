#include <iostream>
#include <string>

using namespace std;

bool b(const string& s){
  if( s[0] != '1' ) return false;
  for(int i = 1; i < s.size(); i++){
    if( s[i] != '0' ) return false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  string nb;
  unsigned long long n, a = 0;
  cin >> n;
  while( n--> 0 ){
    string s;
    cin >> s;
    if( s == "0" ){
      cout << '0' << endl;
      return 0;
    }
    //cout << ">> " << s << endl;
    if( b(s) )
      a += s.size() - 1;
    else
      nb = s;
    //cout << ">> " << a << endl;
  }
  cout << nb;
  while( a-- > 0 )
    cout << '0';
  cout << endl;
  
  return 0;
}
