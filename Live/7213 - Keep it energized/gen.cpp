#include <iostream>

using namespace std;

int main(){
  int n = 100000, m = 100000;

  cout << n << ' ' << m << endl;
  for(int i = 0; i < n; i++){
    cout << 10000 << ' ';
  }
  cout << endl;

  for(int i = 0; i < m; i++){
    cout << i + 1 << ' ' << 10000 << ' ' << 10000 << endl;
  }
    
  return 0;
}
