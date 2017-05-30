#include <iostream>

#define rep(i, a, b) for(__typeof(a)i=a;i<=b;i++)

using namespace std;

int main(){
  cout << 601 << "\n";
  int c = 1;
  rep(m, 0, 400){
    rep(k, 1, m+1){
      cout << c << " " << m << " " << k << "\n";
      c++;
    }
  }
  return 0;
}
