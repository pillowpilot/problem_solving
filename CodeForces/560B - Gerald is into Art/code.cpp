#include <iostream>
#include <limits>

using namespace std;

bool solve( int x, int y, int a, int b, int c, int d ){
  int alpha, beta;

  alpha = a + c;
  beta  = max( b, d );
  if( (alpha <= x && beta <= y) || (beta <= x && alpha <= y) ) return true;

  alpha = a + d;
  beta  = max( b, c );
  if( (alpha <= x && beta <= y) || (beta <= x && alpha <= y) ) return true;

  alpha = b + c;
  beta  = max( a, d );
  if( (alpha <= x && beta <= y) || (beta <= x && alpha <= y) ) return true;

  alpha = b + d;
  beta  = max( a, c );
  if( (alpha <= x && beta <= y) || (beta <= x && alpha <= y) ) return true;

  return false;
}

int main(){
  int a, b, c, d, x, y, alpha, beta;

  cin >> x >> y >> a >> b >> c >> d;

  if( solve( x, y, a, b, c, d ) ) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  return 0;
}

// AC
