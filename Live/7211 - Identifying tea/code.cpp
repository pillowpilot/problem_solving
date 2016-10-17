#include <iostream>

using namespace std;

int main(){
  int t, c;
  while( cin >> t ){
    int ans = 0;
    for(int i = 0; i < 5; i++){
      cin >> c;
      if( c == t )
	ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

// AC
