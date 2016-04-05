#include <iostream>

using namespace std;

int main(){
  std::ios_base::sync_with_stdio(false);
  long long int s, d, x, y, n;

  cin >> n;
  while( n-- > 0 ){
    cin >> s >> d;
    x = s + d;
    y = s - d;
    if( d <= s && x % 2 == 0 && y % 2 == 0 && 0 <= x && 0 <= y){ // Need to check if divisible by 2.
      x /= 2;
      y /= 2;
      if( y < x ) swap(x, y);
      cout << y << ' ' << x << '\n';
    }else cout << "impossible\n";
  }
  cout << flush;
  
  return 0;
}

// AC (Finally.... -.-*...)
