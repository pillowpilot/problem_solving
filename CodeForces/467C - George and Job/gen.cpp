#include <iostream>

using namespace std;

int main(){
  int n = 5000, m = 2, k = 2500;
  cout << n << ' ' << m << ' ' << k << endl;
  for(int i = 0; i < n; i++){
    cout << (int) 1e9 << ' ';
  }
  return 0;
}
