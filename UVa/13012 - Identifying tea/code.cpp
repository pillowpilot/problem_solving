#include <iostream>

using namespace std;

int main(){
  int a, b, c, d, e, x, y;
  while( cin >> x >> a >> b >> c >> d >> e ){
    y = 0;
    if( x == a )y++;
    if( x == b )y++;
    if( x == c )y++;
    if( x == d )y++;
    if( x == e )y++;
    cout << y << endl;
  }
  return 0;
}

// AC

