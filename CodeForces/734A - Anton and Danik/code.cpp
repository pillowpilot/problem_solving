#include <iostream>
#include <string>

#define debug(x)       { cerr << #x << " = " << x << endl; }

using namespace std;

int main(){
  int n;
  string s;
  cin >> n >> s;
  int a, b;
  a = b = 0;
  
  for(char c: s)
    if( c == 'A' )
      a++;
    else
      b++;
  
  if( a == b )
    cout << "Friendship" << endl;
  else if( a > b )
    cout << "Anton" << endl;
  else
    cout << "Danik" << endl;
  
  return 0;
}

// AC
