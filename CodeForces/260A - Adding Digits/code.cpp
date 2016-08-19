#include <iostream>

using namespace std;

int main(){
  int a, b, n;

  cin >> a >> b >> n;

  bool possible = false;
  for(int d = 0; d < 10; d++){
    if( (a*10 + d)%b == 0 ){
      possible = true;
      a = 10*a + d;
      break;
    }
  }

  if( possible ){
    cout << a;
    while( n-- > 1 )
      cout << 0;
  }else{
    cout << -1;
  }

  cout << endl;
  
  return 0;
}

// AC
