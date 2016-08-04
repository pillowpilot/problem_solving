#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int n, a, b, c;
  a = b = c = 0;

  cin >> n;
  while(n--){
    int x, y, z;
    cin >> x >> y >> z;
    a += x;
    b += y;
    c += z;
  }

  if( a == 0 && b == 0 && c == 0 )
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

// AC
