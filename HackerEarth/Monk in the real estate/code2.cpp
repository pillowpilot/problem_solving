#include <iostream>
#include <set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  int t;
  cin >> t;
  while( t-- > 0 ){
    int m;
    cin >> m;

    set<int> s;
    while( m-- > 0 ){
      int x, y;
      cin >> x >> y;
      x--; y--;

      s.insert(x);
      s.insert(y);
    }

    cout << s.size() << endl;
  }
  
  return 0;
}

// AC
