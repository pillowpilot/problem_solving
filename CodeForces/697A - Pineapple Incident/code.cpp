#include <iostream>

using namespace std;

int main(){
  long long t, s, x;
  cin >> t >> s >> x;
  if( t == x)
    cout << "YES" << endl;
  
  else if( (x-t)%s == 0 && (x-t)/s >= 1 )
    cout << "YES" << endl;
  
  else if( (x-t-1)%s == 0 && (x-t-1)/s >= 1 )
    cout << "YES" << endl;
  
  else
    cout << "NO" << endl;
  
  return 0;
}
x
