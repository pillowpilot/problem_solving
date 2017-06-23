#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

const int seed = 2080;

void check(int a, int x, int y){
  if( y < a || a < x ){
    cout << a << endl;
    assert(x<=a&&a<=y);
  }
}

int randx(){
  int a = rand() % (int)1e3;
  int b = rand() % (int)1e3;
  return a*b;
}

int randx2(){
  int a = randx();
  return (rand()%2)?-a:a;
}

int main(){
  int n = 2e5;
  check(n, 1, 2e5);
  cout << n << endl;
  for(int i = 0; i < n; i++){
    int a = randx2();
    check(a, -1e6, 1e6);
    cout << a << " ";
  }
  int m = 1e5;
  check(m, 1, 2e5);
  cout << m << endl;
  for(int i = 0; i < m; i++){
    int a = (int)(rand()%n);
    int b = (int)(rand()%n);
    check(a, 0, n-1);
    check(b, 0, n-1);
    cout << a << " " << b;
    if( rand()%2 == 0 ){
      int v = randx2();
      check(v, -1e6, 1e6);
      cout << " " << v;
    }
    cout << endl;
  }
}
