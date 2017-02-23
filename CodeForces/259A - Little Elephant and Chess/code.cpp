#include <iostream>
#include <string>

using namespace std;

int main(){
  int n = 8;
  while( n-- ){
    string s;
    cin >> s;
    if( s != "WBWBWBWB" && s != "BWBWBWBW" )
      break;
  }
  //cout << n << endl;
  if( n < 0 )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

// AC
