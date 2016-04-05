#include <iostream>

using namespace std;

int main(){
  int a = 1, b = 2, sum = 0;
  while( b <= 4e6 ){
    if( b % 2 == 0 )
      sum += b;
    int t = b;
    b = a + b;
    a = t;
  }
  cout << sum << endl;
  return 0;
}

// AC
