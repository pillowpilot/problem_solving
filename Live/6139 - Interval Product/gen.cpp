#include <iostream>

using namespace std;

int main(){
  int n = 10000, k = 10000;
  cout << n << " " << k << endl;
  for(int i = 0; i < n; i++){
    cout << 100 << ' ';
  }

  cout << endl;
  while( k-- ){
    cout << "P " << 1 << " " << n << endl;
  }
  return 0;
}
