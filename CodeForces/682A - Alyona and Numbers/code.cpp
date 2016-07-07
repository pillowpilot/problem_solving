#include <iostream>

using namespace std;

typedef unsigned long long ull; // <--!

int main(){
  int n, m;

  cin >> n >> m;

  ull a[5] = {0}, b[5] = {0};
  
  for(int i = 1; i <= n; i++){
    a[ i % 5 ]++;
  }
  for(int i = 1; i <= m; i++){
    b[ i % 5 ]++;
  }

  ull s = 0;
  s += a[0]*b[0];
  s += a[1]*b[4];
  s += a[2]*b[3];
  s += a[3]*b[2];
  s += a[4]*b[1];

  cout << s << endl;
  
  return 0;
}

// AC
